#include "selectpt.h"
#include "ui_selectpt.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QMessageBox>
#include <QPainter>
#include <QPoint>

#include "data.h"

SelectPt::SelectPt(QWidget *parent /* = 0 */)
	: ui(new Ui::SelectPt),QWidget(parent)
{
	count = 0;

	img1label = new QLabel();
	img2label = new QLabel();

	img1label->setPixmap(QPixmap(name1));
	img2label->setPixmap(QPixmap(name2));

	QHBoxLayout *mainlayout = new QHBoxLayout;
	mainlayout->addWidget(img1label);
	mainlayout->addWidget(img2label);
	setLayout(mainlayout);

	out.open("./selectpoint.txt");
}

SelectPt::~SelectPt()
{
	delete ui;
	out.close();
}

void SelectPt::mousePressEvent(QMouseEvent *event)
{
	int width = 316,height=265;
	QPainter painter(this);
	
	if(event->button()==Qt::LeftButton)
	{
		if(count%2==0) {
			out<<event->x()<<" "<<event->y();
			connect(this,SIGNAL(mousepress_signal()),SLOT(paintEvent(QPaintEvent *)));
		}
		else {
			if(event->x()-width>0 ||event->y()-height>0) {
				out<<event->x()<<" "<<event->y()<<std::endl;
				connect(this,SIGNAL(mousepress_signal()),SLOT(paintEvent(QPaintEvent *)));
			}
		}
		update();
		count++;
	}
	
}

void SelectPt::paintEvent(QPaintEvent *event)
{
/*	QPainter painter(this);
	painter.drawEllipse(QPoint(20,20),10,10);
	update();
*/
}