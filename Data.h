#ifndef _Data_
#define _Data_

/*
* An object of this class is a data set.
*/

#include "Image.h"

class Data
{
	private:
		Image image;
		bool loaded;

	public:
		Data();
		void load(const char* filename);

	// Static instance
	private:
		static Data instance;
		static Data& get_instance() { return instance; }
};

#endif

