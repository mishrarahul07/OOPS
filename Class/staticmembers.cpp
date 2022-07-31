/*
Static class members

Class Data members can be declared as static
	A single data member that belong to the class and
	not the objects
	Useful to storeclass-wide information

Class functions can also be declared as static
	Independent of any objects
	Can be called using class name

static variables only have access to static attributes








*/
#include<iostream>
#include<string>
using namespace std;
class Player
{
	static int num_players;
	string name; 
	int health; 
	int xp;



public:
	string get_name()
	{
		return name;
	}
	int get_health()
	{
		return health;
	}
	int get_xp()
	{
		return xp;
	}

	Player(string name_val="None",int health_val=0,int xp_val=0);

	Player(const Player &source);

	static int get_num_players();
	
	~Player()
	{
		num_players--;
	}
	
};

Player::Player(string name_val,int health_val,int xp_val)
:name(name_val),health(health_val),xp(xp_val)
{
	num_players++;
}

Player::Player(const Player &source)
:name(source.name),health(source.health),xp(source.xp)
{

}

int Player::num_players=0;

int Player::get_num_players()
{
	return num_players;
}


void display_active_player()
{
	cout<<"Active Players "<<Player::get_num_players()<<endl;
}
int main()
{
	display_active_player();
	Player hero("Hero");
	display_active_player();
	{
		Player frank("Frank");
		display_active_player();
	}
	display_active_player();
	
	Player *enemy=new Player("Enemy",100,100);
	display_active_player();
	delete enemy;
	display_active_player();


	return 0;
}
























