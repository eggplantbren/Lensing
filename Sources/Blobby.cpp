#include "Blobby.h"
#include "RandomNumberGenerator.h"
#include <cassert>
#include <cmath>

using namespace std;
using namespace DNest3;

const int Blobby::maxNumBlobs = 100;
const double Blobby::maxSigmaSquaredEval = 100.;
const double Blobby::minMuRadius = 1E-3;
const double Blobby::maxMuRadius = 1E3;
const double Blobby::rangeMuRadius = log(Blobby::maxMuRadius/Blobby::minMuRadius);
const double Blobby::minMuMass = 1E-3;
const double Blobby::maxMuMass = 1E3;
const double Blobby::rangeMuMass = log(Blobby::maxMuMass/Blobby::minMuMass);
const double Blobby::minX0 = -1.;
const double Blobby::maxX0 =  1.;
const double Blobby::rangeX0 = Blobby::maxX0 - Blobby::minX0;
const double Blobby::minY0 = -1.;
const double Blobby::maxY0 =  1.;
const double Blobby::rangeY0 = Blobby::maxY0 - Blobby::minY0;



Blobby::Blobby()
{

}

void Blobby::fromPrior()
{
	muRadius = exp(log(minMuMass) + rangeMuMass*randomU());
	muMass = exp(log(minMuRadius) + rangeMuRadius*randomU());
	
}

double Blobby::evaluate(double x, double y) const
{
	double result = 0.;

	double xd, yd, sigSq, mass, temp;
	vector<double> params(4);
	for(int i=0; i<maxNumBlobs; i++)
	{
		if(params[3] > 0.)
		{
			xd = x - params[0];
			yd = y - params[1];
			sigSq = params[2]*params[2];
			mass = params[3];
			temp = (xd*xd + yd*yd)/sigSq;

			if(temp < maxSigmaSquaredEval)
			{
				result += mass*exp(-0.5*temp)
					/(2*M_PI*sigSq);
			}
		}
	}
	return result;
}

double Blobby::perturb()
{
	return 0.;
}

void Blobby::print(ostream& out) const
{
	out<<' ';
}

