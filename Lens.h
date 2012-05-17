#ifndef _Lens_
#define _Lens_

/*
* Base class for lens models.
*/

#include <ostream>
#include "Grid.h"
#include "Array.h"

class Lens
{
	protected:
		// Parameters go here


	public:
		// Generate from prior
		virtual void fromPrior() = 0;

		// Deflection angles
		virtual void alpha(double x, double y, double& ax, double& ay) const = 0;		

		// M-H proposals
		virtual double perturb() = 0;

		// Print parameters
		virtual void print(std::ostream& out) const = 0;

		// Evaluate deflection angles on a grid
		void alphaGrid(const Grid& grid, Array& ax, Array& ay) const;
};

#endif

