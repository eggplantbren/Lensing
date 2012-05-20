#ifndef _Array_
#define _Array_

#include <vector>
#include <ostream>

// Stored in row-major order
template<typename Type>
class Array
{
	private:
		int ni, nj, size;
		std::vector<Type> data;

	public:
		Array(int ni, int nj);

		// Element access
		Type& operator () (int i, int j);
		Type  operator () (int i, int j) const;

		// Get size
		int get_ni() const { return ni; }
		int get_nj() const { return nj; }

		// Print to stream
		void print(std::ostream& out) const;
};

#include "ArrayImpl.h"

#endif

