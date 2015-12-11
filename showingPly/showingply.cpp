#include "showingply.h"

#include <QHBoxLayout>
#include <QVBoxLayout>


#include <windows.h>
#include <assert.h>

#define Pi 3.1415926
#undef max
#undef min

#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/console/time.h>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/PolygonMesh.h>
#include <pcl/common/io.h>
#include <pcl/io/io.h>

#include <pcl/features/normal_3d.h>
#include <pcl/features/normal_3d_omp.h>

#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/keyboard_event.h>

#include <boost/lexical_cast.hpp>



#include <iostream>
using namespace std;

using namespace pcl;
using namespace pcl::io;
using namespace pcl::console;


bool
loadCloud(const std::string &filename, pcl::PointCloud<pcl::PointXYZRGB> cloud)
{
	TicToc tt;
	print_highlight("Loading "); print_value("%s ", filename.c_str());

	pcl::PLYReader reader;
	tt.tic();
	if (reader.read(filename, cloud) < 0)
		return (false);
	print_info("[done, "); print_value("%g", tt.toc()); print_info(" ms : "); print_value("%d", cloud.width * cloud.height); print_info(" points]\n");
	print_info("Available dimensions: "); print_value("%s\n", pcl::getFieldsList(cloud).c_str());

	return (true);
}

void
saveCloud(const std::string &filename, const pcl::PointCloud<pcl::PointXYZRGB> &cloud, bool format)
{
	TicToc tt;
	tt.tic();

	print_highlight("Saving "); print_value("%s ", filename.c_str());

	pcl::PCDWriter writer;
	writer.write(filename, cloud, format);

	//print_info("[done, "); print_value("%g", tt.toc()); print_info(" ms : "); print_value("%d", cloud.width * cloud.height); print_info(" points]\n");
}

showingPly::showingPly(QWidget *parent)
	:ui(new Ui::showingPly), QWidget(parent)
{
	ui->setupUi(this);

	initwidgets();
	initconnects();

	QVBoxLayout *plylayout = new QVBoxLayout();
	plylayout->addWidget(plyNameEdit);
	plylayout->addWidget(selectbtn);
	plylayout->addWidget(showPlybtn);

	setLayout(plylayout);
}

showingPly::~showingPly()
{
	delete ui;
}

void showingPly::initwidgets()
{
	selectbtn = new QPushButton("Select");
	showPlybtn = new QPushButton("Show");
	plyNameEdit = new QLineEdit();
}

void showingPly::initconnects()
{
	connect(selectbtn, SIGNAL(clicked()), this, SLOT(select()));
	connect(showPlybtn, SIGNAL(clicked()), this, SLOT(showCloud()));
}

void showingPly::select()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("file"), "", tr("ALL files(*.*);;PLY(*.ply);;OBJ(*.obj)"));
	if (filename.isEmpty()) {
		QMessageBox::warning(NULL, "warning;", "No such directory!");
		return;
	}
	plyNameEdit->setText(filename);

	plyFileName = filename.toStdString();         
}

void showingPly::showCloud()
{
	pcl::PLYReader reader;

	cout << plyFileName << endl;

	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);

	int lenPly = plyFileName.length();
	if (plyFileName[lenPly - 1] == 'j') {
		cout << "Read obj file..." << endl;
		pcl::PolygonMesh mesh;
		pcl::io::load(plyFileName, mesh);
		//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
		pcl::fromPCLPointCloud2(mesh.cloud, *cloud);
	}
	else {
		cout << "Read ply file..." << endl;
		ifstream in(plyFileName);
		char *buf = new char[100];
		double tmpx, tmpy, tmpz;

		for (int i = 0; i < 10; i++) {
			in.getline(buf, 100);
		}
		while (!in.eof()) {
			pcl::PointXYZRGB point;
			in >> point.x >> point.y >> point.z >> point.r >> point.g >> point.b;
			cloud->push_back(point);
		}
	}

	cout << "Point cloud number: " << cloud->size() << endl;

	//visualization
	pcl::visualization::PCLVisualizer cviewer("PCL PointClound");
	cviewer.setBackgroundColor(1, 0, 0);
	cviewer.addPointCloud(cloud);
	while (!cviewer.wasStopped()) {
		cviewer.spinOnce();
		boost::this_thread::sleep(boost::posix_time::microseconds(100));
	}

}