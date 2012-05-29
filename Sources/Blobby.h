#ifndef _Blobby_
#define _Blobby_

/*
* Blobby source profiles
*/

#include "Profile.h"
#include <vector>

class Blobby:public Profile
{
	private:
		// Maximum number of nonzero-mass blobs
		static const int maxNumBlobs;

		// Precision
		static const double maxSigmaSquaredEval;

		// Fraction of blobs with nonzero mass
		double onFraction;

		// Hyperparameter on blob radii
		double muRadius;

		// Hyperparameter on blob masses
		double muMass;

		// Positions, masses, radii
		std::vector<double> xc, yc;
		std::vector<double> mass;
		std::vector<double> radius;

	public:
		Blobby();

		// Generate from prior
		void fromPrior();

		// Surface brightness profile
		double evaluate(double x, double y) const;

		// M-H proposals
		double perturb();

		// Print parameters
		void print(std::ostream& out) const;
};

#endif

