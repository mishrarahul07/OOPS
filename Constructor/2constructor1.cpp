#include<iostream>
using namespace std;

/*
Special member class
invoked during object creation
useful for initialisation
same name as class
no return type is specified
can be overloaded
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

};


int main()