#ifndef SHOWINGPLY_H
#define SHOWINGPLY_H

#include <QtWidgets/QWidget>
#include "ui_showingply.h"

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>

#include <string>
using namespace std;

namespace Ui
{
	class showingPly;
}

class showingPly : public QWidget
{
	Q_OBJECT

public:
	showingPly(QWidget *parent = 0);
	~showingPly();

private slots:
	void select();
	void showCloud();

private:
	Ui::showingPly *ui;

	void initwidgets();
	void initconnects();

	QPushButton *showPlybtn, *selectbtn;
	QLineEdit *plyNameEdit;

	string plyFileName;
};

#endif // SHOWINGPLY_H
