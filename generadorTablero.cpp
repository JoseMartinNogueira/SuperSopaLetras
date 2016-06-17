#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <sys/param.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <errno.h>
#if defined(_WIN32)
#include <direct.h> 
#endif
using namespace std;

void crear_tablero(int num){
    char filename[100];
    sprintf(filename, "test%d.values", num);
    ofstream fout(filename);
    ofstream myfile;
    myfile.open(filename);

	int size = rand()%100;
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j) {
			myfile << rand()%10 << ' ' ;
		}
		myfile << "\n";
	}
	myfile.close();
}

void crear_diccionario(int num){
    char filename[100];
    sprintf(filename, "dicc%d.values", num);
    ofstream fout(filename);
    ofstream myfile;
    myfile.open(filename);

	int size = rand()%10000;
	for (int i = 0; i < size; ++i)	myfile << rand() << ' ' ;
	myfile << "\n";
	myfile.close();
}

string getcwd(){
    char *buffer = new char[MAXPATHLEN];
    getcwd(buffer,MAXPATHLEN);
    if(buffer != NULL){
        string ret(buffer);
        delete[] buffer;
        return ret;
    }else{
        return string();
    }
}

bool isDirExist(const std::string& path){
#if defined(_WIN32)
    struct _stat info;
    if (_stat(path.c_str(), &info) != 0)
    {
        return false;
    }
    return (info.st_mode & _S_IFDIR) != 0;
#else 
    struct stat info;
    if (stat(path.c_str(), &info) != 0)
    {
        return false;
    }
    return (info.st_mode & S_IFDIR) != 0;
#endif
}

bool makePath(const std::string& path){
#if defined(_WIN32)
    int ret = _mkdir(path.c_str());
#else
    mode_t mode = 0755;
    int ret = mkdir(path.c_str(), mode);
#endif
    if (ret == 0)
        return true;

    switch (errno)
    {
    case ENOENT:
        {
            int pos = path.find_last_of('/');
            if (pos == std::string::npos)
#if defined(_WIN32)
                pos = path.find_last_of('\\');
            if (pos == std::string::npos)
#endif
                return false;
            if (!makePath( path.substr(0, pos) ))
                return false;
        }

#if defined(_WIN32)
        return 0 == _mkdir(path.c_str());
#else 
        return 0 == mkdir(path.c_str(), mode);
#endif

    case EEXIST:
        // done!
        return isDirExist(path);

    default:
        return false;
    }
}


int main(){
	char dir[100];

	string cwd = getcwd();
	cwd.append("/test");
	makePath (cwd);
	chdir(cwd.c_str());

	srand(time(NULL));
	int n_tableros = rand()%1000;
	for (int i = 0; i < n_tableros; ++i) {
		crear_tablero(i);
		crear_diccionario(i);
	}

}
