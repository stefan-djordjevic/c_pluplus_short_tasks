#include <iostream>
using namespace std;


template <class F, typename T>
void table(F f, T xmin, T xmax, T dx)				//generic function definition
{
	for (T x = xmin; x <= xmax; x += dx)
		cout << x << "\t" << f(x) << endl;
}


int main()
{
	//--------------------------------------------------------------------------------------------------------------	
	//Task 1 - Lambda expression - EXAMPLE
	
	auto lam = [](int x, double y) -> double {return x + y; };		//definition of lambda expression(function)

	int a = 1;
	double b = 2.2;
	double p = lam(a, b);		//lambda function call

	cout << p << endl;


	//--------------------------------------------------------------------------------------------------------------	
	//Task 2 - Lambda expression
	//- USING AS AN ARGUMENT IN GENERIC FUNCTION WHICH EXPECTS FUNCTION OBJECT OF CERTAIN TYPE LIKE ARGUMENT
	//- (Lambda expression instead of function object)

	double xmin = 0., xmax = 6.28, dx = 0.314;
	table([](double x){return exp(-0.1*x)*sin(x); }, xmin, xmax, dx);


	cout << "\nPress enter to exit...";
	cin.sync();
	cin.ignore();
	return 0;
}