#include "Blobby.h"

using namespace std;

const int Blobby::maxNumBlobs = 100;

void Blobby::fromPrior()
{

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

