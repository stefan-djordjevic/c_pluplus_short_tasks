#ifndef arrayfusion
#define arrayfusion

#include <iostream>
using namespace std;

//...............................................................................................................................
//Use generic function to merge two ordered arrays into a third, same ordered, array;
//Program with generic function should be able to merge arrays of:
//		- whole numbers ordered by their value
//		- points in the plane ordered by their distance from coordinate beginning
//		- rectangles ordered by their area;


//definition of generic function for arrays merging
template <typename T>
	void fusion(const T* a, int na, const T* b, int nb, T*& c, int& nc)
	{
		c = new T[nc = na + nb];
	
		int ia = 0, ib = 0, ic = 0;
		while (ia < na || ib < nb)
		{
			c[ic++] =	ia == na	  ? b[ib++] :
						ib == nb	  ? a[ia++] :
						a[ia] < b[ib] ? a[ia++] : b[ib++];
		}
	}


//definition of class Point
class Point
{
	double x, y;
public:
	friend istream& operator >> (istream& pin, Point& p) 
	{ return pin >> p.x >> p.y; }									//input
	friend ostream& operator << (ostream& pout, Point& p) 
	{ return pout << "p(" << p.x << "," << p.y << ")"; }			//output
	friend int operator < (const Point& p1, const Point& p2) 
	{ return p1.x*p1.x + p1.y*p1.y < p2.x*p2.x + p2.y*p2.y; }		//comparison
};


//definition of class Rectangle
class Rectangle
{
	double a, b;
public:
	friend istream& operator >> (istream& rin, Rectangle& r)
	{ return rin >> r.a >> r.b; }									//input
	friend ostream& operator << (ostream& rout, Rectangle& r)
	{ return rout << "R[" << r.a << "," << r.b << "]"; }			//output
	friend int operator < (const Rectangle& r1, const Rectangle& r2)
	{ return r1.a*r1.b < r2.a*r2.b; }								//comparison
};

#endif