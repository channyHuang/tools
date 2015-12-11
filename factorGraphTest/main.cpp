
#include <gtsam/nonlinear/NonlinearFactor.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/nonlinear/DoglegOptimizer.h>
#include <gtsam/nonlinear/LevenbergMarquardtOptimizer.h>

#include <gtsam/inference/Symbol.h>
#include <gtsam/geometry/Pose3.h>
#include <gtsam/geometry/Point2.h>

#include <gtsam/slam/PriorFactor.h>
#include <gtsam/slam/ProjectionFactor.h>
#include <gtsam/slam/GeneralSFMFactor.h>
#include <gtsam/slam/dataset.h>
#include <gtsam/slam/BetweenFactor.h>
#include <gtsam/slam/BearingRangeFactor.h>
#include <gtsam/slam/BearingFactor.h>

#include <gtsam/nonlinear/Values.h>
#include <gtsam/base/Vector.h>

#include <gtsam/navigation/ImuBias.h>
#include <gtsam/navigation/ImuFactor.h>
#include <gtsam/navigation/CombinedImuFactor.h>
using namespace gtsam;
using symbol_shorthand::C;
using symbol_shorthand::P;

#include <iostream>
#include <vector>
using namespace std;

#include "SFMdata.h"
#include "SilhouetteFactor.h"
#include "myFactor.h"

int main()
{
	//reading data
	Cal3_S2::shared_ptr K(new Cal3_S2(50.0, 50.0, 0.0, 50.0, 50.0));
	vector<Pose3> poses = createPoses();
	vector<Point3> points = createPoints();

	//create graph
	NonlinearFactorGraph graph;

	imuBias::ConstantBias currentBiasGlobal((Vector(3) << 3, 0, 0), (Vector(3) << 2, 0, 0));

	//Gaussian prior on pose and on bias
	if (true)
	{
		noiseModel::Diagonal::shared_ptr priorPoseNoise = noiseModel::Diagonal::Sigmas((Vector(6) << Vector3::Constant(0.3), Vector3::Constant(0.1)));
		graph.push_back(PriorFactor<Pose3>(Symbol('x', 0), poses[0], priorPoseNoise));

		graph.add(PriorFactor<imuBias::ConstantBias>(Symbol('b', 0), currentBiasGlobal, priorPoseNoise));
	}

	//IMU and close
	if (true) {
		Pose3 odometry(Rot3(points[0], points[0], points[0]), points[2]);

		noiseModel::Diagonal::shared_ptr odometryNoise = noiseModel::Diagonal::Sigmas((Vector(6) << Vector3::Constant(0.3), Vector3::Constant(0.1)));
		for (int i = 0; i < poses.size() - 1; i++) {
			graph.add(BetweenFactor<Pose3>(Symbol('x', i), Symbol('x', i + 1), poses[i], odometryNoise));
		}

		graph.add(BetweenFactor<Pose3>(Symbol('x', poses.size() - 1), Symbol('x', 0), poses[poses.size() - 1], odometryNoise));
	}

	//project
	if (true)
	{
		noiseModel::Isotropic::shared_ptr pointNoise = noiseModel::Isotropic::Sigma(2, 1.0);

		for (int j = 0; j < points.size(); j++) {
			for (int i = 0; i < poses.size(); i++) {
				SimpleCamera camera(poses[i], *K);
				Point2 measurement = camera.project(points[j]);

				graph.push_back(GenericProjectionFactor<Pose3, Point3, Cal3_S2>(measurement, pointNoise, Symbol('x', i), Symbol('l', j), K));
			}

		}
	}

	//bias
	if (true)
	{
		noiseModel::Diagonal::shared_ptr biasNoise = noiseModel::Diagonal::Sigmas((Vector(6) << Vector3::Constant(0.3), Vector3::Constant(0.1)));
		for (int i = 0; i < poses.size() - 1; i++) {
			graph.add(BetweenFactor<imuBias::ConstantBias>(Symbol('b', i), Symbol('b', i+1), imuBias::ConstantBias(zeros(3, 1),zeros(3, 1)), biasNoise));
		}
	}

	//self define errors
	noiseModel::Diagonal::shared_ptr myNoise = noiseModel::Diagonal::Sigmas((Vector(6) << Vector3::Constant(0.3), Vector3::Constant(0.1)));
	graph.add(MyFactor(Symbol('x', 1), poses[1], myNoise));
	
	
	//visual hull model
	if (false) {
		for (int i = 0; i < poses.size(); i++) {
			Silhouette silpts;
			graph.add(SilhouetteFactor(Symbol('s', 2), silpts, myNoise));
		}
	}
	

	//show graph
	//graph.print("Factor Graph:\n");
	
	//initialize
	Values initialEstimate;
	for (size_t i = 0; i < poses.size(); ++i) {
		initialEstimate.insert(Symbol('x', i), poses[i].compose(Pose3(Rot3::rodriguez(-0.1, 0.2, 0.25), Point3(0.05, -0.10, 0.20))));
		initialEstimate.insert(Symbol('b', i), currentBiasGlobal);

		Silhouette silpt;
		initialEstimate.insert(Symbol('s', i), silpt);
	}
	for (size_t j = 0; j < points.size(); ++j)
		initialEstimate.insert(Symbol('l', j), points[j].compose(Point3(-0.25, 0.20, 0.15)));
	initialEstimate.print("Initial Estimation:");

	//optimize
	Values result = DoglegOptimizer(graph, initialEstimate).optimize();
	result.print("Final results:\n");

//	LevenbergMarquardtOptimizer optimizer = LevenbergMarquardtOptimizer(graph, initialEstimate);
//	Values result = optimizer.optimize();

	cout << "End..." << endl;

	return 0;
}