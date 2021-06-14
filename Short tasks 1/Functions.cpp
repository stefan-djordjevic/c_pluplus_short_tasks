#include <iostream>
using namespace std;

#include "Declarations_io.h"

//task_1
void sumtask_1(){

	int n, sum=0;

	cout << "TASK_1" << endl;
	cout << "Enter n: ";
	cin >> n;

	//in("TASK_1");

	for (int i = 1; i <= n; ++i){
		sum += i;
	}

	cout << "The sum for entered n is: " << sum << endl;

	//rec func call
	int recf_1(int);
	cout << "The sum for entered n is: " << recf_1(n)<< "  (*recfunc)" << endl;

	cout << endl;
	cin.sync();

}

//task_1 like recursive function
int recf_1(int n){

	if (n < 1) return 0;

	return n + recf_1(n - 1);
}

