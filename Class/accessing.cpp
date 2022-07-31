#include<iostream>
#include<string>
#include<vector>
using namespace std;

class player
{
	public:
	// you can put attributes here
	

	string name;
	int health;
	int xp;

	// you can put methods here
	void talk(string text_to_say)
	{
		cout<<name<<" says "<<text_to_say<<endl;
	}
	bool is_dead();





};

class account
{
	public:
    //attributes
    string name;
    double balance=0.0;
    
    //methods
    bool deposit(double bal)
    {
    	balance+=bal;
    }
    bool withdraw(double bal)
    {
    	balance-=bal;
    }
    
    
};




int main()
{
	account ayush_account;
	account frank_account;

	frank_account.balance=5000;
	frank_account.deposit(1000.0);
	frank_account.withdraw(500.0);
	
	cout<<frank_account.balance<<endl;
	
	player frank;
	player hero;

	frank.name="Frank";
	frank.health=100;
	frank.xp=12;
	frank.talk("Hi there");


// using pointer
	player *enemy=new player;

	(*enemy).health=100;
	enemy->name="Enemy";
	enemy->xp=15;

	enemy->talk("I will destroy you");












}	