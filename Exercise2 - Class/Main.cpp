#include <iostream>
using namespace std;

#include <cstdlib>

#include "Class_test.h"
#include "Class_task.h"
#include "Class_task2.h"
#include "Class_task_copy.h"


int test::sqrt(int third)		//the outer definition of the class function	//it's made by scope operator "::"
{
	return third * third;
}

int main(){

	test a;		//the object of class type "test"		//the definition of the class is in the header file "Class_test.h"
	
	a.first = 3;
	a.second = 5;

	a.print();	//class function call

	int sum_res;
	sum_res = a.sum();
	cout << "Sum value: " << sum_res << endl;

	int sqrt_res;
	sqrt_res = a.sqrt(4);
	a.print_v(sqrt_res);	//class function call with parameters

	
	
	test b;		//the object of class type "test"	//the default constructor is called
	
	b.print_v(b.getZero());
	b.print_v(b.getNull());
	
	
	test c(10, 10);		//the object of class type "test"	//the switched constructor is called
	
	c.print_v(c.getZero());
	c.print_v(c.getNull());


	test d(10, 10);
	
	d.first=3;
	d.second = 5;
	int sum_all;
	sum_all = d.sum2();
	d.print_v(sum_all);

	//-----------------------------------------------------------------

	Task ta;
	cout << "task ta: " << ta.getx() << ", " << ta.gety() << endl;

	Task tb(5, 7);
	cout << "task tb: " << tb.getx() << ", " << tb.gety() << endl;

	tb.setx(15);
	tb.sety(17);
	cout << "task tb: " << tb.getx() << ", " << tb.gety() << endl;

	const Task cta;		//the constant object of the class "Task"
	int v = cta.getx();	//const function call for const object
	cout << v << endl;

	Task::printz();		//static class function call	//no need for object when making a call
	

	//--------------------------------------------------------------------------------------------------
	//friend class and function

	Task tf(4,4);
	Task2 t2;

	t2.print_friend(tf);	//friend class function call


	void set_friend_global(Task2 &, int);	//the declaration of the friend global function
	set_friend_global(t2, 99);				//friend global function call


	//-------------------------------------------------------------------------------------------------
	//copy constructor - SHALLOW COPY (public copy constructor)
	Task tf_c(tf);
	cout << "Copy task tf_c: " << tf_c.getx() << ", " << tf_c.gety() << endl;


	//-------------------------------------------------------------------------------------------------
	//copy constructor - DEEP COPY (user defined)
	
	TaskCopy tc;
	TaskCopy tc2(32);
	TaskCopy tc_c(tc2);		//copy constructor call - deep copy


	//-------------------------------------------------------------------------------------------------
	//inner class
	Task2 ta2(22, 22);
	Task2::Inner in;

	in.h = 90;
	
	in.innerf(ta2);
	t2.task2f(in);

	
	//-------------------------------------------------------------------------------------------------
	//class members pointers
	Task2 obj;
	
	int Task2::*pk = &Task2::k;		//class attribute pointer
	obj.*pk = 425;
	cout << "Value k by class member pointer: " << obj.k << endl;

	void (Task2::*pfunc)(int);		//class function pointer
	pfunc = &(Task2::func);
	(obj.*pfunc)(50);

	//-------------------------------------------------------------------------------------------------


	//cin.sync();
	//cin.ignore();
	system("pause");

	return 0;
}



//=======================================================================================================
//GLOBAL FUNCTIONS DEFINITIONS

void set_friend_global(Task2 &t, int a)		//the definition of the friend global function
{
	t.e = a; t.f = a;
	cout << "e and f by global friend function: " << t.e << ", " << t.f << endl;
}