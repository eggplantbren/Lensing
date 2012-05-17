#ifndef _SIE_
#define _SIE_

#include "../Lens.h"
#include <ostream>

class SIE:public Lens
{
	private:
		// Parameters of a SIE
		double b;
		double q;
		double xc;
		double yc;
		double theta;
		double shear;
		double thetaShear;
		double cosTheta, sinTheta,
			cosThetaShear, sinThetaShear;

	public:		
		SIE();

		// Generate from prior
		void fromPrior();

		// Deflection angles
		void alpha(double x, double y, double& ax, double& ay) const;

		// M-H proposals
		double perturb();

		// Print parameters
		void print(std::ostream& out) const;
};

#endif

