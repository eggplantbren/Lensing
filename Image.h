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
		void read(std::istream& in);

		// Read-only getters
		double get_pixel(int i, int j) const { return pixels(i, j); }
		int get_ni() const { return ni; }
		int get_nj() const { return nj; }
		double get_xMin() const { return xMin; }
		double get_xMax() const { return xMax; }
		double get_yMin() const { return yMin; }
		double get_yMax() const { return yMax; }
		double get_xRange() const { return xRange; }
		double get_yRange() const { return yRange; }
		double get_dx() const { return dx; }
		double get_dy() const { return dy; }
};

#endif

