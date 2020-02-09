
class Task2
{
private:
	int e;
	int f;

public:
	Task2() : e(0), f(0) {}
	Task2(int, int);

	void print_friend(Task &);	//this function is friend of class "Task"

	friend void set_friend_global(Task2 &, int);	//global function like a friend of the class "Task2"

	class Inner		//the definition of the inner class
	{
	private:
		int g;
	
	public:
		int h;
		void innerf(Task2);
	};

	void task2f(Inner);

	int k;
	void func(int);
};


//------------------------------------------------
Task2::Task2(int a, int b) : e(a), f(b) {}

void Task2::print_friend(Task &t)		//because this function is a friend of class "Task", it has access to attributes of class "Task"
{
	cout << "Friend e and f: " << t.x<< ", " << t.y << endl;
}

void Task2::Inner::innerf(Task2 t)		//definition of the function of inner class
{
	g = t.e;
	cout << "Inner g = " << g << endl;
}

void Task2::task2f(Inner i)
{
	int ta = i.h;
	cout << "Task2 ta = inner h = " << i.h << endl;
}

void Task2::func(int a)
{
	cout << "By function member pointer : " << a << endl;
}