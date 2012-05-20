#include "Profile.h"

Array Profile::evaluateGrid(const Grid& grid) const
{
	Array result(grid.get_ni(), grid.get_nj());
	for(int i=0; i<grid.get_ni(); i++)
		for(int j=0; j<grid.get_nj(); j++)
			result(i, j) = evaluate(grid.get_x(i, j),
						grid.get_y(i, j));
	return result;
}

