#include <iostream>		//preprocessor directive
using namespace std;

#include "Declarations.h"	//preprocessor directive

#define MAX 100		//MAX is macro, that all is macro-definition	//preprocessor directive

//main program

int main() {

	char slovo = 'A';
	cout << (int)slovo << endl;	//ASCII code for letter "A"
	cout << static_cast<int>(slovo) << endl;	//this is the better way for explicit type conversation

	unsigned short int x;
	cout << sizeof(x) << endl;	//2 byte, only positive number (0 - 4294967296)
	
	typedef int broj;	//new name for built-in or used-defined type
	broj y;
	cout << sizeof(y) << endl;

	z = 5.2;	//declaration of variable "z" is in header file "Declarations.h" 
	cout << z << endl;

	int a = 3;
	float b = 0.5;
	int c = a*b;
	cout << (a*b) << endl;
	cout << c << endl;

	int i = 0;
	cout << (++i) << endl;
	cout << (i++) << endl;

	int d = 4;
	d += 5;
	cout << "d is: " << d <<"\n"<< endl;

	//scope
	int e = 5;
	{
		int e = 1;
		cout << e << endl;
	}
	cout << e << endl;

	
	//for - iteration statement
	int j;
	for (j = 50; j >= -50; j -= 10){
		if (j > -50)
			cout << j << ", ";
		else
			cout << j;
	}
	cout << endl;

	
	//Sum function call 
	int sum(int, int);	//declaration of the function must exists in this file because in this file we call that function
						//definition of the function is in the file "Functions.cpp"
	int f;
	f = sum(100, 50);	//function call
	cout << "Sum = " << f << endl;


	//Output function call
	void output();

	output();
	output_2();	//it's declaration is in header file "Declarations.h" and it's definition is in file "Functions.cpp"


	//Recursive function call
	int sum_n;
	int n = 3;
	sum_n = recursive_f(n);
	cout << "Sum of n = " << n << " natural numbers: " <<sum_n<< endl;


	//function overloading call
	int g = 2;
	float h = 2.64;

	samename(g);	//the compiler calls function samename(int a)
	samename(h);	//the compiler calls function samename(float a)

	//pointer
	int k=88, l;
	int *pk;	//declaration of pointer pk which points to type int 
	pk = &k;	//pointer pk has address of variable k and that means that pk points to k 
	l = *pk;	//variable l has value from address k which is pointed by pointer pk
	cout << l << endl;

	//null pointer
	double *pl;
	pl = NULL;
	if (!pl)
		cout << "pl points to nothing." << endl;

	//generic ppointer
	void *pm; //it's good for formal arguments in functions

	//reference
	int m;
	int &rm = m;	//declaration of reference rm
	rm = 952;		//rm is another name for variable m
	cout << m << endl;


	//arrays
	int arr[3] = { 3, 2, 1 };
	
	cout << "Array: ";
	for (int i = 0; i < 3; ++i){
		cout << arr[i] <<" ";
	}

	cout << endl;

	//unsized array
	int arr2[] = { 1, 2, 3 };
	
	for (int i = 0; i < 3; ++i){
		cout << arr2[i] << " ";
	}

	//array with more dimensions
	int arr3[2][3] = { { 4, 5, 6 }, 
					   { 4, 4, 4 } };

	cout << endl;

	for (int i = 0; i < 2; ++i){
		for (int j = 0; j < 3; ++j){
			cout << arr3[i][j] << " ";
		}
		cout << endl;
	}


	//index of array 
	int arr4[5] = {1, 2, 3, 4, 5};
	
	arr4[2] = 0;
	
	for (int i = 0; i < 5; ++i){
		cout << arr4[i] << " ";
	}
	
	cout << endl;

	//array and pointer
	int *p_arr4;
	p_arr4 = arr4;	//pointer which points to the first element of array arr4[0]

	cout << *(p_arr4 + 2) << endl;	//access to the third element of array by pointer

	
	//arrays and functions
	int f_array(int *, int *);
	int f_array_2(int[], int[]);	//declarations of functions, their definitions are in the file "Functions.cpp"

	int an[4] = { 5, 6, 7, 8 };
	int am[2] = { 2, 3 };
	int rez;

	rez = f_array(an, am);
	cout << rez << endl;

	rez = f_array_2(an, am);
	cout << rez << endl;


	//dynamic memory allocation
	int* pd = new int;	//dynamically created uninitialized variable
	*pd = 5;
	int num = *pd;
	cout << num << *pd << endl;

	int* pdyn = new int(12);	//dynamically created initialized variable

	float* pad = new float[10];	//dynamically created one-dimensional array
	pad[0] = 1;
	pad[1] = 2;
	pad[2] = 3;
	pad[9] = 4;

	float (*ppad)[3] = new float[2][3];	//dynamically created two-dimensional array
	ppad[0][2] = 8;

	//dynamic memory deallocation
	delete pd;
	delete pdyn;
	delete[] pad;
	delete[] ppad;


	//string
	void string_like_array_cin();	//declarations
	void string_like_array_gets();
	void string_from_library();

	//string_like_array_cin();	//functions call
		cout << endl;
	//string_like_array_gets();
		cout << endl;
	//string_from_library();
		cout << endl;


	//structure
	point aa = { 2.4, 6.1 };	//this is a variable that has a structure type "point", with initialization
	aa.x = 3.4;					//the definition of the structure is in the header file 
	cout << "Point aa(" << aa.x << ", " << aa.y << ")" << endl;


	//macro-definition
	int mac = MAX;		//MAX is a name for 100
	cout << mac << endl;

	//system's macro
	cout << "This program was executed on " << __DATE__ << " at " << __TIME__ << endl;
		

	system("pause");	//pause console

	return 0;
}