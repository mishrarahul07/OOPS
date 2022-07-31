//constructor initialisation list

/*
more efficient
initialisation list immediately follows the parameter list
initializes the data members as the object is created
order of initialization is the order of declaration in the class
irrespective of order in initialiser list

This happens before the body of the constructor is 
executed

*/

#include<iostream>
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
	//Now using initialiser list

	player() :
		name("None"),
		health(0),
		xp(0)
	{
		
		display();
	}
	player(string name_val):
		name(name_val),
		health(0),
		xp(0)
	{
		
		display();
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
3 constructor_initialisation.cpp

89 52 53 54 55 58   None 0 0 

90 60 61 62 63 66   Frank 0 0

91 68 69 70 71 75   Villain 100 55



*/

