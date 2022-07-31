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
	void talk(string);
	bool is_dead();





};

class account
{
    //attributes
    string name="Account";
    double balance=0.0;
    
    //methods
    bool deposit(double);
    bool withdraw(double);
    
    
};




int main()
{
	account ayush_account;
	account frank_account;
	
	
	player frank;
	player hero;

	player players[]={frank,hero};

	vector<player>player_vec={frank};
	player_vec.push_back(hero);



	//created and deleted in runtime
	player *enemy=nullptr;
	enemy=new player;

	delete enemy;

























}	