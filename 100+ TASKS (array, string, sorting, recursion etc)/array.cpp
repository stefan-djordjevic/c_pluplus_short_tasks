#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;


//---------------------------------------------------------------------------------------------------
//The min and max element of an array.

void min_max_Array(){

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

	double min, max;
	min = max = a[0];

	for (int i = 0; i < n; i++){
		if (min>a[i])
			min = a[i];
		else if (max < a[i])
			max = a[i];
	}

	cout << "\n\nThe MIN array element = " << min;
	cout << "\nThe MAX array element = " << max;

	delete[] a;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//The min and max element of an array - alternative way

void min_max_Array_alternative(){

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

	double min, max;
	bool con = true;

	for (int i = 0; i < n; i++){

		if (con){
			min = max = a[i];
			con = false;
			continue;
		}

		if (min>a[i])
			min = a[i];
		else if (max < a[i])
			max = a[i];
	}

	cout << "\n\nThe MIN array element = " << min;
	cout << "\nThe MAX array element = " << max;

	delete[] a;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Intersection, union and difference two entered arrays.

void intersection_union_difference_Arrays(){

	int na, nb;
	void input_Array(int*, int, char);

	cout << "Enter two arrays.\n\n" << endl;

	cout << "Enter a size of array a: ";
	do{
		cin >> na;
		if (na > 100) cout << "Array size must be less than or equal 100. Try again.\n" << endl;
	} while (na > 100);

	int* a = new int[na];

	//Array a elements input
	input_Array(a, na, 'a');


	cout << "\n\nEnter a size of array b: ";
	do{
		cin >> nb;
		if (nb > 100) cout << "Array size must be less than or equal 100. Try again.\n" << endl;
	} while (nb > 100);

	int* b = new int[nb];

	//Array b elements input
	input_Array(b, nb, 'b');


	//.......... Intersection ..........

	int n_min = (na < nb) ? na : nb;
	int n_sarr = 0;

	int* sarr = new int[n_min];

	for (int i = 0; i < na; i++){
		for (int j = 0; j < nb; j++){
			if (a[i] == b[j]){
				sarr[n_sarr++] = a[i];
				break;
			}
		}
	}

	cout << "\n\nIntersection of two entered arrays is:\n" << endl;
	for (int i = 0; i < n_sarr; i++){
		cout << sarr[i] << " ";
	}


	//.......... Union ..........

	int n_max = na + nb;
	int n_uarr = 0;
	bool ucon;

	int* uarr = new int[n_max];

	for (int i = 0; i < na; i++){
		uarr[n_uarr++] = a[i];
	}
	for (int i = 0; i < nb; i++){
		ucon = true;
		for (int j = 0; j < na; j++){
			if (b[i] == a[j]){
				ucon = false;
				break;
			}
		}
		if (ucon) uarr[n_uarr++] = b[i];
	}

	cout << "\n\nUnion of two entered arrays is:\n" << endl;
	for (int i = 0; i < n_uarr; i++){
		cout << uarr[i] << " ";
	}


	//.......... Difference: a - b ..........

	int n_darr = 0;
	bool dcon;

	int* darr = new int[na];

	for (int i = 0; i < na; i++){
		dcon = true;
		for (int j = 0; j < nb; j++){
			if (a[i] == b[j]){
				dcon = false;
				break;
			}
		}
		if (dcon) darr[n_darr++] = a[i];
	}

	cout << "\n\nDifference of two entered arrays (a - b) is:\n" << endl;
	for (int i = 0; i < n_darr; i++){
		cout << darr[i] << " ";
	}


	delete[] a, b, sarr, uarr, darr;

}


void input_Array(int* arr, int n, char ch){

	bool error = false;

	cout << "\nEnter elements value of array " << ch << ": ";
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		for (int j = 0; j < i; j++){
			if (arr[i] == arr[j]){
				cout << "Two equal element values are not allowed. Try again.\n" << endl;
				error = true;
				break;
			}
		}
		if (error) break;
	}

	cin.ignore(80, '\n');

	if (error) input_Array(arr, n, ch);

	/*
	void inArray(int* arr, int n, char ch)
	{
		bool equal;
		for (int i = 0; i < n; i++){
			do{
				cout << ch << "[" << i << "]= ";
				cin >> arr[i];
				equal = false;
				for (int j = 0; j < i; j++){
					if (arr[i] == arr[j]){
						cout << "Equal elements.Try again." << endl;
						equal = true;
						break;
					}
				}
			} while (equal);
		}

	}
	*/
}

//other way - with function that testing whether value exists in array or not !!!
/*
int  exists_in_array(int* arr, int n, int val)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == val)
			return 1;
	return 0;
}
*/

//---------------------------------------------------------------------------------------------------
//Manipulation with array elements.

void array_Modification(){

	unsigned na;

	cout << "Enter a size of array A: ";
	cin >> na;

	int* a = new int[na + 1];

	cout << "Enter elements value of array A: ";
	for (int i = 0; i < na; i++){
		cin >> a[i];
	}

	//. . . . . . . . . . . . . . . . . . . . . .
	//Removing element from the entered position.

	int pos_d;
	cout << "\n\nEnter a position of the element you want to remove: ";
	cin >> pos_d;

	for (int i = pos_d; i + 1 < na; i++){						//To remove first element - for(int i = 0; i+1 < na; i++){
		a[i] = a[i + 1];
	}

	cout << "\nArray A after modification: ";
	for (int i = 0; i < na - 1; i++){
		cout << a[i] << " ";
	}

	//. . . . . . . . . . . . . . . . . . . . . .
	//Inserting new element into array on the entered position.

	na = na - 1;
	int pos_a, new_el;
	cout << "\n\nEnter a value of new element you want to insert: ";
	cin >> new_el;
	cout << "Enter its position: ";
	cin >> pos_a;

	for (int i = na; i > pos_a; i--){						//To add new element to the first position - for (int i = na; i > 0; i--){	
		a[i] = a[i - 1];
	}
	a[pos_a] = new_el;

	cout << "\nArray A after modification: ";
	for (int i = 0; i < na + 1; i++){
		cout << a[i] << " ";
	}

	//. . . . . . . . . . . . . . . . . . . . . .
	//Removing from array all elements with duplicate values - value is entered. 

	na = na + 1;
	int rep_el;
	cout << "\n\nEnter a value of element whose all occurrences you want to remove: ";
	cin >> rep_el;

	int i, j;
	for (i = 0, j = 0; i < na; i++){
		if (a[i] != rep_el){
			a[j++] = a[i];
		}
	}

	cout << "\nArray A after modification: ";
	for (int i = 0; i < j; i++){
		cout << a[i] << " ";
	}


	delete[] a;

}


//---------------------------------------------------------------------------------------------------
//Manipulation with array elements 2.

void array_Modification_2(){

	unsigned int na;

	cout << "Enter a size of array A: ";
	cin >> na;

	int* a = new int[na];

	cout << "Enter elements value of array A: ";
	for (int i = 0; i < na; i++){
		cin >> a[i];
	}

	//. . . . . . . . . . . . . . . . . . . . . .
	//Removing all multiple occurrences of the same element - all duplicates.

	int i, j, k;
	for (i = 0; i < na; i++){								//removing same element a[i] from the rest of the array
		for (j = i + 1, k = i + 1; j < na; j++){
			if (a[j] != a[i]){
				a[k++] = a[j];
			}
		}
		na = k;		// Attention ! ! !
	}

	cout << "\nArray A after removing all multiple occurrences of the same element:" << endl;;
	for (int i = 0; i < na; i++){
		cout << a[i] << " ";
	}

	//. . . . . . . . . . . . . . . . . . . . . .
	//Rotate all elements for k positions to the right

	int pos;

	cout << "\n\nEnter for how many positions you want to rotate the array: ";
	cin >> pos;

	int temp;
	for (int i = 0; i < pos; i++){			//pos times rotate by one position (repeat bellow pos times)					
		temp = a[na - 1];					//save the last element
		for (int j = na - 1; j > 0; j--){	//rotate all elements for one position to the right
			a[j] = a[j - 1];
		}
		a[0] = temp;						//The last put on first
	}

	cout << "\nArray A with all elements rotated for entered positions to the right: " << endl;
	for (int i = 0; i < na; i++){
		cout << a[i] << " ";
	}

	//. . . . . . . . . . . . . . . . . . . . . .
	//Rotate all elements for k positions to the left

	temp = 0;
	for (int i = 0; i < pos; i++){			//pos times rotate by one position (repeat bellow pos times)			
		temp = a[0];						//save the first element
		for (int j = 0; j < na - 1; j++){	//rotate all elements for one position to the left
			a[j] = a[j + 1];
		}
		a[na - 1] = temp;					//The first put on last
	}

	cout << "\n\nNew array with all elements rotated for entered positions to the left: " << endl;
	for (int i = 0; i < na; i++){
		cout << a[i] << " ";
	}

	delete[] a;

}


//---------------------------------------------------------------------------------------------------
//Scanning array.

void array_Scanning(){

	unsigned int na;
	int num;

	cout << "Enter a size of array A: ";
	cin >> na;

	int* a = new int[na];

	cout << "Enter elements value of array A: ";
	for (int i = 0; i < na; i++){
		cin >> a[i];
	}

	//. . . . . . . . . . . . . . . . . . . . . .
	//Searching for entered element of array and printing its position.

	cout << "\n\nSearch for a number (array A): ";
	cin >> num;

	bool exist = false;
	int temp_first = 0, temp_last = 0;
	for (int i = 0; i < na; i++){
		if (a[i] == num){
			if (!exist){
				temp_first = i;
				exist = true;
			}
			temp_last = i;
		}
	}

	if (exist){
		cout << "\n\nArray A contains entered number." << endl;
		cout << "\n - First position index of number is: " << temp_first << endl;
		cout << " - The last position index of number is: " << temp_last << endl;
	}
	else cout << "\n\nArray A doesn't contain entered number." << endl;

	//other way
	/*
	int val;
	cout << "\nVal: ";
	cin >> val;
	
	bool con = true, exist = false;
	for (int i = 0; i < na; i++){
		if (a[i] == val){
			if (con){
				cout << "Value exists on positions: ";
				con = false;
			}
			cout << i+1 << ", ";
			exist = true;
		}
	}

	if (!exist) cout << "Entered value don't exist." << endl;
	*/

	//. . . . . . . . . . . . . . . . . . . . . .
	//Position index of min and max element of array.

	int min = a[0], temp_min = 0, temp_max = 0;
	for (int i = 1; i < na; i++){
		if (min > a[i]){
			min = a[i];
			temp_min = i;
		}
		else if (a[temp_max] < a[i]){
			temp_max = i;
		}
	}

	cout << "\nMIN element of array A is " << min << " and its position index is " << temp_min << endl;
	cout << "MAX element of array A have position index: " << temp_max << endl;

	//. . . . . . . . . . . . . . . . . . . . . .
	//The longest series of consecutive equal elements.

	int temp_seq = na != 0;						//if array is not empty temp_seq = 1
	int max_seq = temp_seq;

	for (int i = 1; i < na; i++){

		if (a[i] == a[i - 1]){
			temp_seq++;
		}
		else
			temp_seq = 1;

		if (temp_seq > max_seq)
			max_seq = temp_seq;

	}

	cout << "\n\nThe longest series of consecutive equal elements is: " << max_seq << endl;

	//. . . . . . . . . . . . . . . . . . . . . .
	//The longest series of consecutive nondecreasing elements.

	temp_seq = na != 0;						//if array is not empty temp_seq = 1
	max_seq = temp_seq;

	for (int i = 1; i < na; i++){

		if (a[i] >= a[i - 1]){
			temp_seq++;
		}
		else
			temp_seq = 1;

		if (temp_seq > max_seq)
			max_seq = temp_seq;

	}

	cout << "\nThe longest series of consecutive nondecreasing elements is: " << max_seq << endl;

	//. . . . . . . . . . . . . . . . . . . . . .
	//Testing if array B is consecutive subarray of array A.

	unsigned int nb;

	cout << "\n\nEnter a size of array B: ";
	cin >> nb;

	int* b = new int[nb];

	cout << "Enter elements value of array B: ";
	for (int i = 0; i < nb; i++){
		cin >> b[i];
	}


	int i, j;
	bool sub = false;

	for (i = 0; i + nb - 1 < na; i++){
		for (j = 0; j < nb; j++){
			if (a[i + j] != b[j]){
				break;
			}
		}
		if (j == nb){
			sub = true;
			break;
		}
	}

	if (sub) cout << "\nArray B is consecutive subarray of array A." << endl;
	else cout << "\nArray B is NOT consecutive subarray of array A." << endl;

	//. . . . . . . . . . . . . . . . . . . . . .
	//Testing if array B is subarray of array A. 
	// *** elements don't need to be consecutive, but they're need to be in the same order

	unsigned int nc;

	cout << "\n\nEnter a size of array C: ";
	cin >> nc;

	int* c = new int[nc];

	cout << "Enter elements value of array C: ";
	for (int i = 0; i < nc; i++){
		cin >> c[i];
	}

	i = j = 0;
	sub = false;

	for (i = 0, j = 0; i < na && j < nc; i++){
		if (a[i] == c[j]){
			j++;
		}
		if (j == nc){
			sub = true;
			break;
		}
	}

	if (sub) cout << "\nArray C is subarray (in order) of array A." << endl;
	else cout << "\nArray C is NOT subarray (in order) of array A." << endl;

	//. . . . . . . . . . . . . . . . . . . . . .

	delete[] a, b, c;

}


//---------------------------------------------------------------------------------------------------
//Finding a number that has the most occurrences in an array.
//***With reallocation array input and dynamic allocation from C!
/*
#define STEP 32

void number_with_most_duplicates_in_Array(){

	unsigned n = 0, aloc = 0;
	int* a = NULL;

	do{
		if (aloc <= n){
			int* a_new;
			aloc += STEP;
			a_new = realloc(a, aloc*sizeof(int));				//<stdlib.h>  /  <cstdlib>
			a = a_new;
		}
		scanf_s("%d", &a[n]);
	
	} while (a[n++] != 0);

	//. . . . . . . . . . . . . . . . . . . . . .
	//THERE IS A BETTER WAY - THIS IS NOT AN EFFICIENT WAY.

	int max_duplicate = 0, num;

	for (int i = 0; i < n; i++){
		int duplicate = 0;
		for (int j = 0; j < n; j++){
			if (a[i] == a[j]){
				duplicate++;
			}
		}
		if (duplicate > max_duplicate){
			max_duplicate = duplicate;
			num = a[i];
		}
	}
	
	cout << "Number " << num << " has the most occurrences - " << max_duplicate << " times." << endl;

}
*/


//---------------------------------------------------------------------------------------------------
//Array linear search.

void linear_search()
{
	int n, num;
	
	cout << "Enter the array size: ";
	cin >> n;

	int *a = new int[n];

	cout << "\nEnter array elements:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "\nEnter the number to search: ";
	cin >> num;

	bool con = false;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == num)
		{
			if (!con) cout << "\nNumber found at index No. ";
			cout << i << ", ";
			con = true;
		}
	}

	if (!con) cout << "\nNumber doesn't found." << endl;

	delete[] a;
}


//---------------------------------------------------------------------------------------------------
//Array binary search.

void binary_search()
{
	int n, num, temp;

	cout << "Enter the array size: ";
	cin >> n;

	int *a = new int[n];

	cout << "\nEnter array elements:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	//Sorting the array using bubble sort technique
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	cout << "\nThe new sorted array is:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	//.............................................

	cout << "\n\nEnter the number to search: ";
	cin >> num;

	int first = 0;
	int last = n - 1;
	int middle = (first + last) / 2;

	while (first <= last)
	{
		if (a[middle] == num)
		{
			cout << "\nThe number " << num << " found at position: " << middle + 1 << endl;
			break;
		}
		else if (a[middle] < num)
			first = middle + 1;
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}

	if (first>last)
		cout << "\nThe number " << num << " is not found in given array." << endl;

	delete[] a;
}