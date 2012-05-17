#include <iostream>
#include <Lenses/SIE.h>
#include <Grid.h>

using namespace std;

int main()
{
	SIE sie;
	Grid grid(1000, 1000, -1., 1., -1., 1.);
	Array ax, ay;
	sie.alphaGrid(grid, ax, ay);
	cout<<ax<<endl;
	cout<<ay<<endl;
	return 0;
}

