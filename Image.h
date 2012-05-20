#ifndef _Image_
#define _Image_

#include "Array.h"
#include <istream>

class Image
{
	private:
		// Borders, number of points, etc
		int ni, nj;
		double xMin, xMax, yMin, yMax;
		double xRange, yRange, dx, dy;

		Array<double> pixels;

	public:
		Image(int ni, int nj,
			double xMin, double xMax, double yMin, double yMax);
		void print(std::ostream& out) const;
		void read(std::istream& in) const;

		// Read-only getters
		double get_pixel(int i, int j) const { return pixels(i, j); }
		int get_ni() const { return ni; }
		int get_nj() const { return nj; }


};

#endif

