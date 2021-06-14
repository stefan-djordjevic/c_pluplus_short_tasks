#include <iostream>
using namespace std;


//---------------------------------------------------------------------------------------------------
//Square matrix - the sum of elements on the main diagonal, above and below the main diagonal

void squareMatrix_sum_diagonal(){

	int n;

	cout << "Enter a size of the square matrix: n= ";
	cin >> n;

	double** a = new double*[n];
	for (int i = 0; i < n; i++){
		a[i] = new double[n];
	}

	cout << "\nEnter values of the matrix elements: \n" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
		cout << endl;
	}

	cout << "\nEntered matrix:\n" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	//the sum of elements on the main diagonal
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i][i];

	cout << "\nThe sum of elements on the main diagonal is: " << sum << endl;

	//the sum of elements above the main diagonal
	sum = 0;
	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			sum += a[i][j];
		}
	}

	cout << "\nThe sum of elements above the main diagonal is: " << sum << endl;

	//the sum of elements below the main diagonal
	sum = 0;
	for (int i = 1; i < n; i++){
		for (int j=0; j < i; j++){
			sum += a[i][j];
		}
	}

	cout << "\nThe sum of elements below the main diagonal is: " << sum << endl;


	for (int i = 0; i < n; i++){
		delete[] a[i];
	}
	delete[] a;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Square matrix - symmetry testing

void squareMatrix_symmetry_testing(){

	int n;

	cout << "Enter a size of the square matrix: n= ";
	cin >> n;

	double** a = new double*[n];
	for (int i = 0; i < n; i++){
		a[i] = new double[n];
	}

	cout << "\nEnter values of the matrix elements: \n" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
		cout << endl;
	}

	cout << "\nEntered matrix:\n" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	bool con = true;
	for (int i = 0; i < n-1; i++){
		for (int j = i+1; j < n; j++){
			if (a[i][j] != a[j][i]){
				con = false;
				break;
			}
		}
		if (!con) break;
	}

	if (con) cout << "\nEntered matrix is symmetric." << endl;
	else cout << "\nEntered matrix is NOT symmetric." << endl;


	for (int i = 0; i < n; i++){
		delete[] a[i];
	}
	delete[] a;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Matrix( m x n) - min and max element

void matrix_min_max(){

	int m, n;

	cout << "Enter a size of matrix (m x n):\n" << endl;
	cout << "m= ";
	cin >> m;
	cout << "n= ";
	cin >> n;

	double** a = new double*[m];
	for (int i = 0; i < m; i++){
		a[i] = new double[n];
	}

	cout << "\nEnter values of the matrix elements: \n" << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
		cout << endl;
	}

	cout << "\nEntered matrix:\n" << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	double min, max;
	min = max = a[0][0];

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (min > a[i][j])
				min = a[i][j];
			else if (max < a[i][j])
				max = a[i][j];
		}
	}

	cout << "\nThe MIN element is: " << min << endl;
	cout << "\nThe MAX element is: " << max << endl;

	for (int i = 0; i < m; i++){
		delete[] a[i];
	}
	delete[] a;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Matrix( m x n) - transposed matrix of the entered matrix

void transposed_matrix(){

	int m, n;

	cout << "Enter a size of matrix (m x n):\n" << endl;
	cout << "m= ";
	cin >> m;
	cout << "n= ";
	cin >> n;

	double** a = new double*[m];
	for (int i = 0; i < m; i++){
		a[i] = new double[n];
	}

	double** b = new double*[n];
	for (int i = 0; i < n; i++){
		b[i] = new double[m];
	}

	cout << "\nEnter values of the matrix elements: \n" << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
		cout << endl;
	}

	cout << "\nEntered matrix:\n" << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\nThe transposed matrix of entered matrix:\n" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			b[i][j] = a[j][i];
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < m; i++){
		delete[] a[i];
	}
	delete[] a;

	for (int i = 0; i < n; i++){
		delete[] b[i];
	}
	delete[] b;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Number of days in months of a simple year and in a leap year.

void days_of_months(){

	int year=0;
	int month=0;

	do{
		cout << "Enter month/year: ";
		scanf_s("%d/%d", &month, &year);
		if (month < 1 || month>12) cout << "Invalid input. Please try again.\n" << endl;
	} while (month < 1 || month>12);

	int leap_year = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;		//result 0 or 1 !!!

	int days_number[][13] = {
			{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
			{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
	};

	const char* month_name[] = { " ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	const char* type_year[] = { "SIMPLE", "LEAP" };

	cout << "\nNumber of days in " << month_name[month] << ", " << year << " is: " << days_number[leap_year][month] << endl;
	cout << "\nYear " << year << " is: " << type_year[leap_year];
}


