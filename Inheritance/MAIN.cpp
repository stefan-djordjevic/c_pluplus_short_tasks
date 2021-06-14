#include <iostream>
using namespace std;

#include "classes.h"

int main()
{
	base b(1, 2);
	b.print();
	cout << endl;

	derivedOne d1(5);
	d1.print();
	cout << endl;

	derivedOne d11(d1);
	d11.print();
	cout << endl;

	void func(const base &);
	func(d1);
	cout << endl;

	base c(d1);
	c.print();
	cout << endl;

	d1.sety_derived(22);
	d1.print();
	cout << endl;

	//grandchild g;
	//g.derivedOne::z = 88;
	grandchild g(3);
	g.z = 88;
	g.f();

	cout << "\nPress enter to exit...";
	cin.sync();
	cin.ignore();

	return 0;
}

void func(const base &b)
{
	b.print();
}
