#ifndef _LENS_
#define _LENS_

/*
* Base class for lens models.
*/

#include <ostream>

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
};

#endif

