#ifndef SELECTPT_H
#define SELECTPT_H

#include <QtWidgets/QWidget>
#include <QLabel>
#include <QMouseEvent>

#include <fstream>

namespace Ui
{
	class SelectPt;
}

class SelectPt : public QWidget
{
	Q_OBJECT
public:
	SelectPt(QWidget *parent = 0);
	~SelectPt();

	void mousePressEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);

signals:
	void mousepress_signal();

private:
	Ui::SelectPt *ui;

	QLabel *img1label,*img2label;
	int count;

	std::ofstream out;
};


#endif