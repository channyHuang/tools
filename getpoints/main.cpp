#include "getpoints.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	getpoints w;
	w.show();
	return a.exec();
}
