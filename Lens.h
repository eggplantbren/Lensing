#ifndef _LENS_
#define _LENS_

/*
* Base class for lens models.
*/

class Lens
{
	protected:
		// Parameters go here


	public:
		virtual void fromPrior() = 0;

		// Deflection angles
		virtual void alpha(double x, double y, double& ax, double& ay) const = 0;		

		// M-H proposals
		virtual double perturb() = 0;
};

#endif

