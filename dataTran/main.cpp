#include <iostream>
#include <fstream>
#include <string>

#include <QtCore/QDir>
#include <QtCore/QFileInfo>
#include <QtCore/QFileInfoList>

#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/video.hpp>

#include <Eigen/Eigen>

int main() {
	//save frames
#if 1
	std::string DATA_PATH = "F:/data1206/";
	std::string videoname = "F:/data1206/VID_20120105_122533.mp4";
	cv::VideoCapture capture;
	capture.open(videoname);
	if (!capture.isOpened()) {
		std::cout << "Could not open video" << videoname << "with opencv..." << std::endl;
		return false;
	}
	cv::Mat frame;
	int no = 0;
	int i = 0;
	for (;;) {
		capture >> frame;
		if (frame.empty())
			break;
		if (no % 5 == 0) {
			//	image.push_back(frame.clone());

			QString picname = QString(DATA_PATH.c_str()) + "visualize/" + QString("%1").arg(i, 8, 10, QChar('0')) + ".jpg";
			cv::imwrite(picname.toStdString(), frame);
			i++;
		}
		no++;
	}
#endif

	//save params to pmvs format
#if 0
	std::string DATA_PATH = "F:/data1201/scenedir/views/";
	QDir imgdir(DATA_PATH.c_str());
	imgdir.setFilter(QDir::Dirs);
	QFileInfoList list = imgdir.entryInfoList();

	std::vector<Eigen::Matrix3d> R;
	std::vector<Eigen::Vector3d> t;
	std::vector<Eigen::Matrix3Xd> P;

	Eigen::Matrix3d K;
	K << 1389, 0, 960, 0, 1389, 540, 0, 0, 1;

	int i = 0;
	for each (QFileInfo fileinfo in list)	{
		if (fileinfo.fileName() == "." || fileinfo.fileName() == "..") {
			continue;
		}
		P.push_back(Eigen::Matrix3Xd(3, 4));
		R.push_back(Eigen::Matrix3d());
		t.push_back(Eigen::Vector3d());

		std::string str;
		std::ifstream ifs(fileinfo.absoluteFilePath().toStdString() + "/meta.ini");

		for (int tmp = 0; tmp < 8; tmp++) {
			getline(ifs, str);
		}
		sscanf(str.c_str(), "%*s %*s %lf %lf %lf %lf %lf %lf %lf %lf %lf", &R.at(i)(0, 0), &R.at(i)(0, 1), &R.at(i)(0, 2), &R.at(i)(1, 0), &R.at(i)(1, 1), &R.at(i)(1, 2), &R.at(i)(2, 0), &R.at(i)(2, 1), &R.at(i)(2, 2));

		getline(ifs, str);
		sscanf(str.c_str(), "%*s %*s %lf %lf %lf", &t.at(i)(0), &t.at(i)(1), &t.at(i)(2));

		P.at(i).col(0) = R.at(i).col(0);
		P.at(i).col(1) = R.at(i).col(1);
		P.at(i).col(2) = R.at(i).col(2);
		P.at(i).col(3) = t.at(i);
		P.at(i) = K*P.at(i);
	
		DATA_PATH = "F:/data1201/";
		QString outputParamName = QString(DATA_PATH.c_str()) + "txt/" + QString("%1").arg(i, 8, 10, QChar('0')) + ".txt";
		std::ofstream ofs(outputParamName.toStdString());
		ofs << "CONTOUR" << std::endl;
		ofs << P.at(i);
		ofs.close();
		ifs.close();
		i++;
	}

	
#endif

	return 0;
}