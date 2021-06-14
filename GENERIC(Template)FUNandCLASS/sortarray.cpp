#include <iostream>
#include "sortarray.h"
#include "arrayfusion.h"	//including classes Point and Rectangle 
using namespace std;

//...............................................................................................................................
//Use generic function to sort array in ascending or descending order;
//Program with generic function should be able to sort arrays of:
//		- whole numbers by their value
//		- points in the plane by their distance from coordinate beginning
//		- rectangles by their area;


//template function for execution
template <typename T>
	void execcute(const char* title)
	{
		cout << "\n" << title << "\n\n";
		//array input:
		int n;
		cout << "Enter size of array: ";
		cin >> n;
		T* a = new T[n];
		cout << "Enter array elements: ";
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << endl;
		//sorting array in ascending order
		Sort<T, Asc<T>>::sort(a, n);
		cout << "Array in ascending order: ";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
		//sorting array in descending order
		Sort<T, Desc<T>>::sort(a, n);
		cout << "Array in descending order: ";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
		//deallocation
		delete[] a;
	}


void sort_array()
{
	execcute<int>("SORTING ARRAY OF INTEGER NUMBERS:");
	execcute<Point>("SORTING ARRAY OF POINTS:");
	execcute<Rectangle>("SORTING ARRAY OF RECTANGLES:");
}