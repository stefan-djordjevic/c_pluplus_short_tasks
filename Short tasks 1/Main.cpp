#include <iostream>
using namespace std;

#include "Declarations.h"

int main(){

	//sumtask_1();      //task_1 via function
	
	int n;
	float sum = 0, k;

	cout << "Enter n: ";
	cin >> n;


	//TASK_1

	for (int i = 1; i <= n; i++){
		sum += i;
	}

	cout << "\nTASK 1 - The sum for entered n is: " << sum << endl;
	cout << "TASK 1 - The sum for entered n is: " << recf1(n) << "   (*rfunc)" << endl;
	cout << endl;
	sum = 0;


	//TASK_2

	for (int i = 1; i <= n; i++){
		sum += i*i;
	}

	cout << "\nTASK 2 - The sum for entered n is: " << sum << endl;
	cout << "TASK 2 - The sum for entered n is: " << recf2(n) << "   (*rfunc)" << endl;
	cout << endl;
	sum = 0;

	
	//TASK_3

	for (int i = 1; i <= n; i++){
		sum += 1 / static_cast<float>(i);
	}

	printf("\nTASK 3 - The sum for entered n is: %.2f\n", sum);
	cout << "TASK 3 - The sum for entered n is: " << recf3(n) << "   (*rfunc)" << endl;
	cout << endl;
	sum = 0;


	//TASK_4

	for (float i = 1; i <= n; i++){
		sum += 1 / (i*i);
	}

	cout << "\nTASK 4 - The sum for entered n is: " << sum << endl;
	cout << "TASK 4 - The sum for entered n is: " << recf4(n) << "   (*rfunc)" << endl;
	cout << endl;
	sum = 0;


	//TASK_5

	cout << "\nEnter k: ";
	cin >> k;

	for (float i = 0; i <= k; i++)
		sum += 1 / (static_cast<float>(n) + i);

	cout << "\nTASK 5 - The sum for entered n and k is: " << sum << endl;
	cout << "TASK 5 - The sum for entered n and k is: " << recf5(n, k) << "   (*rfunc)" << endl;
	cout << endl;
	sum = 0;


	//TASK_6.1 (static array)

	const int m = 3;
	
	float arrs[m];

	cout << "\nEnter the values of the array elements(3): \n";
	for (int i = 0; i < m; i++){
		cout << "a[" << i << "]= ";
		cin >> arrs[i];
	}

	cout << "\nEntered array: ";
	for (int i = 0; i < n; i++){
		cout << arrs[i] << " ";
	}

	for (int i = 0; i < m; i++){
		sum += arrs[i] * arrs[i];
	}

	cout << "\n\nTASK 6.1 - The sum for entered array is: " << sum << "   (*arrstat)" << endl;
	cout << endl;
	sum = 0;


	//TASK_6.2 (dynamic array)

	cout << "\nEnter array size: ";
	cin >> n;
	
	float* parrd = new float[n];

	cout << "\nEnter the values of the array elements(" << n << "): \n";
	for (int i = 0; i < n; i++){
		cout << "a[" << i << "]= ";
		cin >> parrd[i];
	}

	cout << "\nEntered array: ";
	for (int i = 0; i < n; i++){
		cout << parrd[i] << " ";
	}

	for (int i = 0; i < n; i++){
		sum += parrd[i] * parrd[i];
	}

	cout << "\n\nTASK 6.2 - The sum for entered array is: " << sum << "   (*arrdyn)" << endl;
	cout << endl;
	sum = 0;


	//TASK_7
	
	cout << "\nEnter a dimension of the array: ";
	cin >> n;

	float* parrd2 = new float[n];

	cout << "\nEnter the values of the array elements(" << n << "): \n";
	
	for (int i = 0; i < n; i++){
		
		do {
			
			cout << "a[" << i << "]= ";
			cin >> parrd2[i];

			if (parrd2[i] == -1)
				cout << "Enter a number other then -1!" << endl;

		} while (parrd2[i] == -1);

	}


	cout << "\nEntered array: ";
	for (int i = 0; i < n; i++){
		cout << parrd2[i] << " ";
	}
	
	for (int i=0; i < n; i++){
		sum += 1 / (parrd2[i] + 1);
	}

	cout << "\n\nTASK 7 - The sum for entered array is: " << sum << endl;
	cout << endl;
	sum = 0;


	//TASK_8

	float min = parrd2[0];
	float max = parrd2[0];

	for (int i = 0; i < n; i++){
		
		if (min > parrd2[i])
			min = parrd2[i];
		else if (max < parrd2[i])
			max = parrd2[i];
	}

	cout << "\nTASK 8 - The entered array MIN is " << min << " and MAX is " << max << endl;
	cout << endl;

	
	//TASK 8_1
	
	min = 0; max = 0;

	bool con = true;
	
	for (int i = 0; i < n; ++i){
		
		if (con) {
			min = max = parrd[i];
			con = false;
			continue;
		}
		
		if (min > parrd2[i])
			min = parrd2[i];
		else if (max < parrd2[i])
			max = parrd2[i];
	}

	cout << "\nTASK 8.1 - The entered array MIN is " << min << " and MAX is "<< max << endl;
	cout << endl;

	
	//TASK_12

	cout << "\nEntered array: ";
	for (int i = 0; i < n; ++i){
		cout << parrd2[i] << " ";
	}
	
	float temp;
	for (int i = 0, j = n - 1; i < j; i++, j--){
			temp = parrd2[i];
			parrd2[i] = parrd2[j];
			parrd2[j] = temp;
	}

	cout << "\n\nTASK 12 - Entered array reversed: ";
	for (int i = 0; i < n; ++i){
		cout << parrd2[i] << " ";
	}
	
	
	delete[] parrd;
	delete[] parrd2;
	

	//TASK_9

	cout << "\nEnter a number: ";
	cin >> n;

	bool prime = true;
	for (int i = 2; i <= n/2; i++){
		if (n%i == 0){
			prime = false;
			break;
		}
	}

	if (prime)
		cout << "\nThe number is prime." << endl;
	else
		cout << "\nThe number is composite." << endl;
	

	//TASK_10

	int p, q, miN;

	cout << "\Enter two numbers:" << endl;
	cin >> p >> q;

	bool mutprime = true;
	
	if (p < q)
		miN = p;
	else
		miN = q;

	//n < m ? min = n : min = m;

	for (int i = 2; i <= miN; i++){

		if (p%i == 0 && q%i == 0){
			mutprime = false;
			break;
		}
	}

	if (mutprime)
		cout << "\nThe numbers are mutually prime." << endl;
	else
		cout << "\nThe numbers are NOT mutually prime." << endl;
	

	//TASK_10.1

	int a, b, minab;
	bool mprime;

	cout << "The mutually prime numbers (1-30):" << endl;

	for (int i = 2; i < 30; i++){
		for (int j = i + 1; j <= 30; j++){
			
			mprime = true;

			for (int k = 2; k <= i; k++){
				if (i%k == 0 && j%k == 0){
					mprime = false;
					break;
				}
			}

			if (mprime)
			cout << i << ", " << j << endl;
		}
	}
	
	
	//TASK_11

	int psum = 0;

	cout << "Enter a number: ";
	cin >> n;

	for (int i = 1; i <= n/2; i++){
		
		if (n%i == 0) 
			psum += i;
		
		if (psum > n) break;
	}

	if (psum == n)
		cout << "The number is perfect." << endl;
	else
		cout << "The number is NOT perfect." << endl;
	

	//TASK_11.1

	int pSum;

	cout << "The perfect numbers (1-10,000):\n" << endl;
	
	for (int num = 2; num <= 10000; num++){
		
		pSum = 0;

		for (int i = 1; i <= num/2; i++){

			if (num%i == 0)
				pSum += i;

			if (pSum > num) break;
		}

		if (pSum == num)
			cout << num << ", ";
	}
	


	cin.sync();
	cin.ignore();

	return 0;
}


