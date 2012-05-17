#include "SIE.h"
#include <cmath>
#include <RandomNumberGenerator.h>

using namespace std;

SIE::SIE()
:b(1.), q(1.), xc(0.), yc(0.)
,theta(0.), cosTheta(1.), sinTheta(0.)
,shear(0.)
,thetaShear(0.), cosThetaShear(1.), sinThetaShear(0.)
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

	// Avoid division by zero by making circular case slightly
	// elliptical
	if(_q == 1.)
		_q = 0.9999999;

	double xx, yy; // Coordinates in rotated frame (ellipticity)
	double xxx, yyy; // Coordinates in rotated frame (shear)

	xx =  _cosTheta*(x - xc) + _sinTheta*(y - yc);
	yy = -_sinTheta*(x - xc) + _cosTheta*(y - yc);

	xxx =  cosThetaShear*x + sinThetaShear*y;
	yyy = -sinThetaShear*x + cosThetaShear*y;

	/* 
	* From Keeton. astro-ph/0102341
	*/

	double psi = sqrt(xx*xx*_q*_q + yy*yy);
	double qq = sqrt(1.0 - _q*_q);
	double coeff = b*_q/qq;

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

double SIE::evaluate(double x, double y) const
{
	 // Coordinates in rotated frame (ellipticity)
	double xx =  cosTheta*(x - xc) + sinTheta*(y - yc);
	double yy = -sinTheta*(x - xc) + cosTheta*(y - yc);

	double rsq = xx*xx*q + yy*yy/q;

	return 0.5*b/sqrt(rsq);
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

