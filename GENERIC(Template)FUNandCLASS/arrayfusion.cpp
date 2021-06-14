#include <iostream>
#include "arrayfusion.h"
using namespace std;

//...............................................................................................................................
//Use generic function to merge two ordered arrays into a third, same ordered, array;
//Program with generic function should be able to merge arrays of:
//		- whole numbers ordered by their value
//		- points in the plane ordered by their distance from coordinate beginning
//		- rectangles ordered by their area;


//template function for execution
template <typename T>
	void execute(const char* title)
	{
		cout << "\n" << title << "\n\n";
		//first array input:
		int na;
		cout << "Enter size of first array: ";
		cin >> na;
		T* a = new T[na];
		cout << "Enter first array elements: ";
		for (int i = 0; i < na; i++)
			cin >> a[i];
		cout << endl;
		//second array input:
		int nb;	
		cout << "Enter size of second array: ";
		cin >> nb;
		T* b = new T[nb];
		cout << "Enter second array elements: ";
		for (int i = 0; i < nb; i++)
			cin >> b[i];
		cout << endl;
		//fusion into third array:
		int nc;
		T* c;
		fusion<T>(a, na, b, nb, c, nc);
		cout << "Fusion: ";
		for (int i = 0; i < nc; i++)
			cout << c[i] << " ";
		cout << endl;
		//deallocation
		delete[] a; delete[] b; delete[] c;
}


void array_fusion()
{
	execute<int>("FUSION OF ARRAYS OF INTEGERS:");
	execute<Point>("FUSION OF ARRAYS OF POINTS:");
	execute<Rectangle>("FUSION OF ARRAYS OF RECTANGLES:");
}