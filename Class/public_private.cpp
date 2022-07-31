#include<iostream>
#include<string>
#include<vector>
using namespace std;

class player
{
	// you can put attributes here
	

	string name;
	int health;
	int xp;

	// you can put methods here
	public:
	void talk(string text_to_say)
	{
		cout<<name<<" says "<<text_to_say<<endl;
	}
	bool is_dead();





};






int main()
{
	
	
	
	player frank;
	player hero;

	frank.name="Frank";
	frank.health=100;
// 	frank.xp=12;
// 	frank.talk("Hi there");


// // using pointer
// 	player *enemy=new player;

// 	(*enemy).health=100;
// 	enemy->name="Enemy";
// 	enemy->xp=15;

// 	enemy->talk("I will destroy you");












}	