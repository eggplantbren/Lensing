#ifndef _SIE_
#define _SIE_

#include <Lens.h>
#include <ostream>

class SIE:public Lens
{
	private:
		// Parameters of a SIE
		double b;
		double q;
		double xc;
		double yc;
		double theta, cosTheta, sinTheta;
		double shear;
		double thetaShear, cosThetaShear, sinThetaShear;

	public:		
		SIE();

		// Generate from prior
		void fromPrior();

		// M-H proposals
		double perturb();

		// Print parameters
		void print(std::ostream& out) const;

		// Deflection angles
		void alpha(double x, double y, double& ax, double& ay) const;

		// Surface mass density
		double evaluate(double x, double y) const;
};

#endif

