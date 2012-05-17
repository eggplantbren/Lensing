#ifndef _Source_
#define _Source_

/*
* Abstract base class for source surface brightness models
*/

#include "Grid.h"
#include "Array.h"

class Source
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
		Array evaluateGrid(const Grid& grid) const;
};

#endif

