#include "Blobby.h"
#include "RandomNumberGenerator.h"
#include <cassert>
#include <cmath>

using namespace std;
using namespace DNest3;

const int Blobby::maxNumBlobs = 100;
const double Blobby::maxSigmaSquaredEval = 100.;

Blobby::Blobby()
{

}

void Blobby::fromPrior()
{
	muRadius = 1.;
	muMass = 1.;

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

