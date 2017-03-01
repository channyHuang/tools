#include <iostream>
#include <vector>
using namespace std;

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;

vector< Point2f> corner;
int no = 0;
cv::Mat img0;

void on_mouse(int event, int x, int y, int flags, void* param) {
	Mat img = img0.clone();

	char coordinate[16];
	if (event == cv::EVENT_LBUTTONDOWN) {
		corner.push_back(Point2f(x, y));
		circle(img, Point2f(x, y), 2, Scalar(255, 0, 0), CV_FILLED, CV_AA, 0);
		imshow("frames", img);
		if (corner.size() >= 4) {
			destroyWindow("frames");
		}
	}
	else if (event == cv::EVENT_MOUSEMOVE){
		sprintf(coordinate, "(%d, %d)", x, y);
		putText(img, coordinate, Point2f(x, y), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1, 8);
		imshow("frames", img);
	}
}

void getCorners()
{
	
		namedWindow("frames");
		setMouseCallback("frames", on_mouse, 0);
		imshow("frames", img0);
		waitKey(0);
}

int main() {
	std::string filename = "E:/ArtShoe2_reconstruction/code/data/f004_dc_left/data/pic/0002.jpg";

	cv::Mat img = cv::imread(filename, 1), roimg;
	cv::resize(img, img0, cv::Size(1024, 768));

	if (img0.empty())
	{
		std::cout << "Couldn'g open image " << filename << ". Usage: watershed <image_name>/n";
		return 0;
	}

	namedWindow("frames");
	getCorners();
	vector<Point2d> target;
	target.push_back(Point2d(0, 210));
	target.push_back(Point2d(297, 210));
	target.push_back(Point2d(297, 0));
	target.push_back(Point2d(0, 0));


	Point2f targets[4], corners[4];
	for (int i = 0; i < 4; i++) {
		targets[i] = target.at(i);
		corners[i] = corner.at(i);
	}
	//cv::Mat H = getAffineTransform(corners, target);
	cv::Mat H = getPerspectiveTransform(corners, targets);

	warpPerspective(img0, roimg, H, cv::Size(297, 210));

	namedWindow("frames");
	imshow("frames", roimg);
	waitKey(1000);

	imwrite("frames.jpg", roimg);

	return 0;
}


