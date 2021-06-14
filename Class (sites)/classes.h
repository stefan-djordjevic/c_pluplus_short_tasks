#ifndef classes
#define classes

//---------------------------------------------------------------------------------
//EXAMPLE 1

class Square;

class Rectangle
{
	int width, length;
public:
	Rectangle();
	Rectangle(int, int);
	Rectangle(const Rectangle &);

	const int& getWidth() const;
	const int& getLength() const;
	void setWidth(int);
	void setLength(int);

	int area() const;
	void printArea() const;

	void convert(const Square &);
};

Rectangle::Rectangle() : width(0), length(0) {}

Rectangle::Rectangle(int a, int b) : width(a), length(b) {}

Rectangle::Rectangle(const Rectangle &r) : width(r.width), length(r.length) {}

const int& Rectangle::getWidth() const { return width; }

const int& Rectangle::getLength() const { return length; }

void Rectangle::setWidth(int a) { width = a; }

void Rectangle::setLength(int b) { length = b; }

int Rectangle::area() const { return width*length; }

void Rectangle::printArea() const { cout << "Rectangle Area = " << area() << endl; }

//...............................

class Square
{
	int side;
public:
	Square();
	Square(int);

	friend class Rectangle;
};

Square::Square() : side(0) {}

Square::Square(int a) : side(a) {}

//...............................

void Rectangle::convert(const Square &s)
{
	width = s.side;
	length = s.side;
}


//---------------------------------------------------------------------------------
//EXAMPLE 2

class Circle
{
	double radius;
public:
	Circle();
	Circle(double);
	Circle(const Circle &);

	const double& getRadius() const;
	void setRadius(double);

	double area() const;
	void printArea() const;
};

Circle::Circle() : radius(0) {}

Circle::Circle(double r) : radius(r) {}

Circle::Circle(const Circle &c) : radius(c.radius) {}

const double& Circle::getRadius() const { return radius; }

void Circle::setRadius(double r) { radius = r; }

double Circle::area() const { return radius*radius*3.14; }

void Circle::printArea() const { cout << "Circle Area = " << area() << endl; }

//...............................

class Cylinder
{
	Circle base;
	double height;
public:
	Cylinder();
	Cylinder(double, double);
	Cylinder(const Cylinder &);

	const double& getR() const;
	const double& getH() const;
	void setR(double);
	void setH(double);

	double volume() const;
	void printVolume() const;
};

Cylinder::Cylinder() : base(), height(0) {}

Cylinder::Cylinder(double r, double h) : base(r), height(h) {}

Cylinder::Cylinder(const Cylinder &c) : base(c.base), height(c.height) {}

const double& Cylinder::getR() const { return base.getRadius(); }

const double& Cylinder::getH() const { return height; }

void Cylinder::setR(double r) { base.setRadius(r); }

void Cylinder::setH(double h) { height = h; }

double Cylinder::volume() const { return base.area()*height; }

void Cylinder::printVolume() const { cout << "Base Area = " << base.area() << "\tCylinder Volume = " << volume() << endl; }


//---------------------------------------------------------------------------------
//EXAMPLE 3 - Inheritance

class Polygon
{
protected:
	int width, height;
public:
	const int& getWidth() const { return width; }
	const int& getHeight() const { return height; }
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }
};

class Rectanglle : public Polygon
{
public:
	Rectanglle(int a, int b) { width = a; height = b; }
	
	int area() const { return width*height; }
	void printArea() const { cout << "Area = " << area() << endl; }
};

class Triangle : public Polygon
{
public:
	Triangle(int a, int b) { width = a; height = b; }
	
	int area() const { return width*height / 2; }
	void printArea() const { cout << "Area = " << area() << endl; }
};


//---------------------------------------------------------------------------------
//EXAMPLE 4 - Polymorphism

//........................................
//polymorphic class and virtual function

class Polygonn				//polymorphic base class
{
protected:
	int width, height;
public:
	Polygonn() { width = 0; height = 0; }
	const int& getWidth() const { return width; }
	const int& getHeight() const { return height; }
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }

	virtual int area() const { return 0; }	//virtual base member function
	void printArea() const { cout << "Area = " << area() << endl; }
};

class Rectangllee : public Polygonn
{
public:
	Rectangllee(int a, int b) { width = a; height = b; }
	int area() const { return width*height; }	//override virtual base function
};

class Trianglee : public Polygonn
{
public:
	Trianglee(int a, int b) { width = a; height = b; }
	int area() const { return width*height / 2; }	//override virtual base function
};

//..........................................
//Abstract class and pure virtual function

class Pollygonn				//abstract base class
{
protected:
	int width, height;
public:
	Pollygonn() { width = 0; height = 0; }
	const int& getWidth() const { return width; }
	const int& getHeight() const { return height; }
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }

	virtual int area() const = 0;			//pure virtual base member function
	virtual void printArea() const = 0;		//pure virtual base member function
};

void Pollygonn::printArea() const { cout << "Area = " << area() << endl; }		//definition of pure virtual function

class Recctangllee : public Pollygonn
{
public:
	Recctangllee(int a, int b) { width = a; height = b; }
	int area() const { return width*height; }									//override pure virtual base function
	void printArea() const { cout << "Rectangle "; Pollygonn::printArea(); }	//override pure virtual base function
};

class Triannglee : public Pollygonn
{
public:
	Triannglee(int a, int b) { width = a; height = b; }
	int area() const { return width*height / 2; }								//override pure virtual base function
	void printArea() const { cout << "Triangle "; Pollygonn::printArea(); }		//override pure virtual base function
};


#endif