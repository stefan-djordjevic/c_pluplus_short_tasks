#include <iostream>
using namespace std;


//---------------------------------------------------------------------------------------------------
//Example of namespaces.

namespace first{
	int x = 1;
	int y = 8;
}

namespace second{
	double x = 1.14;
	double y = 8.23;
}


void example_Namespace(){

	using namespace first;

	cout << x << endl;
	cout << y << endl;
	cout << second::x << endl;
	cout << second::y << endl;

}