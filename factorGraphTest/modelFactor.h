#ifndef MODELFACTOR_H
#define MODELFACTOR_H

#include <gtsam/nonlinear/NonlinearFactor.h>
#include <gtsam/base/Vector.h>
#include <gtsam/base/Value.h>
#include <gtsam/geometry/Pose3.h>

using namespace gtsam;

#include <iostream>
#include <vector>
using namespace std;

class Model : public DerivedValue<Point3> {
private:
	vector<Point3> points;

public:
	virtual size_t dim() const {
		return points.size();
	}
	 
	void print(const string & str = "") const {};

	Vector localCoordinates(const vector<Point3> &pts) const {
		Eigen::Matrix<double, 6, 1> result;
		for (int i = 0; i < 6; i++) {
			result(i, 0) = i;
		}

		return result;
	}
};

class ModelFactor : public NoiseModelFactor1<Pose3> {
private:
	Pose3 q;

public:
	virtual ~ModelFactor() {}

	ModelFactor(Key i, Pose3 &p, const SharedNoiseModel & model) :NoiseModelFactor1<Pose3 >(model, i), q(p) {}

	Vector	evaluateError(const Pose3 &pts, boost::optional<Matrix&> H = boost::none) const
	{
		Matrix Ha, Hb;

		Eigen::Matrix<double, 6, 1> result;
		for (int i = 0; i < 6; i++) {
			result(i, 0) = i;
		}

		return result;
	}
};


#endif