
class Task
{
private:
	int x;
	int y;
	static int z;	//the declaration of the static attribute

public:
	Task() : x(0), y(0) {}		//the default constructor by initialization list
	Task(int, int);				//the declaration of the switched constructor

	int getx() const { return x; }	//constant class functions
	int gety() const { return y; }

	void setx(int xx){ x = xx; }	//set class functions
	void sety(int yy){ y = yy; }

	static void printz()		//static class function		//only available for static attribute
	{ cout << "Static z = "<< z << endl; }

	friend class Task2;		//all functions from class "Task2" are friends of class "Task"



};


//-----------------------------------------------
//definitions of constructors and class functions

Task::Task(int a, int b) : x(a), y(b) {}	//the definition of the switched constructor with initialization list

int Task::z = 0;	//the definition of the static attribute	//its call is available without the object


