#include <iostream>
using namespace std;



//---------------------------------------------------------------------------------------------------
//The reversed array (reverse order).

void reverse_array(){

	int n;

	cout << "Enter the array size: n= ";
	cin >> n;

	double* a = new double[n];

	cout << "\nEnter the values of the array elements:" << endl;

	for (int i = 0; i < n; i++){
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}

	cout << "\nThe entered array: ";

	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}

	int i, j;
	double temp;

	for (i = 0, j=n-1; i < j; i++, j--){
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	cout << "\n\nEntered array reversed: ";

	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}

	delete[] a;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//The reversed array (reverse order) - using pointers.

void reverse_array_viaPointers()
{
	int n;

	cout << "Enter the array size: n= ";
	cin >> n;

	double* a = new double[n];

	cout << "\nEnter the values of the array elements:" << endl;

	for (int i = 0; i < n; i++){
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}

	cout << "\nThe entered array: ";

	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}

	int i, j;
	double temp;
	double *pOne = &a[0];
	double *pTwo = &a[n-1];

	for (i = 0, j = n - 1; i < j; i++, j--){
		temp = *pOne;
		*pOne = *pTwo;
		*pTwo = temp;
		pOne++;
		pTwo--;
	}

	cout << "\n\nEntered array reversed: ";

	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}

	delete[] a;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Merge two non-decreasing arrays into one non-decreasing array.

void two_arrays_into_nondecreasing_Third_(){

	unsigned na, nb, nc;

	cout << "Enter a size of array A: ";
	cin >> na;

	int* a = new int[na];

	cout << "Enter elements value of array A: ";
	for (int i = 0; i < na; i++){
		cin >> a[i];
	}

	cout << "\nEnter a size of array B: ";
	cin >> nb;

	int* b = new int[nb];

	cout << "Enter elements value of array B: ";
	for (int i = 0; i < nb; i++){
		cin >> b[i];
	}

	int* c = new int[na + nb];

	//. . . . . . . . . . . . . . . . . . . . . .

	int i = 0, j = 0, k = 0;

	while (i < na && j < nb){
		c[k++] = a[i] < b[j] ? a[i++] : b[j++];
	}

	//add the rest of array a or array b (depends on whose size is larger)
	while (i < na){
		c[k++] = a[i++];
	}

	while (j < nb){
		c[k++] = b[j++];
	}


	cout << "\n\nTwo arrays merged into one non-decreasing array: " << endl;
	for (int i = 0; i < k; i++){
		cout << c[i] << " ";
	}


	delete[] a, b, c;

}


//---------------------------------------------------------------------------------------------------
//BUBBLE SORT- Sort an array in ascending order using bubble sort and print array after each sort.

void bubble_sort()
{
	int n, temp;

	cout << "Enter the array size: ";
	cin >> n;

	int *a = new int[n];

	cout << "\nEnter array elements:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "\nSorting the array using bubble sort technique..." << endl;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		//.................................
		cout << "Step " << i + 1 << ": ";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}

	cout << "\nArray sorted successfully!" << endl;
	cout << "\nThe new array is:\n" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	delete[] a;
}


//---------------------------------------------------------------------------------------------------
//SELECTION SORT- Sort an array in ascending order using selection sort and print array after each sort.

void selection_sort()
{
	int n, temp, min, index;
	bool con;

	cout << "Enter the array size: ";
	cin >> n;

	int *a = new int[n];

	cout << "\nEnter array elements:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "\nSorting the array using selection sort technique..." << endl;

	for (int i = 0; i < n - 1; i++)
	{
		con = false;
		min = a[i];
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				index = j;
				con = true;
			}
		}

		if (con)
		{
			temp = a[i];
			a[i] = min;
			a[index] = temp;
		}
		//.............................
		cout << "Step " << i + 1 << ": ";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}

	cout << "\nArray sorted successfully!" << endl;
	cout << "\nThe new array is:\n" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	delete[] a;
}


//---------------------------------------------------------------------------------------------------
//INSERTION SORT- Sort an array in ascending order using insertion sort and print array after each sort.

void insertion_sort()
{
	int n, current, index;
	bool con;

	cout << "Enter the array size: ";
	cin >> n;

	int *a = new int[n];

	cout << "\nEnter array elements:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "\nSorting the array using insertion sort technique..." << endl;

	for (int i = 1; i < n; i++)
	{
		current = a[i];
		if (current < a[i - 1])
		{
			for (int j = 0; j <= i; j++)
			{
				if (current < a[j])
				{
					index = j;
					for (int k = i; k > j; k--)
					{
						a[k] = a[k - 1];
					}
					break;
				}
			}
		}
		else
			continue;

		a[index] = current;

		//......................................
		cout << "Step " << i << ": ";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}

	cout << "\nArray sorted successfully!" << endl;
	cout << "\nThe new array is:\n" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	delete[] a;
}