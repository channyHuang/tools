#include "tip.h"
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include "changeDialog.h"

#include <iostream>

tipClass::tipClass(QWidget *parent)
	:ui(new Ui::tipClass), QWidget(parent)
{
	ui->setupUi(this);

	initwidgets();
	initconnects();
	QGridLayout *listlayout = new QGridLayout();
	listlayout->addWidget(worklist, 0, 0, 1, 1);
	listlayout->addWidget(timelist, 0, 1, 1, 3);
	QHBoxLayout *btnlayout = new QHBoxLayout();
	btnlayout->addWidget(addbtn);
	btnlayout->addWidget(deletebtn);
	QVBoxLayout *mainlayout = new QVBoxLayout();
	mainlayout->addWidget(textlabel);
	mainlayout->addLayout(listlayout);
	mainlayout->addLayout(btnlayout);

	setLayout(mainlayout);

	//setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
	setWindowFlags(windowFlags() | Qt::WindowStaysOnBottomHint);
	setWindowOpacity(0.5);
}

tipClass::~tipClass()
{
	delete ui;
}

void tipClass::initwidgets() {
	worklist = new QListWidget();
	timelist = new QListWidget();
	worklist->setFont(QFont("Times", 12, QFont::Bold));
	timelist->setFont(QFont("Times", 12));

	addbtn = new QPushButton("Add");
	deletebtn = new QPushButton("Delete");
	textlabel = new QLabel("Work : Deadline");
}
void tipClass::initconnects() {
	connect(addbtn, SIGNAL(clicked()), this, SLOT(addText()));

	connect(deletebtn, SIGNAL(clicked()), this, SLOT(deleteText()));
}

void tipClass::addText() {
	ChangeDialog *changedlg = new ChangeDialog(this);
	connect(changedlg, SIGNAL(sendInfo(std::string, QDate, QDateTime)), this, SLOT(showChange(std::string, QDate, QDateTime)));

	changedlg->show();
}

void tipClass::showChange(std::string subject, QDate endtime, QDateTime begintime)
{
	QListWidgetItem *newWorkItem = new QListWidgetItem(worklist);
	newWorkItem->setText(subject.c_str());
	worklist->addItem(newWorkItem);

	QListWidgetItem *newTimeItem = new QListWidgetItem(timelist);
	newTimeItem->setText(endtime.toString()+", start in "+begintime.toString());
	worklist->addItem(newTimeItem);
}

void tipClass::deleteText() {
	int drow = worklist->currentRow();
	delete worklist->item(drow);
	delete timelist->item(drow);
}