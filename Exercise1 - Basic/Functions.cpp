#include <iostream>
using namespace std;

#include <cstdlib>	//system header file for function exit()
#include <cstdio>	//contains string function gets_s()
#include <string>

//function "sum"
int sum(int a, int b)
{
	return a+b;
}


//function "output"
//function with no return value
void output()
{
	cout << "Everything's gonna be alright." << endl;
}

void output_2()
{
	cout << "Be sure!" << endl;
}


//recursive function
//sum of natural numbers
int recursive_f(int n)
{
	if (n < 1) return 0;	//end condition for recursion

	return n + recursive_f(n - 1);
}

//function overloading
void samename(float a)
{
	cout << a << endl;
	//exit(0);
}

void samename(int a)
{
	cout << a << endl;
}


//arrays and functions
int f_array(int *p, int *p_1)
{
	return p[0]+p_1[0];
}

int f_array_2(int p[], int p_1[])	//same as the first way
{
	return p[0] + p_1[0];
}


//string
void string_like_array_cin()
{
	char str[256];
	cout << "Enter your name and surname: ";
	cin >> str;	//reads until white space
	cout << "Your name and surname are: " << str;

	cin.sync();
}

void string_like_array_gets()
{
	char str[256];
	cout << "Enter your name and surname: ";
	gets_s(str);	//reads until new line   //gets_s() function is from library <cstdio>  //gets() is unsafe!!!
	cout << "Your name and surname are: " << str;

	cin.sync();
}

void string_from_library()
{
	string name, surname;		// type "string" from lybrary <string>
	string str;

	cout << "Enter your name and surname: ";
	cin >> name >> surname;	//function gets_s() is only for char array!!!
	cout << "Your name and surname are: " << name << " " << surname;
	cin.sync();

	cout << endl;

	cout << "Enter your name and surname: ";
	getline(cin, str);	//function from library <string>
	cout << "Your name and surname are: " << str;
	cin.sync();

}


