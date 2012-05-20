#include "Image.h"

using namespace std;

Image::Image(int ni, int nj,
	double xMin, double xMax, double yMin, double yMax)
:ni(ni), nj(nj)
,xMin(xMin), xMax(xMax), yMin(yMin), yMax(yMax)
,xRange(xMax - xMin), yRange(yMax - yMin)
,dx(xRange/nj), dy(yRange/ni)
,pixels(ni, nj)
{
	assert(ni > 0 && nj > 0 && xRange > 0. && yRange > 0.);
}

void Image::print(ostream& out) const
{
	out<<ni<<' '<<nj<<' '<<xMin<<' '<<xMax<<' '<<yMin<<' '<<yMax<<' ';
	pixels.print(out);
}

