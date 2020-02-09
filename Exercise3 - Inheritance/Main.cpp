#include <iostream>
using namespace std;

#include "ClassParent.h"
#include "Class2Childs.h"
#include "ClassGrandchild.h"

int main(){

	Parent p(5,10);
	cout << "Parent x and z: " << p.getx() << ", " << p.getz() << endl;

	Child c(22);
	cout << "Child x, z, y: " << c.getx() << ", " << c.gety() << ", "<< c.getz() << endl;

	c.func();
	cout << "Child x, z, y after function call: " << c.getx() << ", " << c.gety() << ", " << c.getz() << endl;

	Parent pa(c);	//initialization of base class object by derived class object 
	cout << "Parent x and z by child object: " << pa.getx() << ", " << pa.getz() << endl;


	cin.sync();
	cin.ignore();

	return 0;
}