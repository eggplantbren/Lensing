#include "Profile.h"

Array<double> Profile::evaluateGrid(const MeshGrid& grid) const
{
	Array<double> result(grid.get_ni(), grid.get_nj());
	for(int i=0; i<grid.get_ni(); i++)
		for(int j=0; j<grid.get_nj(); j++)
			result(i, j) = evaluate(grid.get_x(i, j),
						grid.get_y(i, j));
	return result;
}

