#ifndef _Lens_
#define _Lens_

/*
* Base class for lens models.
*/

#include <ostream>
#include "Profile.h"

class Lens:public Profile
{
	protected:
		// Parameters go here


	public:
		// Deflection angles
		virtual void alpha(double x, double y, double& ax, double& ay) const = 0;		

		// Evaluate deflection angles on a grid
		void alphaGrid(const Grid& grid, Array& ax, Array& ay) const;
};

#endif

