#include <cassert>

template<typename Type>
Array<Type>::Array()
:ni(0), nj(0)
,size(0)
,data(size)
{

}

template<typename Type>
Array<Type>::Array(int ni, int nj)
:ni(ni), nj(nj)
,size(ni*nj)
,data(size)
{
	assert(ni >= 0 && nj >= 0);
}

template<typename Type>
Type& Array<Type>::operator () (int i, int j)
{
	assert(i >= 0 && i < ni && j >= 0 && j < nj);
	return data[nj*i + j];
}

template<typename Type>
Type Array<Type>::operator () (int i, int j) const
{
	assert(i >= 0 && i < ni && j >= 0 && j < nj);
	return data[nj*i + j];
}

template<typename Type>
void Array<Type>::print(std::ostream& out) const
{
	for(int i=0; i<size; i++)
		out<<data[i]<<' ';
}


