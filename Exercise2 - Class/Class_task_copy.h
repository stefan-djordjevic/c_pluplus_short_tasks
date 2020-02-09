
class TaskCopy
{
private:
	int * ph;

public:
	TaskCopy() : ph(NULL) 
	{ 
		cout << "Default constructor." << endl;
		if(ph)
			cout << "Pointer ph is alocated." << endl;
		else
			cout << "Pointer ph is dealocated." << endl;
	}

	TaskCopy(int x) : ph(new int(x)) 
	{ cout << "Switched constructor." << endl << "*ph= " << *ph << endl;}

	TaskCopy(const TaskCopy &tc) : ph(new int(*tc.ph))	//copy constructor
	{ cout << "Copy constructor." << endl << "*ph = " << *ph << endl; }


	~TaskCopy()		//destructor for dynamic variable
	{ 
		delete ph; 
		cout << "Destructor." << endl;
	}	
};