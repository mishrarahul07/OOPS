
/*
	duplicated code can lead to errors

	by delegating constructors 
	code for one constructor can call another in the initialization list
	avoids duplication

	in this we call the 3 args constructor in the place where we 
	use initialiser list

	we can only do it in the initialisation list

	one arg and 2 arg constructor is a subset of
	3 arg constructor



*/


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
	// 3 overloaded constructors with standard use
/*
	player()
	{
		name="None";
		health=0;
		xp=0;
		display();
	}
	player(string name_val)
	{
		name=name_val;
		health=0;
		xp=0;	
		display();
	}
	player(string name_val,int health_val,int xp_val)
	{
		name=name_val;
		health=health_val;
		xp=xp_val;
		display();
	}
*/
	//Now using initialiser list delegating constructors
	

	player() :
		player("None",0,0)
		
	{
	
		cout<<"No args constructor"<<endl;	
		
	}
	player(string name_val):
		player(name_val,0,0)
	{
		cout<<"One args constructor"<<endl;
		
	}
	player(string name_val,int health_val,int xp_val):
		name(name_val),
		health(health_val),
		xp(xp_val)
	
	{
		
		display();
	}

	void display()
	{
		cout<<name<<" "<<health<<" "<<xp<<endl;
	}



};

int main()
{
	player empty;
	player frank("Frank");
	player villain("Villain",100,55);
	return 0;

}

/*

97 62 63 76-83 86-- None 0 0  No args constructor  --67
98 70 71 76-83 86-- Frank 0 0 One args constructor --73
99 76-83 86-- Villain 100 55--
*/
