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

		// Uniform latent variables
		// (position, position, size, mass)
		std::vector<double> u1, u2, u3, u4;

	public:
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

