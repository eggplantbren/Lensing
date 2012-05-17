#ifndef _Grid_
#define _Grid_

#include <ostream>
#include "Array.h"

class Grid
{
	private:
		// Borders, number of points, etc
		int ni, nj;
		double xMin, xMax, yMin, yMax;
		double xRange, yRange, dx, dy;

		Array x, y;

	public:
		Grid(int ni, int nj,
			double xMin, double xMax, double yMin, double yMax);
		void print(std::ostream& out) const;

		// Read-only getter
		double get_x(int i, int j) const { return x(i, j); }
};

#endif

