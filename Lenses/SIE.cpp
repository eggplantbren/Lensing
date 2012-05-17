#include "SIE.h"
#include <cmath>

using namespace std;

SIE::SIE()
{

}

void SIE::fromPrior()
{

}

void SIE::alpha(double x, double y, double& ax, double& ay) const
{
	double _q = q;
	double _theta = theta;
	double _sinTheta = sinTheta;
	double _cosTheta = cosTheta;

	if(q > 1)
	{
		_q = 1.0/q;
		_theta += 0.5*M_PI;
		_sinTheta = cosTheta;
		_cosTheta = -sinTheta;
	}

	double xx, yy; // Coordinates in rotated frame (ellipticity)
	double xxx, yyy; // Coordinates in rotated frame (shear)

	xx =  _cosTheta*(x - xc) + _sinTheta*(y - yc);
	yy = -_sinTheta*(x - xc) + _cosTheta*(y - yc);

	xxx =  cosThetaShear*x + sinThetaShear*y;
	yyy = -sinThetaShear*x + cosThetaShear*y;

	/* 
	* From Keeton. astro-ph/0102341
	*/

	double psi = sqrt(xx*xx*_q + yy*yy/_q);
	double qq = sqrt(1.0 - _q*_q);
	double coeff = b/qq;

	double axprime = coeff*atan(qq*xx/psi);
	double ayprime = coeff*atanh(qq*yy/psi);

	ax =  axprime*_cosTheta - ayprime*_sinTheta;
	ay =  axprime*_sinTheta + ayprime*_cosTheta;

	// Now just do shear
	double axshear =  shear*xxx;
	double ayshear = -shear*yyy;

	ax += axshear*cosThetaShear - ayshear*sinThetaShear;
	ay += axshear*sinThetaShear + ayshear*cosThetaShear;
}

double SIE::perturb()
{
	return 0.;
}

void SIE::print(ostream& out) const
{
	out<<b<<' '<<q<<' '<<xc<<' '<<yc<<' '<<theta<<' '
		<<shear<<' '<<thetaShear;
}

