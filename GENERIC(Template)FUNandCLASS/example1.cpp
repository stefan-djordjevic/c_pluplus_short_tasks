#include <iostream>
using namespace std;

#include "example1.h"

//...................................................
//1.1 Generic function - the largest of two elements

void example_1_1()
{
	int num1, num2, max;

	cout << "Enter two numbers: ";
	cin >> num1 >> num2;

	max = max_el<int>(num1, num2);		//implicit call of function generated of generic function
	cout << "\nThe largest number is: " << max << endl;

	max = max_el(num1, num2);			//automatic deduce about parameters type based on arguments type
	cout << "The largest number is: " << max << endl;

	cout << endl;
}


//...................................................
//1.2 Generic function - array print

void example_1_2()
{
	const int n = 6;
	
	double arr[n] = { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6 };
	char carr[] = "Stefan";
	
	print_array<double>(arr, n);
	cout << endl;
	print_array<char>(carr, n);
	cout << endl << endl;
}


//..................................................
//1.3 Generic class - generating static array

void example_1_3()
{
	Vect<int, 10> vect1;				//Vect class object that contains array of 10 integer type elements
	
	//fill in array
	for (int i = 0; i < 10; i++)
	{
		vect1[i] = i + 1;
	}

	//print array
	for (int i = 0; i < 10; i++)
	{
		cout << vect1[i] << " ";
	}
	cout << endl;

	//empty array
	vect1.empty();

	//print array
	for (int i = 0; i < 10; i++)
	{
		cout << vect1[i] << " ";
	}
}


//..................................................
//1.4 Generic class - generating static array (default parameters and typedef)

void example_1_4()
{
	Vecto<>			vecto1;				//Vect class object that contains array of 5 double type elements
	Vecto<char>		vecto2;				//Vect class object that contains array of 5 char type elements
	Vecto<char, 15> vecto3;				//Vect class object that contains array of 15 char type elements

	//.   .   .   .   .   .   .   .   .

	for (int i = 0; i < 5; i++)
	{
		vecto1[i] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << vecto1[i] << " ";
	}
	cout << endl;
	//.   .   .   .   .   .   .   .   .

	for (int i = 0; i < 5; i++)
	{
		vecto2[i] = i + 49;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << vecto2[i] << " ";
	}
	cout << endl;
	//.   .   .   .   .   .   .   .   .

	for (int i = 0; i < 15; i++)
	{
		vecto3[i] = i + 49;
	}

	for (int i = 0; i < 15; i++)
	{
		cout << vecto3[i] << " ";
	}
	cout << endl;
	//.   .   .   .   .   .   .   .   .

	typedef Vecto<int, 3> Vi3;				//another name for class type Vecto<int, 3>

	Vi3 vecto4;

	for (int i = 0; i < 3; i++)
	{
		vecto4[i] = i + 1;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << vecto4[i] << " ";
	}
	cout << endl << endl;
}


//..................................................
//1.5 Generic function - delayed function type specifing

void example_1_5()
{
	double a = 3.45;
	int b = 4;

	auto c = sum<double, int>(a, b);

	cout << c << endl;
}