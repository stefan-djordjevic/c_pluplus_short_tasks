#include <iostream>
using namespace std;

#include "Classes.h"
#include "Classes2.h"

int main()
{
	//----------------------------------------------------------------------------------------
	//POLYMORPHISM AND VIRTUAL FUNCTIONS

	cout << "TEST_1:" << endl;

	Player p;		//object of base class type
	CD_player c;	//object of derived class type

	test(p);
	test(c);		//virtual and override functions enable dynamic binding (late binding)



	//----------------------------------------------------------------------------------------
	//ABSTRACT CLASS AND PURE VIRTUAL FUNCTIONS

	cout << endl;
	cout << "TEST_2:" << endl;
	
	Sony_player sp;		//it's not allowed to make object of pure and non-pure abstract classes type

	test2(sp);


	cin.sync();
	cin.ignore();

	return 0;

}