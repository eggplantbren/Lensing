#include "Blobby.h"
#include "RandomNumberGenerator.h"
#include "Data.h"
#include <cassert>
#include <cmath>

using namespace std;
using namespace DNest3;

const int Blobby::maxNumBlobs = 100;
const double Blobby::maxSigmaSquaredEval = 100.;

Blobby::Blobby()
:U(maxNumBlobs, vector<double>(4))
{

}

void Blobby::fromPrior()
{
	onFraction = exp(log(1E-3) + log(1E3)*randomU());
	muRadius = 1.;
	muMass = 1.;

	for(int i=0; i<maxNumBlobs; i++)
		for(int j=0; j<4; j++)
			U[i][j] = randomU();
}

double Blobby::evaluate(double x, double y) const
{
	double result = 0.;

	double xd, yd, sigSq, mass, temp;
	vector<double> params(4);
	for(int i=0; i<maxNumBlobs; i++)
	{
		transform(U[i], params);

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

void Blobby::transform(const vector<double>& U, vector<double>& params) const
{
	assert(u.size() == params.size());

	double t = 1. - onFraction;
	params[0] = -1. + 2.*U[0];
	params[1] = -1. + 2.*U[1];
	params[2] = -muRadius*log(1. - U[2]);
	params[3] = -muMass*log(1. - (U[3] - t)/onFraction);
}

