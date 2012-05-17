#include <iostream>
#include <Lenses/SIE.h>
#include <Grid.h>

using namespace std;

int main()
{
	SIE sie;
	Grid grid(1000, 1000, -1., 1., -1., 1.);
	Array ax(1000, 1000), ay(1000, 1000);
	sie.alphaGrid(grid, ax, ay);
	ax.print(cout);
	ay.print(cout);
	return 0;
}

