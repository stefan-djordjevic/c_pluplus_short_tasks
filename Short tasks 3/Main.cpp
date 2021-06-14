#include <iostream>
using namespace std;

#include <math.h>


struct point {
	int x;
	int y;
};


int main(){

	//TASK1
	
	point a;
	point b;

	double distance = 0;

	cout << "Enter point a(x,y):" << endl;
	cout << "\na.x= ";
	cin >> a.x;
	cout << "a.y= ";
	cin >> a.y;

	cout << "\nEnter point b(x,y):" << endl;
	cout << "\nb.x= ";
	cin >> b.x;
	cout << "b.y= ";
	cin >> b.y;

	distance = sqrt(pow((a.x-b.x),2) + pow((a.y-b.y),2));

	cout << "\nTASK 1 - Distance between points a and b is: " << distance << endl;
	
	/*
	point p[2];

	for (int i = 0; i < 2; i++){
		cout << "x[" << i << "]= ";
		cin >> p[i].x;
		cout << "y[" << i << "]= ";
		cin >> p[i].y;
	}

	float dist = sqrt(pow((p[0].x - p[1].x), 2) + pow((p[0].y - p[1].y), 2));

	cout << "\n" << dist << endl;
	*/


	//TASK2

	int n;
	cout << "\nEnter a number of points: ";
	cin >> n;

	double* x = new double[n];
	double* y = new double[n];

	for (int i = 0; i < n; ++i){

		cout << "\nx[" << i << "]= ";
		cin >> x[i];

		cout << "y[" << i << "]= ";
		cin >> y[i];

	}

	double min, max, dist = 0;
	min = max = sqrt(pow(x[0], 2) + pow(y[0], 2));

	int temp1 = 0, temp2 = 0;       //ovom inicijalizacijom belezimo ako je prva tacka najbliza, odnosno najudaljenija !!!

	for (int i = 0; i < n; i++){

		dist = sqrt(pow(x[i], 2) + pow(y[i], 2));

		if (dist < min){
			min = dist;
			temp1 = i;
		}
		else if (dist > max){
			max = dist;
			temp2 = i;
		}
	}

	cout << "\nThe closest point to the coordinate beginning is " << temp1 << " with coordinates [" << x[temp1] << "," << y[temp1] << "]" << endl;
	cout << "\nThe farthest point to the coordinate beginning is " << temp2 << " with coordinates [" << x[temp2] << "," << y[temp2] << "]" << endl;

	
	delete[] x;
	delete[] y;
	

	//TASK3

	int num;
	cout << "\nEnter a number of points: ";
	cin >> num;

	double* q = new double[num];
	double* w = new double[num];

	for (int i = 0; i < num; i++){

		cout << "\nx[" << i << "]= ";
		cin >> q[i];

		cout << "y[" << i << "]= ";
		cin >> w[i];

	}

	double miN, maX, d = 0;
	bool con = true;

	miN = maX = sqrt(pow((q[0] - q[1]), 2) + pow((w[0] - w[1]), 2));

	int min1 = 0, min2 = 1;
	int max1 = 0, max2 = 1;			//inicijalizacija je bitna !!!

	for (int i = 0; i < num - 1; i++){
		for (int j = i+1; j < num; j++){

			d = sqrt(pow((q[i] - q[j]), 2) + pow((w[i] - w[j]), 2));

			if (d < miN){
				miN = d;
				min1 = i;
				min2 = j;
			}
			else if (d > maX){
				maX = d;
				max1 = i;
				max2 = j;
			}
		}
	}

	cout << "\nThe closest points are " << "[" << q[min1] << "," << w[min1] << "]" << " and " << "[" <<q[min2] << "," << w[min2] << "]." << endl;
	cout << "\nThe farthest points are " << "[" << q[max1] << "," << w[max1] << "]" << " and " << "[" << q[max2] << "," << w[max2] << "]." << endl;

	delete[] q;
	delete[] w;

	
	cin.sync();
	cin.ignore();

	return 0;
}