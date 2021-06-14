#include <iostream>
#include <iomanip>
using namespace std;




//---------------------------------------------------------------------------------------------------
// The setw() manipulator - multiplication table of one number

void mult_table_oneNum()
{
	int num;

	cout << "Enter a number: ";
	cin >> num;

	cout << "\nTable of " << num << " is:\n\n";

	for (int i = 1; i <= 10; i++)
	{
		cout << num << setw(3) << "*" << setw(4) << i << setw(4) << "=" << setw(4) << num*i << endl;	//manipulator setw() from <iomanip>
	}																									//sets the width of the field (as a 
}																										//parameter) assigned for the output


//---------------------------------------------------------------------------------------------------
// The setw() manipulator - multiplying entered number by 5 ten times and printing with 3 columns

void mult_by_num()
{
	int num;

	cout << "Enter a number: ";
	cin >> num;

	cout << "Multiplying number <" << num << "> by 5 ten times and printing with 3 columns: \n\n";

	for (int i = 0; i < 10; i++)
	{
		cout << num << setw(25) << num << setw(25) << num << endl;
		num *= 5;
	}
}


//---------------------------------------------------------------------------------------------------
// The setprecision() manipulator - with IOS flags

void set_precision()
{
	//sets the total number of digits to be displayed when floating-point numbers are printed
	cout << setprecision(5) << 123.456 << endl;
												
	//once the flag has been set, the number that is passed to setprecision() is the number of
	//decimal places that are wanted to be displayed
	cout.setf(ios::fixed);
	cout << setprecision(5) << 12.345678 << endl;

	//other IOS flags: left, right, showpoint, uppercase, showpos, scientific

	//print 5.8 like +5.80
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.setf(ios::showpos);
	cout << setprecision(2);
	cout << 5.8;

}