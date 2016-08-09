#include "opencv/cv.h"
#include <iostream>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <math.h> 
#include <vector>
#include <algorithm>
#include <fstream>

#include <QtCore/QDir>

using namespace std;

namespace my {
	bool cmp(const CvRect& ca, const CvRect& cb) {
		return ca.y < cb.y;
	}
}

int totalWords = 0;

void cut(IplImage *pSrc, CvRect rect, bool flag, int no) {
	CvSize size = cvSize(rect.width, rect.height);//区域大小

	cvSetImageROI(pSrc, rect);//设置源图像ROI

	IplImage* pDest = cvCreateImage(size, pSrc->depth, pSrc->nChannels);//创建目标图像

	cvCopy(pSrc, pDest); //复制图像

	cvResetImageROI(pDest);//源图像用完后，清空ROI

	char str[100];
	if (flag == false) {
		sprintf(str, "word/word_%05d.jpg", no);
		cvSaveImage(str, pDest);//保存目标图像
	}
	else {
		sprintf(str, "mean/mean_%05d.jpg", no);
		cvSaveImage(str, pDest);
	}
	cvReleaseImage(&pDest);
}

void com(char *a, char *b) {
	cv::Mat img1 = cv::imread(a);
	cv::Mat img2 = cv::imread(b);

	cv::Mat img(img1.rows + img2.rows, img1.cols, img1.type(), cv::Scalar(0));
	cv::Mat imgROI = img(cv::Rect(0, 0, img1.cols, img1.rows));
	img1.copyTo(imgROI, img1);
	imgROI = img(cv::Rect(0, img1.rows, img2.cols, img2.rows));
	img2.copyTo(imgROI, img2);

	cv::imwrite(a, img);
}

void on_trackbar(IplImage *src, IplImage *bianyuan, CvMemStorage *storage)
{
	IplImage *img;
	img = cvCreateImage(cvGetSize(bianyuan), 8, 1);

	int thresh = 50;

	CvSeq* contour = 0;
	if (storage == NULL)
	{
		storage = cvCreateMemStorage(0);
	}
	else
	{
		cvClearMemStorage(storage);
	}
	cvSmooth(bianyuan, bianyuan, CV_GAUSSIAN, 3, 3, 0, 0);
	cvThreshold(bianyuan, img, thresh, 200, CV_THRESH_BINARY);

	cvFindContours(img, storage, &contour, sizeof(CvContour), CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE, cvPoint(0, 0));  //查找轮廓

	int n = 0;

	vector<CvRect> pageRects;

	for (; contour; contour = contour->h_next)
	{
		CvRect rect = cvBoundingRect(contour, 1);       // 获取矩形边界框 

		if (rect.x > 150 || rect.height < 30|| rect.width < 100 || rect.width > 450) continue;

		CvRect tmp;

		tmp.x = rect.x;
		tmp.y = rect.y;

		tmp.height = rect.height;
		tmp.width = rect.width;
		pageRects.push_back(tmp);
		n++;
	}
	
	sort(pageRects.begin(), pageRects.end(), my::cmp);    //依次增大
	
	//************
	for (int i = 0; i < pageRects.size(); i++) {
		CvRect trect1 = pageRects.at(i);

#if 1
		if (i == 0 && trect1.y > 80) {
			//last word
			CvRect addrect = cvRect(340, 60, 1420, trect1.y - 60);

			cvSetImageROI(src, addrect);//设置源图像ROI
			IplImage* pDest = cvCreateImage(cvSize(addrect.width, addrect.height), src->depth, src->nChannels);//创建目标图像
			cvCopy(src, pDest); //复制图像
			cvResetImageROI(pDest);//源图像用完后，清空ROI
			char str[100];
			sprintf(str, "mean/mean_%05d_add.jpg", totalWords - 1);
			cvSaveImage(str, pDest);
			cvReleaseImage(&pDest);

			char orgname[100], addname[100];
			sprintf(orgname, "mean/mean_%05d.jpg", totalWords - 1);
			sprintf(addname, "mean/mean_%05d_add.jpg", totalWords - 1);
			com(orgname, addname);

			remove(addname);
		}
#endif

		CvRect trect2 = cvRect(trect1.x + trect1.width, trect1.y, 1420, trect1.height);

		if (i < pageRects.size() - 1) trect2.height = pageRects.at(i + 1).y - trect1.y;
		else trect2.height = 2550 - trect1.y;

		if (trect2.x + trect2.width > src->width || trect2.y + trect2.height > src->height) {
			std::cout << "Error: " << totalWords << std::endl;
			continue;
		}
		else {
			cut(src, trect1, false, totalWords);
			cut(src, trect2, true, totalWords);
		}
		

		totalWords++;

	}

}

void txtmaker(int totalWords) {

	std::cout << "Total words: " << totalWords << std::endl;

	ofstream txtfile("datapath.txt");

	for (int i = 0; i < totalWords; i++) {
		char wordname[100], meanname[100];
		sprintf(wordname, "word/word_%05d.jpg", i);
		sprintf(meanname, "mean/mean_%05d.jpg", i);
		txtfile << "<img src=\'" << wordname << "\'> \t" << "<img src=\'" << meanname << "\'> " << std::endl;
	}

	txtfile.close();
}

int main()
{
	ofstream of("message.txt");
	streambuf *streams = cout.rdbuf();
	cout.rdbuf(of.rdbuf());

	QDir dir("E:/document/page");
	dir.setFilter(QDir::Files);
	QFileInfoList list = dir.entryInfoList();

	std::cout << "Total page: " << list.size() << std::endl;

	int idx = 0;
	for each (QFileInfo fileinfo in list) {
		idx++;
		std::cout << "Page " << idx << " of " << list.size() << ", totalWords = " << totalWords << std::endl;

		IplImage* src;
		IplImage* bianyuan;
		CvMemStorage* storage = NULL;


		src = cvLoadImage(fileinfo.absoluteFilePath().toStdString().c_str(), 0);


		//	const char* a = "test.jpg";
		//	src = cvLoadImage(a, 0);

		if (!src)
			return -1;

		cvSmooth(src, src, CV_GAUSSIAN, 5, 5, 0, 0);

		bianyuan = cvCreateImage(cvGetSize(src), 8, 1);
		cvEqualizeHist(src, bianyuan);
		cvSmooth(bianyuan, bianyuan, CV_MEDIAN, 3, 3, 0, 0);
		cvCanny(bianyuan, bianyuan, 200, 600, 3);

		on_trackbar(src, bianyuan, storage);

		cvReleaseImage(&src);
		cvReleaseImage(&bianyuan);
		cvReleaseMemStorage(&storage);
	}

//	txtmaker(totalWords);

	cout.rdbuf(streams);
//	txtmaker(8167);
	
	return 0;
}