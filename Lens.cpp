#include "Lens.h"
#include <cassert>

void Lens::alphaGrid(const Grid& grid, Array& ax, Array& ay) const
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

