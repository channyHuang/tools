#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
	:ui(new Ui::MainWidget), QWidget(parent)
{
	ui->setupUi(this);

	initwidgets();
	initconnects();

	QVBoxLayout *mainlayout = new QVBoxLayout();
	mainlayout->addWidget(btn);
	mainlayout->addWidget(glwidget);

	setLayout(mainlayout);
}

MainWidget::~MainWidget()
{
	delete ui;
}

void MainWidget::initwidgets() {
	btn = new QPushButton("Button");

	glwidget = new GLWidget();
}

void MainWidget::initconnects() {}