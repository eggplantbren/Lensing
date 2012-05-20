#include <iostream>
#include <Lenses/SIE.h>
#include <Grid.h>

using namespace std;

int main()
{
	SIE sie;
	Grid grid(1001, 1001, -1., 1., -1., 1.);
	Array ax(1001, 1001), ay(1001, 1001);
	Array result = sie.densityGrid(grid, 1E-7);
	grid.print(cout);
	result.print(cout);
	return 0;
}

