#ifndef GETPOINTS_H
#define GETPOINTS_H

#include <QtWidgets/QWidget>
#include "ui_getpoints.h"

#include <QPushButton>
#include <QLineEdit>

#include <opencv2/core/core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\features2d\features2d.hpp>
#include <opencv2\nonfree\features2d.hpp>
#include<opencv2/legacy/legacy.hpp>

#include "data.h"

namespace Ui
{
	class getpoints;
}

class getpoints : public QWidget
{
	Q_OBJECT

public:
	getpoints(QWidget *parent = 0);
	~getpoints();

//	void on_mouse( int event, int x, int y, int flags, void* param );
	cv::Mat contreps(cv::Mat_<float> X,cv::Mat_<float> F);

private slots:
	void showimg();
	bool choose1();
	bool choose2();
	void calculate();

	void draw();

private:
	Ui::getpoints *ui;

	QPushButton *showimgbtn,*exitbtn;
	QLineEdit *imgname1,*imgname2;
	QPushButton *chooseimg1,*chooseimg2;
	QPushButton *calculatebtn;

	std::vector<cv::Point2f> point1,point2;

	QPushButton *drawptbtn;
	int add_remove_pt;
};

#endif // GETPOINTS_H
