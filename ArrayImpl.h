#include <cassert>
#include <iomanip>

template<typename Type>
Array<Type>::Array(int ni, int nj)
:ni(ni), nj(nj)
,size(ni*nj)
,data(size)
{
	assert(ni >= 0 && nj >= 0);
}

template<typename Type>
Array<Type>::Array(int ni, int nj, const Type& value)
:ni(ni), nj(nj)
,size(ni*nj)
,data(size, value)
{
	assert(ni >= 0 && nj >= 0);
}

template<typename Type>
void Array<Type>::set(const Type& value)
{
	for(int i=0; i<size; i++)
		data[i] = value;
}

template<typename Type>
Type& Array<Type>::operator () (int i, int j)
{
	assert(i >= 0 && i < ni && j >= 0 && j < nj);
	return data[nj*i + j];
}

template<typename Type>
const Type& Array<Type>::operator () (int i, int j) const
{
	assert(i >= 0 && i < ni && j >= 0 && j < nj);
	return data[nj*i + j];
}

template<typename Type>
void Array<Type>::print(std::ostream& out) const
{
	out<<std::setprecision(10);
	for(int i=0; i<size; i++)
		out<<data[i]<<' ';
}

