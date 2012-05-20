#include "MeshGrid.h"
#include <vector>
#include <cassert>

using namespace std;

MeshGrid::MeshGrid(int ni, int nj,
	double xMin, double xMax, double yMin, double yMax)
:ni(ni), nj(nj)
,xMin(xMin), xMax(xMax), yMin(yMin), yMax(yMax)
,xRange(xMax - xMin), yRange(yMax - yMin)
,dx(xRange/nj), dy(yRange/ni)
,x(ni, nj), y(ni, nj)
{
	assert(ni > 0 && nj > 0 && xRange > 0. && yRange > 0.);

	vector<double> xx(nj), yy(ni);
	for(int i=0; i<ni; i++)
		yy[i] = yMax - (i + 0.5)*dy;
	for(int j=0; j<nj; j++)
		xx[j] = xMin + (j + 0.5)*dx;

	// Fill the MeshGrid
	for(int i=0; i<ni; i++)
	{
		for(int j=0; j<nj; j++)
		{
			x(i, j) = xx[j];
			y(i, j) = yy[i];
		}
	}
}


void MeshGrid::print(ostream& out) const
{
	x.print(out);
	y.print(out);
}

