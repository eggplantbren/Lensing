#ifndef _Profile_
#define _Profile_

/*
* Abstract base class for 2D profiles - lenses and Profiles
*/

#include "MeshGrid.h"
#include "Array.h"

class Profile
{
	protected:
		// Parameters go here

	public:
		// Generate from prior
		virtual void fromPrior() = 0;

		// Surface brightness profile
		virtual double evaluate(double x, double y)
				const = 0;

		// M-H proposals
		virtual double perturb() = 0;

		// Print parameters
		virtual void print(std::ostream& out) const = 0;

		// Evaluate surface brightness profile on a grid
		Array<double> evaluateGrid(const MeshGrid& grid) const;
};

#endif

