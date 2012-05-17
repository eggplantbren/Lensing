#include "Array.h"
#include <cassert>

template<typename Type>
Array2D<Type>::Array2D()
:ni(0), nj(0)
,size(0)
,data(size)
{

}

template<typename Type>
Array2D<Type>::Array2D(int ni, int nj)
:ni(ni), nj(nj)
,size(ni*nj)
,data(size)
{
	assert(ni >= 0 && nj >= 0);
}

template<typename Type>
Type& Array2D<Type>::operator () (int i, int j)
{
	assert(i >= 0 && i < ni && j >= 0 && j < nj);
	return data[nj*i + j];
}

template<typename Type>
Type Array2D<Type>::operator () (int i, int j) const
{
	assert(i >= 0 && i < ni && j >= 0 && j < nj);
	return data[nj*i + j];
}

template<typename Type>
void Array2D<Type>::print(std::ostream& out) const
{
	for(int i=0; i<ni; i++)
	{
		for(int j=0; j<nj; j++)
			out<<data[nj*i + j]<<' ';
		out<<std::endl;
	}
}

typedef Array2D<double> Array;

