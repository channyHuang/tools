#include "showingply.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	showingPly w;
	w.show();
	return a.exec();
}
