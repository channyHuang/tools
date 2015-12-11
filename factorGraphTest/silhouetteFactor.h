#ifndef SILHOUETTEFACTOR_H
#define SILHOUETTEFACTOR_H

#include <gtsam/nonlinear/NonlinearFactor.h>
#include <gtsam/base/Vector.h>
#include <gtsam/base/Value.h>
#include <gtsam/geometry/Pose3.h>

using namespace gtsam;

#include <iostream>
#include <vector>
using namespace std;

class Silhouette : public DerivedValue<Point3> {
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

class SilhouetteFactor : public NoiseModelFactor1<Silhouette > {
private:
	Silhouette sil;

public:

	SilhouetteFactor(Key i, Silhouette pts, const SharedNoiseModel & model) : NoiseModelFactor1<Silhouette >(model, i), sil(pts) {}

	Vector	evaluateError(const Silhouette &pts, boost::optional<Matrix&> H = boost::none) const
	{
		Matrix Ha, Hb;

		Eigen::Matrix<double, 6, 1> result;
		for (int i = 0; i < 6; i++) {
			result(i, 0) = i;
		}

		return result;
	}
};


//refine 2 silhouettes base on model projection
class SilhouetteFactor2 : public NoiseModelFactor2<Silhouette, Silhouette > {

private:
	Silhouette measured_;

public:
	typedef boost::shared_ptr<SilhouetteFactor> shared_ptr;

	SilhouetteFactor2(Key j, Key k, const Silhouette& measured, const SharedNoiseModel& model) :
		NoiseModelFactor2<Silhouette, Silhouette  >(model, j, k), measured_(measured) {}

	virtual ~SilhouetteFactor2() {}

	Vector evaluateError(const Silhouette &pIC, const Silhouette &pIB,
		boost::optional<Matrix&> H1 = boost::none,
		boost::optional<Matrix&> H2 = boost::none) const
	{
		Matrix Ha, Hb, Hc;

		if (H1) *H1 = Hb;
		if (H2) *H2 = Hc;

		cout << '\n' << Ha << '\n' << Hb << '\n' << Hc << '\n';

		Eigen::Matrix<double, 6, 1> result;
		for (int i = 0; i < 6; i++) {
			result(i, 0) = i;
		}

		return result;
	}

	virtual gtsam::NonlinearFactor::shared_ptr clone() const {
		return boost::static_pointer_cast<gtsam::NonlinearFactor>(
			gtsam::NonlinearFactor::shared_ptr(new SilhouetteFactor2(*this)));
	}

	virtual void print(const std::string& s, const KeyFormatter& keyFormatter = DefaultKeyFormatter) const {
		std::cout << s << "Niko factor on \n";
		measured_.print("measured: ");
	}


};

#endif