#include "Lens.h"
#include <cassert>

void Lens::alphaGrid(const MeshGrid& grid, Array& ax, Array& ay) const
{
	assert( grid.get_ni() == ax.get_ni() &&
		grid.get_nj() == ax.get_nj() &&
		grid.get_ni() == ay.get_ni() &&
		grid.get_nj() == ay.get_nj());

	for(int i=0; i<grid.get_ni(); i++)
		for(int j=0; j<grid.get_nj(); j++)
			alpha(grid.get_x(i, j), grid.get_y(i, j),
				ax(i, j), ay(i, j));
}

double Lens::density(double x, double y, double h) const
{
	double ax1, ax2, ay1, ay2, term1, term2;

	// Divergence of deflection angle field
	alpha(x+h, y, ax1, ay1);
	alpha(x-h, y, ax2, ay2);
	term1 = (ax1 - ax2)/(2*h);

	alpha(x, y+h, ax1, ay1);
	alpha(x, y-h, ax2, ay2);
	term2 = (ay1 - ay2)/(2*h);

	return (term1 + term2)/2;
}

Array Lens::densityGrid(const MeshGrid& grid, double h) const
{
	Array results(grid.get_ni(), grid.get_nj());
	for(int i=0; i<grid.get_ni(); i++)
		for(int j=0; j<grid.get_nj(); j++)
			results(i, j) = density(grid.get_x(i, j), grid.get_y(i, j),
				h);

	return results;
}

