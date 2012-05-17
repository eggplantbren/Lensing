#include "Lens.h"

void Lens::alphaGrid(const Grid& grid, Array& ax, Array& ay) const
{
	ax.conservativeResize(grid.get_ni(), grid.get_nj());
	ay.conservativeResize(grid.get_ni(), grid.get_nj());

	for(int i=0; i<grid.get_ni(); i++)
		for(int j=0; j<grid.get_nj(); j++)
			alpha(grid.get_x(i, j), grid.get_y(i, j),
				ax(i, j), ay(i, j));
}
