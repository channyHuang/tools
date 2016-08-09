#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets/QWidget>
#include "ui_mainwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "glWidget.h"

namespace Ui {
	class MainWidget;
};

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();


	void initwidgets();
	void initconnects();

private:
	Ui::MainWidget *ui;

	QPushButton *btn;

	GLWidget *glwidget;
};

#endif // MAINWIDGET_H
