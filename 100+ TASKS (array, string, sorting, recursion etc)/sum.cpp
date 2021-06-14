#include <iostream>
using namespace std;


//---------------------------------------------------------------------------------------------------
//The sum: S(n)=1/(n+k).

void sum_1(){

	int n, k;
	double sum = 0;

	do{
		cout << "Enter n and k: " << endl;
		cin >> n >> k;

		if (n <= 0) cout << "\nThe value of n is not allowed!\n";

	} while (n <= 0);


	for (int i = 0; i <= k; i++){

		sum += (1.0 / (n + i));

	}

	cout << "\nSum is: " << sum << endl;
	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//The sum: S(n)=1/(a(n)+1), where a(n) is array.

void sum_2(){

	int n;
	double sum=0;

	cout << "Enter the array size: n= ";
	cin >> n;

	double* a = new double[n];

	cout << "\nEnter the values of the array elements:" << endl;
	
	for (int i = 0; i < n; i++){
		do{
			cout << "a[" << i << "]= ";
			cin >> a[i];

			if (a[i] == -1) cout << "The element value is not allowed!" << endl;

		} while (a[i] == -1);
	}

	cout << "\nThe entered array: ";

	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	
	for (int i = 0; i < n; i++){
		sum += (1.0 / (a[i] + 1));
	}

	cout << "\n\nThe sum of entered array is: " << sum << endl;
	cin.sync();

	delete[] a;

}


