
#include<iostream>
#include<string>

using namespace std;

class player
{
private:
	string name;
	int health;
	int xp;

public:
	void set_name(string name_val)
	{
		name=name_val;
	}
	
	//overloaded constructors
	player()
	{
		cout<<"No arguement constructor is called"<<endl;

	}
	player(string name)
	{
		cout<<"string arg constructor is called"<<endl;

	}
	player(string name,int health, int xp)
	{
		cout<<" Three arg constructor is called"<<endl;

	}
	
	//destructors 
	//destructors are called in the reverse order of the creation of 
	//the objects
	~player()
	{
		cout<<" Destructor is called for "<<name<<endl;
	}

};


int main()
{
	{
		player slayer;
		slayer.set_name("Slayer");
	}

	{
		player frank;
		frank.set_name("Frank");
	
		player hero("Hero");
		hero.set_name("hero");

		player villain("villain",100,12);

		villain.set_name("Villain");

	}

}


/*

iteration
50 21 No arguement constructor is called 15 
Destructor is called for slayer

56 21 No arguement constructor is called 57 15 

59 26 string arg constructor is called 15

62 31 Three arg constructor is called 15

40   Destructor is called for villain
40   Destructor is called for hero 
40   Destructor is called for frank
 




*/





















