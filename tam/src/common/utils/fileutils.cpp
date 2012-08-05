#include "fileutils.h"
#include <fstream>
#include <sys/types.h>
#include <dirent.h>

using namespace common::utils;
using namespace std;

long FileUtils::getFileSize(const string& path) {
	long length;
	fstream file(path.c_str(), ios::in);
	file.seekg(0, ios::end);
  length = file.tellg();
  file.close();
  return length;
}
				
bool FileUtils::fileExists(const string& path) {
	ifstream file(path.c_str());
	return file;
}

int FileUtils::countDirs(string& basePath, bool excludeDotDirs) {
	int count = -1;
	DIR *d;
	if((d = opendir(basePath.c_str())) != NULL) {
		for(count = 0; readdir(d) != NULL; count++);
		closedir(d);
	}
	return excludeDotDirs ? count - 2 : count;
}

/**
 * Copia un archivo
 * @param src Ruta y nombre del archivo de origen.
 * @param dst Ruta y nombre del archivo de destino.
 */
void FileUtils::copy(const string& src, const string& dst) {
	std::ifstream in(src.c_str());
	std::ofstream out(dst.c_str());
	out << in.rdbuf();
	in.close();
	out.close();
}
