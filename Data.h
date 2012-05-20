#ifndef _Data_
#define _Data_

/*
* An object of this class is a data set.
*/

#include "Array.h"

class Data
{
	private:
		Array<double> pixels;
		bool loaded;

	public:
		Data();
		void load(const char* filename);
};

#endif

