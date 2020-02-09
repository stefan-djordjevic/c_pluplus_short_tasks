
//the definition of the class
class test
{
	int zero;		//it's PRIVATE, default access!
	int null;

public:
	int first;
	int second;

public:
	void print()	//the inner definition of the class function
	{
		cout << "My first class." << endl;
	}
	int sqrt(int third);	//only the declaration of the class function
	int sum();
	void print_v(int value);

	test() { zero = 0; null = 0; }		//the default constructor
	test(int, int);		//the declaration of the switched(folded) constructor
	
	int getZero() { return zero; }		//get class function, it represents access to the variable "zero" 
	int getNull() { return null; }

	int sum2();


};


//outer definitions of class functions

int test::sum()
{
	return first + second;
}

void test::print_v(int value)
{
	cout << value << endl;
}

test::test(int x, int y)	//the definition of the switched constructor
{
	zero = x; null = y;
}

int test::sum2()
{
	return zero + null + first + second;
}