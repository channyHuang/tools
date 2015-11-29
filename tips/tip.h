#ifndef TIP_H
#define TIP_H

#include <QtWidgets/QWidget>
#include "ui_tip.h"

#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QDateTime>
#include <QListWidget>
#include <QListWidgetItem>

namespace Ui
{
	class tipClass;
}

class tipClass : public QWidget
{
	Q_OBJECT

public:
	tipClass(QWidget *parent = 0);
	~tipClass();

private:
	Ui::tipClass *ui;

	void initwidgets();
	void initconnects();

	QListWidget *worklist, *timelist;
	QPushButton *addbtn, *deletebtn;
	QLabel *textlabel;

public slots :
void addText();
void deleteText();
void showChange(std::string subject, QDate endtime, QDateTime begintime);
};

#endif // TIP_H
