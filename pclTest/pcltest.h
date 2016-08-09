#ifndef PCLTEST_H
#define PCLTEST_H


#include <iostream>

#include <QtWidgets/QWidget>
#include "ui_pcltest.h"
#include <QPushButton>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>


#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

#include <QVTKWidget.h>

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

namespace Ui {
	class pclTest;
}

class pclTest : public QWidget
{
	Q_OBJECT

public:
	pclTest(QWidget *parent = 0);
	~pclTest();

	public slots:
	void
		randomButtonPressed();

	void
		RGBsliderReleased();
	
	void
		pSliderValueChanged(int value);

	void
		redSliderValueChanged(int value);

	void
		greenSliderValueChanged(int value);

	void
		blueSliderValueChanged(int value);
		
protected:
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
	PointCloudT::Ptr cloud;

	unsigned int red;
	unsigned int green;
	unsigned int blue;

private:
	Ui::pclTest *ui;

	QPushButton *pushButton_random;
	QVTKWidget *qvtkWidget;
	QSlider *horizontalSlider_R, *horizontalSlider_G, *horizontalSlider_B, *horizontalSlider_p;

	void initwidgets();
	
};

#endif // PCLTEST_H
