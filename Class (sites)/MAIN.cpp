#include <iostream>
using namespace std;

#include "classes.h"

int main()
{
	//EXAMPLE 1..............................
	Rectangle r(2,3), q(r);
	q.setWidth(5);
	q.printArea();
	cout << endl;
	//***class and pointers
	Rectangle *pr, *prec;
	pr = &r;
	prec = new Rectangle(5, 6);
	r.printArea();
	pr->printArea();
	prec->printArea();
	delete prec;
	cout << endl;
	//***friend class
	Rectangle rec;
	Square s(5);
	rec.convert(s);
	rec.printArea();
	cout << endl;

	//EXAMPLE 2..............................
	Circle c(3);
	c.printArea();
	cout << endl;
	//***
	Cylinder cyl(0,4), cil(cyl);
	cil.setR(3);
	cil.printVolume();
	cout << endl;

	//EXAMPLE 3..............................
	Rectanglle k(2, 6);
	Triangle t(3, 6);
	k.setWidth(3);
	k.printArea();
	t.printArea();
	cout << endl;

	//EXAMPLE 4..............................
	Polygonn pol;
	Rectangllee tan(4,5);
	Trianglee tri(4, 5);
	tan.printArea();
	tri.printArea();
	cout << endl;
	//***polymorphic class
	Polygonn* ppol1 = &pol;
	Polygonn* ppol2 = &tan;
	Polygonn* ppol3 = &tri;
	ppol1->printArea();
	ppol2->printArea();
	ppol3->printArea();
	cout << endl;
	//***abstract class
	Recctangllee tang(5, 8);
	Triannglee tria(5, 8);
	Pollygonn* ppoly1 = &tang;
	Pollygonn* ppoly2 = &tria;
	ppoly1->printArea();
	ppoly2->printArea();


	cout << "\nPress enter to exit...";
	cin.sync();
	cin.ignore();

	return 0;
}