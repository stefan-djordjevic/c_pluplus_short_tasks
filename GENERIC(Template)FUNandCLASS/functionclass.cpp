#include <iostream>
#include <cmath>
using namespace std;

#include "functionclass.h"

//...............................................................................................................................
//Function class like parameter of template - damped oscillations

void funclass_dumpedoscillations()
{
	double xmin = 0., xmax = 6.28, dx = 0.314;

	//- generic function call
	table(Oscillations<double>(), xmin, xmax, dx);
	cout << endl << endl;

	//- generic class method call
	Table<Oscillations<double>, double> tab;
	tab.table(xmin, xmax, dx);
}