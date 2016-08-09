#include <QDir>
#include <QStringList>

#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
	QDir dir(QDir::currentPath());
	dir.setFilter(QDir::Files);
	
	QStringList filters;
	filters << "*.lib";// << ".cpp"
	dir.setNameFilters(filters);
	QFileInfoList list = dir.entryInfoList();

	std::ofstream of("libs.txt");
	for each (QFileInfo fileinfo in list) {
		of << fileinfo.fileName().toStdString().c_str() << std::endl;
	}
	of.close();
}