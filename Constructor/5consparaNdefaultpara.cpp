#include<iostream>
using namespace std;
#include<string>

/*


	We can simpify our code and reduce the number
	of overloaded constructors

	Here we are only using one constructor which will
	do the work of all the remaining constructors

    can only function if you declare default constructor 
    inside class and three args constructor outside class

	the three args const is given some default values if
	arguement is not passed then those default values will
	be used

	giving default values happens while we do the 
	prototyping

*/

class player
{
private:
	string name;
	int health;
	int xp;

public:
	
	player(string name_val="None",int health_val=0,int xp_val=0);

	
	void display()
	{
		cout<<name<<" "<<health<<" "<<xp<<endl;
	}

	//  Player() {}    // Will cause a compiler error
	// as ambiguity

};

    player::player(string name_val,int health_val,int xp_val):
		name(name_val),
		health(health_val),
		xp(xp_val)
	
	{
		
		cout<<"Three Args constructor"<<endl;
		display();
	}


int main()
{
	player empty;
	player frank("Frank");
	player hero("Hero",100);
	player villain("Villain",100,55);
	return 0;

}
/* Output 

Three Args constructor
None 0 0
Three Args constructor
Frank 0 0
Three Args constructor
Hero 100 0
Three Args constructor
Villain 100 55
*/