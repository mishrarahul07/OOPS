#include<iostream>
using namespace std;

/*
Special member class
invoked during object is destroyed
only 1 destructor is allowed per class
same name as class proceeded by a (~) sign
no return type and no parameters
cannot be overloaded
*/


class account
{
	private:
	std:: string name;
	double balance;

	public:
	//constructors
	account();
	account(string name, double balance);
	account(string name);
	account(double balance);

	//destructor
	~account();	

};


int main()
{
	account ayush;
	account savita("savita");
	account praveen("praveen",1000);
	account sania(1000);
	
}