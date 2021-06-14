#include <iostream>
using namespace std;


//---------------------------------------------------------------------------------------------------
//Print half-pyramid, inverted half-pyramid, full pyramid and inverted full pyramid patterns of stars.

void pyramid_patterns()
{
	//half-pyramid....................
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << endl;

	//inverted half-pyramid...........
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j + i < 6; j++)			//for (int j = i; j < 6; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << endl;

	//full pyramid....................
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; i + j < 5; j++)
		{
			cout << "  ";
		}
		for (int k = 0; k <= i * 2; k++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << endl;

	//full pyramid - other way........
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; i + j < 5; j++)
		{
			cout << " ";						//!!! one space, not two!
		}
		for (int k = 0; k <= i; k++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << endl;

	//inverted full pyramid...........
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "  ";
		}
		for (int k = 1; k + i*2 < 6*2; k++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << endl;

	//inverted full pyramid - other way
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < i ; j++)
		{
			cout << " ";						//!!! one space, not two!
		}
		for (int k = 0; k + i < 6; k++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	cout << endl;

	//triangle........................
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; i + j < 5; j++)
		{
			cout << "  ";						 
		}
		for (int k = 0; k <= i; k++)			//it's all the same like "full pyramid", only
		{										//with k<=1 instead k<=i*2
			cout << "* ";
		}
		cout << endl;
	}

	cout << endl;
}


//---------------------------------------------------------------------------------------------------
//Print full pyramid pattern of stars in given size.

void pyramid_pattern_in_size()
{
	int n;

	cout << "Enter the number of pyramid rows: ";
	cin >> n;

	cout << endl;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i + j < n-1; j++)
		{
			cout << "  ";
		}
		for (int k = 0; k <= i * 2; k++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}


//---------------------------------------------------------------------------------------------------
//Print diamond pattern of stars.

void diamond_pattern()
{
	int n;

	cout << "Enter the number of rows: ";
	cin >> n;
	
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i + j < n-1; j++)
		{
			cout << " ";
		}
		for (int k = 0; k <= i * 2; k++)
		{
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int k = 1; k + i * 2 < n * 2; k++)
		{
			cout << "*";
		}
		cout << endl;
	}

}