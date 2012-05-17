#ifndef _Array_
#define _Array_

#include <vector>
#include <ostream>

// Stored in row-major order
template<typename Type>
class Array2D
{
	private:
		int ni, nj, size;
		std::vector<Type> data;

	public:
		Array2D();
		Array2D(int ni, int nj);

		// Element access
		Type& operator () (int i, int j);
		Type  operator () (int i, int j) const;

		// Get size
		int get_ni() { return ni; }
		int get_nj() { return nj; }

		// Print to stream
		void print(std::ostream& out) const;
};

#include "ArrayImpl.h"

#endif

