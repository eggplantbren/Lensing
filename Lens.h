#ifndef _Lens_
#define _Lens_

/*
* Base class for lens models.
*/

#include <ostream>
#include "Profile.h"
#include "MeshGrid.h"

class Lens:public Profile
{
	protected:
		// Parameters go here


	public:
		// Deflection angles
		virtual void alpha(double x, double y, double& ax, double& ay) const = 0;

		// Evaluate deflection angles on a grid
		void alphaGrid(const MeshGrid& grid, Array<double>& ax, Array<double>& ay) const;

		// Numerically evaluate the surface density
		double density(double x, double y, double h) const;

		// Numerically evaluate surface density on a grid
		Array<double> densityGrid(const MeshGrid& grid, double h) const;
};

#endif

