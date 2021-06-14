#include <iostream>
#include <math.h>

using namespace std;


//---------------------------------------------------------------------------------------------------
//A distance between two points.

void distance_2points(){

	struct point {
		double x=0;
		double y=0;
	};


	point a, b;
	double distance = 0;

	cout << "Enter point a(x,y):" << endl;
	cout << "a.x= ";
	cin >> a.x;
	cout << "a.y= ";
	cin >> a.y;

	cout << "\nEnter point b(x,y):" << endl;
	cout << "b.x= ";
	cin >> b.x;
	cout << "b.y= ";
	cin >> b.y;

	distance = sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));

	cout << "\nDistance between points a and b is: " << distance << endl;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//The nearest and the farthest point to the coordinate beginning.

void nearest_farthest_point_toZero(){

	int n;

	cout << "Enter a number of points: ";
	cin >> n;

	double* x = new double[n];
	double* y = new double[n];

	cout << "\nEnter points (x,y):" << endl;
	for (int i = 0; i < n; i++){
		cout << "x" << i << "= ";
		cin >> x[i];
		cout << "y" << i << "= ";
		cin >> y[i];
		cout << endl;
	}

	double distance =0, min_distance, max_distance;
	min_distance = max_distance = sqrt(pow(x[0], 2) + pow(y[0], 2));
	
	int temp_min=0, temp_max=0;

	for (int i = 0; i < n; i++){
		distance = sqrt(pow(x[i], 2) + pow(y[i], 2));
		if (min_distance > distance){
			min_distance = distance;
			temp_min = i;
		} else if (max_distance < distance){
			max_distance = distance;
			temp_max = i;
		}
	}

	cout << "\nThe nearest point to the coordinate beginning is point " << temp_min << " with coordinates (" << x[temp_min] << ", " << y[temp_min] <<
			") and distance: " << min_distance << "." << endl;
	cout << "\nThe farthest point to the coordinate beginning is point " << temp_max << " with coordinates (" << x[temp_max] << ", " << y[temp_max] <<
			") and distance: " << max_distance << "." << endl;

	delete[] x;
	delete[] y;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//The nearest and the farthest point to the coordinate beginning (by structure).

void nearest_farthest_point_toZero_STRUCT(){

	struct point{
		double x=0;
		double y=0;
	};


	int n;

	cout << "Enter a number of points: ";
	cin >> n;

	point* points = new point[n];

	cout << "\nEnter points (x,y):" << endl;
	for (int i = 0; i < n; i++){
		cout << "x" << i << "= ";
		cin >> points[i].x;
		cout << "y" << i << "= ";
		cin >> points[i].y;
		cout << endl;
	}

	double distance = 0, min_distance, max_distance;
	min_distance = max_distance = sqrt(pow(points[0].x, 2) + pow(points[0].y, 2));

	int temp_min = 0, temp_max = 0;

	for (int i = 0; i < n; i++){
		distance = sqrt(pow(points[i].x, 2) + pow(points[i].y, 2));
		if (min_distance > distance){
			min_distance = distance;
			temp_min = i;
		}
		else if (max_distance < distance){
			max_distance = distance;
			temp_max = i;
		}
	}

	cout << "\nThe nearest point to the coordinate beginning is point " << temp_min << " with coordinates (" << points[temp_min].x << ", " << 
			points[temp_min].y << ") and distance: " << min_distance << "." << endl;
	cout << "\nThe farthest point to the coordinate beginning is point " << temp_max << " with coordinates (" << points[temp_max].x << ", " << 
			points[temp_max].y << ") and distance: " << max_distance << "." << endl;

	delete[] points;

	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//The nearest and the farthest points from one another.

void nearest_farthest_points(){

	int n;

	cout << "Enter a number of points: ";
	cin >> n;

	double* x = new double[n];
	double* y = new double[n];

	cout << "\nEnter points (x,y):" << endl;
	for (int i = 0; i < n; i++){
		cout << "x" << i << "= ";
		cin >> x[i];
		cout << "y" << i << "= ";
		cin >> y[i];
		cout << endl;
	}

	double distance = 0, min_distance, max_distance;
	min_distance = max_distance = sqrt(pow((x[0] - x[1]), 2) + pow((y[0] - y[1]), 2));

	int temp_min1 = 0, temp_min2 = 1;
	int temp_max1 = 0, temp_max2 = 1;

	for (int i = 0; i < n-1; i++){
		for (int j = i + 1; j < n; j++){
			distance = sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
			if (min_distance > distance){
				min_distance = distance;
				temp_min1 = i;
				temp_min2 = j;
			}
			else if (max_distance < distance){
				max_distance = distance;
				temp_max1 = i;
				temp_max2 = j;
			}
		}
	}

	cout << "\nThe two nearest points are: " << temp_min1 << "(" << x[temp_min1] << ", " << y[temp_min1] <<") and " 
			<< temp_min2 << "(" << x[temp_min2] << ", " << y[temp_min2] << ") with distance = "<< min_distance << "." << endl;
	cout << "\nThe two farthest points are: " << temp_max1 << "(" << x[temp_max1] << ", " << y[temp_max1] << ") and "
			<< temp_max2 << "(" << x[temp_max2] << ", " << y[temp_max2] << ") with distance = " << max_distance << "." << endl;

	delete[] x;
	delete[] y;


	cin.sync();
}


//---------------------------------------------------------------------------------------------------
//Testing whether points A and B are on the same side of the line determined by points C i D.

void points_sameSide_line(){

	struct point{
		double x = 0;
		double y = 0;
	};

	const int n = 4;
	int k;
	point p[n];

	cout << "Enter 4 points - points A, B and points which determine the line C, D:\n" << endl;
	for (int i = 0; i < n; i++){
		cout << "x" << i << "= ";
		cin >> p[i].x;
		cout << "y" << i << "= ";
		cin >> p[i].y;
		cout << endl;
	}
	
	k = (p[3].y - p[2].y) / (p[3].x - p[2].x);

	if ((((p[0].y - p[2].y) < (k*(p[0].x - p[2].x))) && ((p[1].y - p[2].y) < (k*(p[1].x - p[2].x)))) 
		|| (((p[0].y - p[2].y) > (k*(p[0].x - p[2].x))) && ((p[1].y - p[2].y) > (k*(p[1].x - p[2].x)))))
		cout << "\nPoints A and B are on the same side of the line determined by points C and D" << endl;
	else if ((((p[0].y - p[2].y) == (k*(p[0].x - p[2].x))) && ((p[1].y - p[2].y) == (k*(p[1].x - p[2].x)))))
		cout << "\nPoints A and B are on the line determined by points C and D" << endl;
	else cout << "\nPoints A and B are NOT on the same side of the line determined by points C and D" << endl;

	cin.sync();
}