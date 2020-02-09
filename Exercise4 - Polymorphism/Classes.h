
//==================================================
//base class

class Player
{
public:
	virtual void play() const					//virtual class function !!! 
	{ cout << "player::play" << endl; }
	void stop() const
	{ cout << "player::stop" << endl; }
};


//==================================================
//derived class

class CD_player : public Player
{
public:
	void play() const
	{ cout << "cd_player::play" << endl; }		//override function
	void stop() const
	{ cout << "cd_player::stop" << endl; }
};


//==================================================
//a ordinary function

void test(const Player &r)
{
	r.play();
	r.stop();
}