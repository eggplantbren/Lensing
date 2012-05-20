#include "Data.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

Data::Data()
:image(1, 1, -1., 1., -1., 1.)
,loaded(false)
{

}

void Data::load(const char* filename)
{
	fstream fin(filename, ios::in);

	// Check that the file was opened successfully
	if(!fin)
	{
		cerr<<"# Error. Couldn't open file "<<filename<<
			" for reading. No data was loaded."<<endl;
		fin.close();
		return;
	}

	image.read(fin);
	loaded = true;
}

