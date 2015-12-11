#ifndef MYFACTOR_H
#define MYFACTOR_H

#include <gtsam/nonlinear/NonlinearFactor.h>
#include <gtsam/geometry/Pose3.h>
#include <gtsam/geometry/Point2.h>

#include <iostream>

using namespace gtsam;
using namespace std;

class MyFactor : public NoiseModelFactor1<Pose3> {
private:
	Pose3 p;

public:
	MyFactor(Key i, Pose3 q, const SharedNoiseModel & model) : NoiseModelFactor1<Pose3>(model, i), p(q) {}
	
	Vector evaluateError(const Pose3 &q, boost::optional<Matrix&> H = boost::none) const
	{
		Matrix Ha, Hb;
		Pose3 tmpp = q.inverse(Hb);
		if (H) *H = Hb;
	
		return p.localCoordinates(tmpp)*2;
		
		Eigen::Matrix<double, 6, 1> result;
		for (int i = 0; i < 6; i++) {
			result(i, 0) = i;
		}

		return result;
	}
	
	/*
	Vector evaluateError(const Pose3 &q) const
	{
		Matrix Hb;
		return p.localCoordinates(q.inverse(Hb));
	}
	*/
	virtual gtsam::NonlinearFactor::shared_ptr clone() const {
		return boost::static_pointer_cast<gtsam::NonlinearFactor>(
			gtsam::NonlinearFactor::shared_ptr(new MyFactor(*this)));
	}

	virtual void print(const std::string& s, const KeyFormatter& KeyFormatter = DefaultKeyFormatter) const {
		cout << s << "Here are some information.";
	}
};


#endif