#ifndef classes
#define classes

#include <iostream>
using namespace std;

class base
{
private:
	int x;
protected:
	int y;
public:
	int z;

	base() : x(0), y(0)
	{
		cout << "Default constructor - base" << endl;
	}

	base(int a, int b) : x(a), y(b)
	{
		cout << "Overload constructor - base" << endl;
	}

	base(const base &b) : x(b.x), y(b.y)
	{
		cout << "Copy constructor - base" << endl;
	}

	int getx() const { return x; }
	int gety() const { return y; }

	void print() const { cout << x << "\t" << y << endl; }
};


class derivedOne : virtual public base
{
private:
	int e;
public:
	int f;

	derivedOne() : e(0)
	{
		cout << "Default constructor - derivedOne" << endl;
	}

	derivedOne(int a) : e(a), base(a - 1, a + 1)
	{
		cout << "Overload constructor - derivedOne" << endl;
	}

	derivedOne(const derivedOne &d) : e(d.e)
	{
		cout << "Copy constructor - derivedOne" << endl;
	}

	int gete() const { return e; }

	void print() const { cout << getx() << "\t" << y << "\t" << e << endl; }

	void sety_derived(int a) { y = a; }
};


class derivedTwo : virtual public base
{
private:
	int h;
public:
	int g;

	derivedTwo() : h(0)
	{
		cout << "Default constructor - derivedTwo" << endl;
	}

	int geth() const { return h; }
};


class grandchild : public derivedOne, public derivedTwo
{
public:
	grandchild() {}
	grandchild(int a) : base(a, a + 10)
	{
		cout << "Overload constructor - grandchild" << endl;
	}

	void f()
	{
		//++derivedOne::z;
		++z;
		//cout << "Child z: " << derivedOne::z << endl;
		cout << "Common z: " << z << endl;

		cout << "Common x and y: " << getx() << "\t" << y << endl;

		cout << "e and h: " << gete() << "\t" << geth() << endl;
	}
};

#endif