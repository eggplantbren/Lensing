#include <iostream>
#include <MeshGrid.h>

using namespace std;

int main()
{
	MeshGrid g(100, 100, -1., 1., -1., 1.);
	g.print(cout);
	return 0;
}

