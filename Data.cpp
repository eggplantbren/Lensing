#include "Data.h"
#include <fstream>

using namespace std;

Data::Data()
:loaded(false)
{

}

void Data::load(const char* filename)
{
	fstream fin(filename, ios::in);
	fin.close();
}

