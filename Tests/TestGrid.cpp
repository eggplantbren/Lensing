#include <iostream>
#include <Grid.h>

using namespace std;

int main()
{
	Grid g(100, 100, -1., 1., -1., 1.);
	g.print(cout);
	return 0;
}

