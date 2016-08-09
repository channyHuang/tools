#include <iostream>
#include <fstream>

#include <QDir>
#include <QFileInfoList>

QFileInfoList GetFileList(QString path)
{
    QDir dir(path);
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
 
	int folderNum = folder_list.size();
    for(int i = 0; i != folderNum; i++)
    {
         QString name = folder_list.at(i).absoluteFilePath();
         QFileInfoList child_file_list = GetFileList(name);
		 folder_list.append(child_file_list);
    }
 
    return folder_list;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Usage: argv[1] = path \n For example: \n > readAllPath.exe E:/" << std::endl;
		return 0;
	}
	
	QFileInfoList list = GetFileList(argv[1]);
	std::ofstream of("path.txt");
	for each (QFileInfo fileinfo in list) {
		of << fileinfo.absoluteFilePath().toStdString().c_str() << std::endl;
	}
	of.close();
	
	return 0;
}