#ifndef _Blobby_
#define _Blobby_

/*
* Blobby source profiles
*/

#include "Profile.h"

class Blobby:public Profile
{
	private:


	public:
		// Generate from prior
		void fromPrior();

		// Surface brightness profile
		double evaluate(double x, double y);

		// M-H proposals
		double perturb();

		// Print parameters
		void print(std::ostream& out) const;

};

#endif

