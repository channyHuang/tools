#ifndef CHANGEDIALOG_H
#define CHANGEDIALOG_H

#include "ui_changeDialog.h"

#include <QtWidgets/QDialog>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QDateTimeEdit>

namespace Ui
{
	class ChangeDialog;
}

class ChangeDialog :public QDialog {
	Q_OBJECT
public:
	ChangeDialog(QWidget *parent = 0);
	~ChangeDialog();

private:
	Ui::ChangeDialog *ui;

	std::string work;
	QTextEdit *textEdit;
	QPushButton *finishbtn;
	QDateTimeEdit *timebtn, *begintimebtn;
signals:
	void sendInfo(std::string, QDate, QDateTime);
private slots:
void finishSlot();
};

#endif