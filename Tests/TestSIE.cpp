#include <iostream>
#include <Lenses/SIE.h>
#include <MeshGrid.h>

using namespace std;

int main()
{
	SIE sie;
	MeshGrid grid(1001, 1001, -1., 1., -1., 1.);
	Array<double> ax(1001, 1001), ay(1001, 1001);
	Array<double> result = sie.densityGrid(grid, 1E-7);
	grid.print(cout);
	result.print(cout);
	return 0;
}

