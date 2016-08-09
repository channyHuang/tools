#include "pcltest.h"

pclTest::pclTest(QWidget *parent)
	: QWidget(parent), ui(new Ui::pclTest)
{
	ui->setupUi(this);

	initwidgets();

	QVBoxLayout *slidelayout = new QVBoxLayout();
	slidelayout->addWidget(horizontalSlider_R);
	slidelayout->addWidget(horizontalSlider_G);
	slidelayout->addWidget(horizontalSlider_B);
	slidelayout->addWidget(horizontalSlider_p);
	slidelayout->addWidget(pushButton_random);
	QHBoxLayout *mainlayout = new QHBoxLayout();
	mainlayout->addLayout(slidelayout);
	mainlayout->addWidget(qvtkWidget);
	setLayout(mainlayout);

	// Setup the cloud pointer
	cloud.reset(new PointCloudT);
	// The number of points in the cloud
	cloud->points.resize(200);
	// The default color
	red = 128;
	green = 128;
	blue = 128;

	// Fill the cloud with some points
	for (size_t i = 0; i < cloud->points.size(); ++i)
	{
		cloud->points[i].x = 1024 * rand() / (RAND_MAX + 1.0f);
		cloud->points[i].y = 1024 * rand() / (RAND_MAX + 1.0f);
		cloud->points[i].z = 1024 * rand() / (RAND_MAX + 1.0f);

		cloud->points[i].r = red;
		cloud->points[i].g = green;
		cloud->points[i].b = blue;
	}
	
	// Set up the QVTK window
	viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
/*	qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
	viewer->setupInteractor(qvtkWidget->GetInteractor(), qvtkWidget->GetRenderWindow());
	qvtkWidget->update();
	*/
	// Connect "random" button and the function
	connect(pushButton_random, SIGNAL(clicked()), this, SLOT(randomButtonPressed()));

	// Connect R,G,B sliders and their functions
	connect(horizontalSlider_R, SIGNAL(valueChanged(int)), this, SLOT(redSliderValueChanged(int)));
	connect(horizontalSlider_G, SIGNAL(valueChanged(int)), this, SLOT(greenSliderValueChanged(int)));
	connect(horizontalSlider_B, SIGNAL(valueChanged(int)), this, SLOT(blueSliderValueChanged(int)));
	connect(horizontalSlider_R, SIGNAL(sliderReleased()), this, SLOT(RGBsliderReleased()));
	connect(horizontalSlider_G, SIGNAL(sliderReleased()), this, SLOT(RGBsliderReleased()));
	connect(horizontalSlider_B, SIGNAL(sliderReleased()), this, SLOT(RGBsliderReleased()));

	// Connect point size slider
	connect(horizontalSlider_p, SIGNAL(valueChanged(int)), this, SLOT(pSliderValueChanged(int)));
	viewer->addPointCloud(cloud, "cloud");
	pSliderValueChanged(2);
	viewer->resetCamera();
	qvtkWidget->update();
	
}

pclTest::~pclTest()
{
	delete ui;
}

void pclTest::initwidgets() {
	horizontalSlider_B = new QSlider();
	horizontalSlider_B->setOrientation(Qt::Horizontal);
	horizontalSlider_G = new QSlider();
	horizontalSlider_G->setOrientation(Qt::Horizontal);
	horizontalSlider_R = new QSlider();
	horizontalSlider_R->setOrientation(Qt::Horizontal);
	horizontalSlider_p = new QSlider();
	horizontalSlider_p->setOrientation(Qt::Horizontal);

	pushButton_random = new QPushButton("");

	qvtkWidget = new QVTKWidget(this);
}

void pclTest::randomButtonPressed() {
	printf("Random button was pressed\n");

	// Set the new color
	for (size_t i = 0; i < cloud->size(); i++)
	{
		cloud->points[i].r = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
		cloud->points[i].g = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
		cloud->points[i].b = 255 * (1024 * rand() / (RAND_MAX + 1.0f));
	}

	viewer->updatePointCloud(cloud, "cloud");
	qvtkWidget->update();
}



void pclTest::RGBsliderReleased() {
	// Set the new color
	for (size_t i = 0; i < cloud->size(); i++)
	{
		cloud->points[i].r = red;
		cloud->points[i].g = green;
		cloud->points[i].b = blue;
	}
	viewer->updatePointCloud(cloud, "cloud");
	qvtkWidget->update();
}

void
pclTest::redSliderValueChanged(int value)
{
	red = value;
	printf("redSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void
pclTest::greenSliderValueChanged(int value)
{
	green = value;
	printf("greenSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void
pclTest::blueSliderValueChanged(int value)
{
	blue = value;
	printf("blueSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void pclTest::pSliderValueChanged(int value) {

}