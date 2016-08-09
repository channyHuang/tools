#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2)

#include "pcltest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	pclTest w;
	w.show();
	return a.exec();
}
