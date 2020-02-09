
class Grandchild : public Child, public Child2
{
public:
	void f()
	{
		++ Child::i;	//it's necesssary to specifically state from which superclass is i used
		cout << "Child i: " << Child::i << endl;		
	}
};

//it's NOT necessary if classes Child and Child2 are derived from base class like VIRTUAL !!!
//class Child  :: virtual public Parent { ... };
//class Child2 :: virtual public Parent { ... };
