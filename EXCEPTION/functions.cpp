#include <iostream>
#include <stdio.h>
#include <exception>
using namespace std;

//----------------------------------------------------------------------------
//Exception handling example: explaination of flow of execution of try/catch blocks
//codescracker.com/tutorials

void example_1()
{
	int num;

	cout << "Enter a positive number: ";
	cin >> num;

	cout << "\nBefore try" << endl;

	try {
		cout << "Inside try" << endl;
		if (num < 0)
		{
			throw num;
			cout << "After throw (never executed)" << endl;
		}
	}
	catch (int num) {
		cout << "Exception caught" << endl;
	}

	cout << "After catch (will be executed)" << endl;
}


//----------------------------------------------------------------------------
//Exception handling example: how special catch(...) block work
//geeksforgeeks.com/tutorials

void example_2()
{
	try {
		throw 10;
	}
	catch (char *excp) {
		cout << "Caught " << excp << endl;
	}
	catch (...)	{										//this catch block can be used to catch all types of exceptions;													//an int is thrown as an exception, but there is no catch block
		cout << "Default Exception" << endl;			//for int, so catch(...) block will be executed;
	}
}


//----------------------------------------------------------------------------
//Exception handling example: when an exception is thrown, but there is no catch block to catch
//geeksforgeeks.com/tutorials

void example_3()
{
	try {
		throw 'a';								//if an exception is thrown and not caught anywhere,
	}											//the program terminates abnormally;
	catch (int x) {
		cout << "Caught " << x << endl;
	}
}


//----------------------------------------------------------------------------
//Exception handling example: specify the exceptions that function throws 
//geeksforgeeks.com/tutorials

void example_4()
{
	void func(int *, int) throw (int *, int);

	try	{
		func(NULL, 0);								//constant NULL from header <stdio.h>
	}
	catch (...) {
		cout << "Caught exceptions from func()" << endl;
	}
}

void func(int *ptr, int x) throw (int *, int)		//without throw, function signature will be fine by the compiler
{													//but not recomended; ideally, the function should specify all
	if (ptr == nullptr)								//uncaught exceptions;
		throw ptr;									//if signature throw() is without parameters, than function can't
													//throw any exception !!!
	if (x == 0)
		throw x;
}


//----------------------------------------------------------------------------
//Exception handling example: specify whether function throw an exception or not - noexcept()
//better than func() throw(<without parameters>) !!!
/*
void example_5()
{
	void funct(int) noexcept;

	try {
		funct(2);
	}
	catch (int x) {
		cout << "Caught exception from funct: " << x << endl;
	}
}

void funct() noexcept					//function can't throw an exception
{
	throw x;
}
*/ //DOESN'T WORK !!!

//----------------------------------------------------------------------------
//Exception handling example: nested try-catch blocks and re-throwned exceptions
//geeksforgeeks.com/tutorials

void example_6()
{
	try {
		try {											//try-catch blocks an be nested, also an exception
			throw 20;									//can be re-thrown using "throw" !!!
		}
		catch (int n) {
			cout << "Handle Partially" << endl;
			throw;	//Re-throwing an exception
		}
	}
	catch (int n) {
		cout << "Handle remaining" << endl;				//to be able this catch block to catch an exception
	}													//that exception must be re-trown in nested try-catch block;
}


//----------------------------------------------------------------------------
//Exception handling example: objects created inside try block
//geeksforgeeks.com/tutorials

class Test {
public:
	Test() { cout << "Constructor of Test" << endl; }
	~Test() { cout << "Destructor of Test" << endl; }
};

void example_7()
{
	try {
		Test t; 
		throw 10;							//when an exception is thrown, all objects created inside the enclosing
	}										//try block are destructed before the control is transferred to catch block;
	catch (int n) {
		cout << "Caught " << n << endl;
	}
}


//----------------------------------------------------------------------------
//Exception handling example: stack unwinding
//geeksforgeeks.com/tutorials

void example_8()
{
	void f3();								//when exception occurs, the function call stack is linearly searched for
	f3();									//the exception handler, and all the entries before the function with
}											////exception handler are removed from the function call stack

void f1() throw(int)
{
	cout << "\nf1() Start" << endl;
	throw 100;								
	cout << "\nf1() End" << endl;			
}											

void f2() throw(int)
{
	cout << "\nf2() Start" << endl;
	f1();
	cout << "\nf2() End" << endl;
}

void f3()
{
	cout << "\nf3() Start" << endl;
	try {
		f2();
	}
	catch (int n) {
		cout << "\nCaught exception: " << n << endl;
	}
	cout << "\nf3() End\n" << endl;
}


//----------------------------------------------------------------------------
//Exception handling example: catching base and derived classes as exceptions
//geeksforgeeks.com/tutorials

class Base {};

class Derived : public Base {};

void example_9()
{
	Derived d;

	try {												//if both base and derived classes are caught as exception then
		throw d;										//catch block of derived class must appear before the base class
	}
	catch (Base b) {									//if we put base class first then the derived class catch block 
		cout << "Caught Base exception" << endl;		//will never be reached
	}
	catch (Derived d) {									//this catch block is never executed !!!
		cout << "Caught Derived exception" << endl;
	}

	//....................................

	try {												//in this order of catch blocks, both catch blocks become reachable
		throw d;
	}
	catch (Derived d) {
		cout << "\nCaught Derived exception\n" << endl;
	}
	catch (Base b) {
		cout << "Caught Base exception" << endl;
	}
}


//----------------------------------------------------------------------------
//Exception handling example: explaination of flow of execution of try/catch blocks

void example_10()
{
	try {
		int age = 15;
		if (age >= 18) {
			cout << "Access granted - you are old enough.";
		}
		else {
			throw (age);
		}
	}
	catch (int myNum) {
		cout << "Access denied - You must be at least 18 years old.\n";
		cout << "Age is: " << myNum;
	}
}