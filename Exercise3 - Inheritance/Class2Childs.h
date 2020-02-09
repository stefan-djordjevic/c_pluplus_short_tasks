
class Child : public Parent		//derived, child, subclass
{
private:
	int y;

public:
	int j;

	Child(int a) : y(a), Parent(a + 1, a - 1)	//derived class constructor with explicit base class constructor
	{ cout << "Constructor for Child" << endl; }

	int gety() { return y; }

	void func()
	{
		z = 2;
	};
};



class Child2 : public Parent
{
public:
	int k;
};