/*
exceptions can also be thrown from within the class

Method
	These work the same way as the functions do

Constructor
	-Constructors may fail
	-Constructors do not return any value
	-Throw an exception in the constructor if 
	 you cannot initialise an object

Destructor
	Do not throw exceptions from a destructor

*/
/*

*/
#include<iostream>
#include<memory>
using namespace std;

class IllegalBalanceException :public exception
{
public:
	IllegalBalanceException() noexcept=default;
	~IllegalBalanceException()noexcept=default;
	virtual const char* what() const noexcept
	{
		return "Illegal balance exception";
	}
};
class Account
{
	string name;
	double balance;

public:
	Account()
	:name("None"),balance(0)
	{

	}
	Account(string name,double balance)
	:name(name),balance(balance)
	{
		if(balance<0)
		{
			throw IllegalBalanceException();
		}
	}
	~Account();
	
};

class Checking_account:public Account
{
public:
	Checking_account()
	:Account()
	{

	}
	Checking_account(string name,double balance)
	:Account(name,balance)
	{

	}
	~Checking_account()
	{

	}
	
};

int main()
{
	try
	{
		unique_ptr<Account>ayush_account=make_unique<Checking_account>("Ayush",10000);	
		cout<<"Use Ayush's account"<<endl;
	}

	catch(const IllegalBalanceException &ex)
	{
		cerr<<ex.what()<<endl;
	}
	

}