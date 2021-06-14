#include <iostream>
using namespace std;


int main(){

	int n;
	cout << "Enter a size of square matrix: ";
	cin >> n;

	//dynamic matrix
	double** a = new double*[n];
	for (int i = 0; i < n; i++){
		a[i] = new double[n];
	}

	cout << "\nEnter a values of matrix elements:"<<endl;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << " a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}

	cout << "\nEntered matrix:\n" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << " " << a[i][j];
		}
		cout << endl;
	}
	
	
	//TASK1

	int sum = 0;

	for (int i = 0; i < n; i++){
		sum += a[i][i];
	}

	cout << "\nTASK 1 - The sum of elements on the main diagonal is: " << sum << endl;
	sum = 0;


	//TASK2

	for (int i = 0; i < n - 1; i++){
		for (int j = i + 1; j < n; j++){
			sum += a[i][j];
		}
	}

	cout << "\nTASK 2 - The sum of elements above the main diagonal is: " << sum << endl;
	sum = 0;
	

	//TASK3

	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			sum += a[i][j];
		}
	}
	
	//	for (int i = 0; i < n - 1; i++){
	//		for (int j = i + 1; j < n; j++){
	//			sum += a[j][i];
	//		}
	//	}

	//	for (int j = 0; j < n - 1; j++){
	//		for (int i = j + 1; i < n; i++){
	//			sum += a[i][j];
	//		}
	//	}

	cout << "\nTASK 3 - The sum of elements below the main diagonal is: " << sum << endl;
	sum = 0;


	//TASK4

	bool symmetry = true;

	for (int i = 0; i < n-1; i++){				//i = 0; i < n; i++
		for (int j = i+1; j < n; j++){				//j = 0; j < n; j++
			if (a[i][j] != a[j][i]){
				symmetry = false;
				break;
			}
		}
		if (!symmetry) break;
	}

	if(symmetry)
		cout << "\nTASK 4 - The entered matrix IS symmetric." << endl;
	else
		cout << "\nTASK 4 - The entered matrix is NOT symmetric." << endl;
	

	//TASK5

	int m, k;

	cout << "\nEnter a size of new non-square matrix (m x k)." << endl;
	cout << "\nEnter m: ";
	cin >> m;
	cout << "Enter k: ";
	cin >> k;

	double** b = new double*[m];
	for (int i = 0; i < m; ++i){
		b[i] = new double[k];
	}

	cout << "\nEnter a values of matrix elements:\n" << endl;

	for (int i = 0; i < m; i++){
		for (int j = 0; j < k; j++){
			cout << " b[" << i << "][" << j << "]= ";
			cin >> b[i][j];
		}
	}

	cout << "\nEntered matrix:\n" << endl;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < k; j++){
			cout << " " << b[i][j];
		}
		cout << endl;
	}

	
	double min, max;
	min = max = b[0][0];
	
	for (int i = 0; i < m; i++){
		for (int j = 0; j < k; j++){
			
			if (min > b[i][j])
				min = b[i][j];

			else if (max < b[i][j])
				max = b[i][j];

		}
	}

	cout << "\nTASK 5 - MAX element is: "<< max <<"\tMIN element is: "<< min << endl;


	//TASK6

	double** c = new double*[k];
	for (int i = 0; i < k; i++){
		c[i] = new double[m];
	}

	cout << "\nTASK 6 - The transposed matrix for entered matrix is:\n" << endl;
	
	for (int i = 0; i < k; i++){
		for (int j = 0; j < m; j++){
			
			c[i][j] = b[j][i];
			cout << " " << c[i][j];

		}
		cout << endl;
	}


	//deallocation
	for (int i = 0; i < n; i++){
		delete[] a[i];
	}
	
	delete[] a;

	for (int i = 0; i < m; i++){
		delete[] b[i];
	}

	delete[] b;

	for (int i = 0; i < k; i++){
		delete[] c[i];
	}

	delete[] c;


	cin.sync();
	cin.ignore();

	return 0;
}