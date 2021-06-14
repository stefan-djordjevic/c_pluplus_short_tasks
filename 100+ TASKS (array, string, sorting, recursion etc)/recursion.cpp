#include <iostream>
#include <cstring>
using namespace std;


//---------------------------------------------------------------------------------------------------
//The sum: S(n)=1/(n+k) like recursion.

void sum_1_recursion(){

	int n, k;
	double sum = 0;

	do{
		cout << "Enter n and k: " << endl;
		cin >> n >> k;

		if (n <= 0) cout << "\nThe value of n is not allowed!\n";

	} while (n <= 0);

	double recursion(int, int);

	cout << "\nSum is: " << recursion(n, k) << endl;
	cin.sync();
}

double recursion(int n, int k){

	if (k < 0) return 0;

	return (1.0 / (n + k)) + recursion(n, k - 1);
}


//---------------------------------------------------------------------------------------------------
//The sum of two numbers - like recursion

void add_like_recursion()
{
	double a, b, add;
	double add_recursion(double, double);

	cout << "Enter two numbers:" << endl;
	cin >> a >> b;

	add = add_recursion(a, b);

	cout << "Result a + b = " << add << endl;
}

double add_recursion(double a, double b)
{
	if (b == 0)
		return a;

	return 1 + add_recursion(a, b - 1);
}


//---------------------------------------------------------------------------------------------------
// Graduation - like recursion.

void graduation_like_recursion(){

	double x, result;
	unsigned n;
	int graduation(double, unsigned);

	cout << "Enter base: ";
	cin >> x;
	cout << "Enter exponent: ";
	cin >> n;

	result = graduation(x, n);
	
	cout << "\nResult is: " << result << endl;

}

int graduation(double x, unsigned n){

	if (n == 0)
		return 1.0;
	else if(n % 2 == 0)
		return graduation(x*x, n / 2);
	else
		return x * graduation(x, n - 1);

}


//---------------------------------------------------------------------------------------------------
// Factorial - like recursion.

void factorial_like_recursion(){

	int n, result;
	int factorial(int);

	cout << "Enter a number: ";
	cin >> n;


	result = factorial(n);

	cout << "\nFactorial of entered number is: " << result << endl;

}

int factorial(int n){

	if (n < 2)
		return 1;
	
	return n * factorial(n - 1);

}

//---------------------------------------------------------------------------------------------------
// Reverse string via recursion and pointers

void reverse_string()
{
	char str[256];
	
	cout << "Enter string: ";
	gets_s(str);

	void reverse(char*);
	reverse(str);				//recursive function call
}

void reverse(char *p)			//definition of recursive function
{
	if (*p)
		reverse(p + 1);
	else
		return;

	cout << *p;
}


//---------------------------------------------------------------------------------------------------
//Array binary search - like recursion.

void binary_search_like_recursion()
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

	int binSearch_rec(int*, int, int, int);
	int first = 0, last = n - 1;					//!!!
	int pos;

	pos = binSearch_rec(a, first, last, num);		//recursive function call

	if (!pos) 
		cout << "\nThe number " << num << " is not found in given array." << endl;
	else
		cout << "\nThe number " << num << " found at position: " << pos << endl;

	delete[] a;
}

//definition of recursive function
int binSearch_rec(int *a, int first, int last, int num)
{	
	if (first > last) return 0;

	int middle = (first + last) / 2;

	if (a[middle] == num)
		return middle + 1;
	else if (a[middle] > num)
		binSearch_rec(a, first, middle-1, num);
	else
		binSearch_rec(a, middle+1, last, num);
}


//---------------------------------------------------------------------------------------------------
//