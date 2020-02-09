
//==================================================
//base class

class Player2										//PURE ABSTRACT CLASS
{
public:
	virtual void play2() const = 0;					//pure virtual functions
	virtual	void stop2() const = 0;
};


void Player2::play2() const							//definitions of pure virtual functions 
{ cout << " started." << endl; }

void Player2::stop2() const
{ cout << " stopped." << endl; }


//==================================================
//derived class

class CD_player2 : public Player2					//ABSTRACT CLASS (non pure!!!)
{
public:
	void stop2() const								//override function
	{ cout << "CD player2 -"; Player2::stop2(); }
};


//==================================================
//derived class

class Sony_player : public CD_player2
{
public:
	void play2() const
	{ cout << "sony CD player2 -"; Player2::play2(); }
};

//==================================================
//a ordinary function

void test2(const Player2 &r)
{
	r.play2();
	r.stop2();
}