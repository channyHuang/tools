#include "getpoints.h"

#include <QFileDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

#include <fstream>

getpoints::getpoints(QWidget *parent)
	:ui(new Ui::getpoints), QWidget(parent)
{
	add_remove_pt = 0;
	ui->setupUi(this);

	showimgbtn = new QPushButton("show img");
	exitbtn = new QPushButton("exit");

	imgname1=new QLineEdit();
	imgname2=new QLineEdit();

	chooseimg1=new QPushButton("choose img1");
	chooseimg2=new QPushButton("choose img2");

	calculatebtn = new QPushButton("calculate");

	connect(chooseimg1,SIGNAL(clicked()),this,SLOT(choose1()));
	connect(chooseimg2,SIGNAL(clicked()),this,SLOT(choose2()));
	connect(showimgbtn,SIGNAL(clicked()),this,SLOT(showimg()));
	connect(exitbtn,SIGNAL(clicked()),this,SLOT(close()));

	connect(calculatebtn,SIGNAL(clicked()),this,SLOT(calculate()));

	drawptbtn = new QPushButton("draw point");
	connect(drawptbtn,SIGNAL(clicked()),this,SLOT(draw()));

	QHBoxLayout *btn1layout=new QHBoxLayout();
	QHBoxLayout *btn2layout=new QHBoxLayout();
	btn1layout->addWidget(imgname1);
	btn1layout->addWidget(chooseimg1);
	btn2layout->addWidget(imgname2);
	btn2layout->addWidget(chooseimg2);
	QVBoxLayout *mainlayout=new QVBoxLayout();
	mainlayout->addLayout(btn1layout);
	mainlayout->addLayout(btn2layout);
	mainlayout->addWidget(showimgbtn);
	mainlayout->addWidget(calculatebtn);
	mainlayout->addWidget(drawptbtn);
	mainlayout->addWidget(exitbtn);
	setLayout(mainlayout);
}

getpoints::~getpoints()
{
	delete ui;
}

bool getpoints::choose1()
{
	if(imgname1->text()!=NULL) {
		name1=imgname1->text();
		return true;
	}
	name1=QFileDialog::getOpenFileName(this,tr("image1"),"",tr("ALL files(*.*);;JPG(*.jpg);;BMP(*.bmp);;PNG(*.png)"));
	if(name1.isEmpty()) {
		QMessageBox::warning(NULL,"error!","No such file or directory!");
		return false;
	}
	imgname1->setText(name1);
	return true;
}

bool getpoints::choose2()
{
	if(imgname2->text()!=NULL) {
		name2=imgname2->text();
		return true;
	}
	name2=QFileDialog::getOpenFileName(this,tr("image2"),"",tr("ALL files(*.*);;JPG(*.jpg);;BMP(*.bmp);;PNG(*.png)"));
	if(name2.isEmpty()) {
		QMessageBox::warning(NULL,"error!","No such file or directory!");
		return false;
	}
	imgname2->setText(name2);
	return true;
}

void getpoints::showimg()
{
	cv::Mat originimg=cv::imread(name1.toStdString());
	cv::Mat referimg=cv::imread(name2.toStdString());
	if(originimg.empty()||referimg.empty()) {
		QMessageBox::warning(NULL,QStringLiteral("读取图像失败"),QStringLiteral("找不到图像，请确认路径是否正确！"));
		return ;
	}

	cv::SiftFeatureDetector detector;
	std::vector<cv::KeyPoint> keypoints1,keypoints2;
	detector.detect(originimg,keypoints1);
	detector.detect(referimg,keypoints2);

	cv::SiftDescriptorExtractor extractor;
	cv::Mat descriptor1,descriptor2;
	extractor.compute(originimg,keypoints1,descriptor1);
	extractor.compute(referimg,keypoints2,descriptor2);
	cv::BruteForceMatcher<cv::L2<float> > matcher;
	std::vector<cv::DMatch> matches;
	matcher.match(descriptor1,descriptor2,matches);

	std::ofstream out;
	out.open("./56point.txt");

	std::vector<cv::Point2f> p1((int)matches.size()),p2((int)matches.size());
	std::vector<cv::KeyPoint> p_left_keypoint,p_right_keypoint; 
	for(long i=0;i<matches.size();i++) {
		p_left_keypoint.push_back(keypoints1[ matches[i].queryIdx ]);
		p_right_keypoint.push_back(keypoints2[ matches[i].trainIdx ]);

		out<< (int)keypoints1[ matches[i].queryIdx ].pt.x << " " << (int)keypoints1[ matches[i].queryIdx ].pt.y << " " << (int)keypoints2[ matches[i].trainIdx ].pt.x << " "<< (int)keypoints2[ matches[i].trainIdx ].pt.y <<std::endl;

		p1[i] = cv::Point(keypoints1[ matches[i].queryIdx ].pt.x, keypoints1[ matches[i].queryIdx ].pt.y);
		p2[i] = cv::Point(keypoints2[ matches[i].trainIdx ].pt.x, keypoints2[ matches[i].trainIdx ].pt.y);
	}
	point1 = p1;
	point2 = p2;

	out.close();

	std::string str=QString::number(matches.size()).toLocal8Bit();
	cv::Mat originimg_point,referimg_point;
	cv::drawKeypoints(originimg,p_left_keypoint,originimg_point,cv::Scalar::all(-1),cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	cv::drawKeypoints(referimg,p_right_keypoint,referimg_point,cv::Scalar::all(-1),cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	cv::putText(originimg_point,str,cv::Point(originimg_point.rows*2/3,originimg_point.cols*2/3),CV_FONT_HERSHEY_COMPLEX,1,cv::Scalar(0,0,255));
	cv::putText(referimg_point,str,cv::Point(referimg_point.rows*2/3,referimg_point.cols*2/3),CV_FONT_HERSHEY_COMPLEX,1,cv::Scalar(0,0,255));
	cv::namedWindow("originimg_point");
	cv::imshow("originimg_point",originimg_point);
	cv::namedWindow("referimg_point");
	cv::imshow("referimg_point",referimg_point);
	cv::waitKey(0);

	return ;
}

void getpoints::calculate()
{
	std::ofstream out;
	out.open("matrixf.txt");

	cv::Mat_<float> F,P,K,R,t,H;
	cv::Mat_<float> U,S,V;
	std::vector<cv::Point2f> newp1,newp2;
	F = cv::findFundamentalMat(point1,point2);
	H = cv::findHomography(point1,point2);
	out << "F:" << std::endl << F << std::endl;
	out << "H:" << std::endl << H <<std::endl;
	cv::correctMatches(F,point1,point2,newp1,newp2);
	cv::SVD svd;
	svd.compute(F,S,U,V);
	P = contreps(U.col(2),F);
	out << "P:" << std::endl << P << std::endl;
	cv::decomposeProjectionMatrix(P,K,R,t);	
	out << "K:" << std::endl << K << std::endl; 
	out << "R:" << std::endl << R << std::endl;
	out << "t:" << std::endl << t << std::endl;
	cv::Mat_<float> pt = cv::Mat::zeros(3,4,CV_32F);
	cv::Mat_<float> P1 = cv::Mat::ones(3,4,CV_32F);
	cv::triangulatePoints(P1,P,point1,point2,pt);
	out << "point1:" << std::endl << point1 << std::endl;
	out << "point2:" << std::endl << point2 << std::endl;
	out << "pt:" << std::endl << pt << std::endl;
	out.close();
}

cv::Mat getpoints::contreps(cv::Mat_<float> X,cv::Mat_<float> F)
{
	cv::Mat_<float> Y = cv::Mat::zeros(3,1,CV_32F);
	cv::Mat_<float> Y1 = cv::Mat::zeros(3,1,CV_32F);
	cv::Mat_<float> Y2 = cv::Mat::zeros(3,1,CV_32F);
	cv::Mat_<float> Y3 = cv::Mat::ones(3,1,CV_32F);
	float a[] = {0,0,0,0,0,-1,0,1,0};
	float b[] = {0,0,1,0,0,0,-1,0,0};
	float c[] = {0,-1,0,1,0,0,0,0,0};
	Y = X.t()*cv::Mat(3,3,CV_32F,a);
	Y1 = X.t()*cv::Mat(3,3,CV_32F,b);
	Y2 = X.t()*cv::Mat(3,3,CV_32F,c);
	Y3 = X.t()*cv::Mat::ones(3,3,CV_32F);
	Y.push_back(Y1);
	Y.push_back(Y2);
	Y = (Y*F).t();
	Y.push_back(Y3);
	
	return Y.t();
} 

void getpoints::draw()
{
/*	
	cv::Mat drawimg=cv::Mat::zeros(512,512,CV_8UC3);
	cv::line(drawimg,cv::Point(30,30),cv::Point(60,40),cv::Scalar(0,255,0),10,8);
	cv::namedWindow("draw");
	cv::imshow("draw",drawimg);
	cv::waitKey(0);
	*/
	std::ifstream inf("feature.txt");
	std::ofstream outf("3Dfeature.txt"); 
	double x,y,tmp[3];
	double img,xs,ys;
	int num;
	std::string str;
	inf>>num;
	while(num--) {
		inf >> x >> y; 
		if (x==6) {
			inf >> tmp[0] >> tmp[1] >> tmp[2];
			for(int i=0;i<6;i++) {
				inf >> img >> xs >> ys;
			}
			outf << tmp[0] << " " << tmp[1] << " " << tmp[2] << std::endl;
		}
		else {
			inf >> tmp[0] >> tmp[1] >> tmp[2];
			for(int i=0;i<x;i++) {
				inf >> img >> xs >> ys;
			}
		}
	}
	inf.close();
	outf.close();
}