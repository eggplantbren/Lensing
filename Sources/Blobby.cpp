#include "Blobby.h"
#include "RandomNumberGenerator.h"

using namespace std;
using namespace DNest3;

const int Blobby::maxNumBlobs = 100;

Blobby::Blobby()
:U(maxNumBlobs, vector<double>(4))
{

}

void Blobby::fromPrior()
{
	for(int i=0; i<maxNumBlobs; i++)
		for(int j=0; j<4; j++)
			U[i][j] = randomU();
}

double Blobby::evaluate(double x, double y) const
{
	x = x + y;
	return 0.;
}

double Blobby::perturb()
{
	return 0.;
}

void Blobby::print(ostream& out) const
{
	out<<' ';
}

