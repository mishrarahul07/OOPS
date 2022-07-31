#include<iostream>
#include<string>
using namespace std;
/*
	
	Technically copy constructor gets called 
	whenever you pass an object to a function

	it initialises an object of a class using 
	a pre existing object

	Copy constructor is called when 
	1. When an object of the class is returned by value.
    2. When an object of the class is passed (to a function) by value as an argument.
    3. When an object is constructed based on another object of the same class.
    4. When the compiler generates a temporary object.

*/

class player
{
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
	//default constructor
	//basically it is prototyping
	player(string name_val="None",int health_val=0,int xp_val=0);
	
	player(player &source);
	
	//Destructor
	~player()
	{
		cout<<"Destructor is called for "<<name<<endl;

	}
};

player::player(string name_val,int health_val,int xp_val)
	:name(name_val),health(health_val),xp(xp_val)

{
	cout<<"Three args constructor is called for "<<name<<endl;

}

player::player(player &source)
	:name(source.name),health(source.health),xp(source.xp)

{
	cout<<"Copy Constructor - made copy of:"<<source.name<<endl;
}

void display_player(player p)
{
	cout<<"Name: "<<p.get_name()<<endl;
	cout<<"Health: "<<p.get_health()<<endl;
	cout<<"Xp: "<<p.get_xp()<<endl;
}

int main()
{
	player empty;

	display_player(empty);
	player frank("Frank");
	display_player(frank);
	player hero("Hero",100);
	display_player(hero);
	player villain("Villain",100,55);
	display_player(villain);
	player p2=frank;
	
	// in this case copy constructor is not called
	// bcoz we are not initialising but simply copying
	//constructors are called for initialisation
	player p3;
	p3=hero;
	return 0;

}


















