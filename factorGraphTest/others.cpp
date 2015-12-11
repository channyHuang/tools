#include "others.h"

#include "engine.h"
#pragma  comment(lib, "libeng.lib")
#pragma  comment(lib, "libmx.lib")
#pragma  comment(lib, "libmat.lib")

#include <gtsam/geometry/Pose3.h>
#include <gtsam/geometry/Point2.h>
using namespace gtsam;

#include <boost/property_tree/xml_parser.hpp>
#include <boost/math/quaternion.hpp>

#include <vector>
#include <iostream>
using namespace std;

struct xmlAcc {
	
	int index;
	double time;
};

int readSensorData()
{
	vector<Pose3> poses;
	vector<Point3> points;

	//read xml file
	string filename = "F:/";
	boost::property_tree::ptree pt;
	boost::property_tree::ptree root;
	try {
		read_xml(filename, pt);
		root = pt.get_child("name");
	}
	catch (std::exception& e) {
		return -1;
	}
}

void silhouetteToModel()
{
	Engine *ep;
	if (!(ep = engOpen("\0"))) {
		cout << "Could not open the matlab engine..." << endl;
		exit(0);
	}

	//compute the model using matlab
	if (true) {
		engEvalString(ep, "clear all");

		double *ver;
		mxArray *result = NULL;
		//change to the file path
		engEvalString(ep, "cd ../"); 
		engEvalString(ep, "VisualHullMain");

		//read verts data from matlab into c
		result = mxCreateDoubleMatrix(50000, 1, mxREAL);
		result = engGetVariable(ep, "verts");
		ver = mxGetPr(result);

		mxDestroyArray(result);

		engEvalString(ep, "close;");
		engClose(ep);
	}

	cout << "Silhouette to Model Path have Finished..." << endl;
}

void refineModel(string roughModelName, string desModelName)
{
	//refine the destination using ICP or other algorithm

}

void refineSilhouette()
{
	//refine two silhouettes using ICP or other algorithm

}