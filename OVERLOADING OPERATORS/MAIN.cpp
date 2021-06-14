#include <iostream>
using namespace std;

#include "e1Complex.h"

int main()
{
	//-------------------------------------
	//Example 1

	Complex c1;
	c1.print();

	c1.setImag(4);
	c1.print();

	cout << c1.getImag() << endl;

	c1.setCmplx(2, 4);
	c1.print();

	Complex c2(1, 1);
	c2.print();

	Complex c3, c4;
	c3 = ~c1;
	c3.print();

	c4 = c3 + c2;
	c4.print();

	c4 = 0 + c2;
	c4.print();

	c4 = c3 - c2;
	c4.print();

	c4 = 0 - c2;
	c4.print();

	c4 = c3 * c2;
	c4.print();

	c4 = c2 * 55;
	c4.print();

	c4 = c3 / c2;
	c4.print();

	c4 = 0 / c2;
	c4.print();

	cout << abs(c2) << endl;

	
	//-------------------------------------
	//Example 2


	cout << "\nPress enter to exit...";
	cin.sync();
	cin.ignore();

	return 0;
}