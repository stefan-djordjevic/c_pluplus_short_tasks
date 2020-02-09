
class Parent		//base, parent, superclass
{
private:
	int x;

protected:
	int z;

public:
	int i;

	Parent(int a, int b) : x(a), z(b)
	{ cout << "Constructor for Parent" << endl; }

	Parent(const Parent &p) : x(p.x), z(p.z) 
	{ cout << "Copy constructor for Parent" << endl; }

	int getx() { return x; }
	int getz() { return z; }
};


