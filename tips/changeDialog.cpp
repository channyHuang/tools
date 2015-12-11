#include "changeDialog.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

ChangeDialog::ChangeDialog(QWidget *parent /* = 0 */) : ui(new Ui::ChangeDialog), QDialog(parent)
{
	ui->setupUi(this);

	textEdit = new QTextEdit();
	finishbtn = new QPushButton("Finish");
	timebtn = new QDateTimeEdit();
	timebtn->setDateTime(QDateTime::currentDateTime());
	begintimebtn = new QDateTimeEdit();
	begintimebtn->setDateTime(QDateTime::currentDateTime());
	connect(finishbtn, SIGNAL(clicked()), this, SLOT(finishSlot()));

	QVBoxLayout *mainlayout = new QVBoxLayout();
	mainlayout->addWidget(begintimebtn);
	mainlayout->addWidget(textEdit);
	mainlayout->addWidget(timebtn);
	mainlayout->addWidget(finishbtn);

	setLayout(mainlayout);
}

ChangeDialog::~ChangeDialog() {}

void ChangeDialog::finishSlot() {
	emit sendInfo(textEdit->toPlainText().toStdString(), timebtn->date(), begintimebtn->dateTime());
	this->close();
}