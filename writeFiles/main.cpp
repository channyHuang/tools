#include <iostream>
#include <fstream>

#include <QString>
#include <QDir>
#include <QStringList>

void copySingleFolder(QString sourcedir, QString targetdir, QString foldername, bool isleft) {
	QDir sdir(sourcedir);
	QFileInfoList slist = sdir.entryInfoList(QDir::Files);

	QString addname = "_left";
	if (!isleft) addname = "_right";

	QDir tdir(targetdir);
	tdir.mkdir(foldername + addname);
	tdir.cd(foldername + addname);
	tdir.mkdir("data");
	tdir.cd("data");
	tdir.mkdir("pic");
	tdir.cd("pic");

	int i = 1;
	for each (QFileInfo fileinfo in slist) {
		QFile::copy(fileinfo.absoluteFilePath(), tdir.absolutePath() + "/" + QString("%1").arg(i, 4, 10, QChar('0')) + ".jpg");
		i++;
	}

	tdir.cd("../");
	tdir.mkdir("mask");
	tdir.cd("mask");
	i = 1;
	for each (QFileInfo fileinfo in slist) {
		QFile::copy(fileinfo.absoluteFilePath(), tdir.absolutePath() + "/" + QString("%1").arg(i, 4, 10, QChar('0')) + ".bmp");
		i++;
	}
}

void copyRawImage(QString dirname) {
	QString path = "E:/ArtShoe2_reconstruction/data";

	QDir dir(dirname);
	QFileInfoList list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
	for each (QFileInfo fileinfo in list) {
		QString str = fileinfo.absoluteFilePath();
		copySingleFolder(str + "/left", path, fileinfo.fileName(), true);
		copySingleFolder(str + "/right", path, fileinfo.fileName(), false);
	}
}

int main(int argc, char** argv) {
//	copyRawImage("E:/1611_foot_data/0_dc");
//	copySingleFolder("E:/1611_foot_data/0_dc/f001_dc/left", "E:/ArtShoe2_reconstruction/data", "f001_dc", true);

	argc = 2;
	argv[1] = "E:/ArtShoe2_reconstruction/data";
	if (argc != 2) {
		std::cout << "Usage: writeFiles.exe dir" << std::endl;
		return 0;
	}

	QString dirname = argv[1];
	QDir dir(dirname);
	QFileInfoList list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
	for each (QFileInfo fileinfo in list) {
		std::string str = "E:/ArtShoe2_reconstruction/ini/" + fileinfo.fileName().toStdString();
		std::ofstream of(str + ".ini");
		of << "data_dir=" << fileinfo.fileName().toStdString() << "/" << std::endl << "process_config=process.ini" << std::endl;
		of.close();
	}

	return 0;
}
