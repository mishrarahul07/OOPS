/*
	Virtual functions
	Redefined functions in the derived class are
	bound statically by default unless Virtual 
	keyword is used.

	Overriden functions are bound dynamically by 
	using the Vitual keyword.




*/

#include<iostream>
using namespace std;

class Account
{
public:
	virtual void withdraw(double amount)
	{
		cout<<"In Account::withdraw"<<endl;
	}
	virtual ~Account()
	{
		cout<<"Account::destructor"<<endl;
	}
};

class Checking:public Account
{
public:
	virtual void withdraw(double amount)
	{
		cout<<"In Checking::withdraw"<<endl;
	}
	virtual ~Checking()
	{
		cout<<"Checking::destructor"<<endl;
	}
};


class Savings:public Account
{
public:
	virtual void withdraw(double amount)
	{
		cout<<"In Savings::withdraw"<<endl;
	}

	virtual ~Savings()
	{
		cout<<"Savings::destructor"<<endl;
	}
};

class Trust:public Account
{
public:
	virtual void withdraw(double amount)
	{
		cout<<"In Trust::withdraw"<<endl;
	}

	virtual ~Trust()
	{
		cout<<"Trust::destructor"<<endl;
	}
};


int main()
{
	cout<<"====== Pointers ======"<<endl;
	Account *p1=new Account;
	Account *p2=new Savings;
	Account *p3=new Checking;
	Account *p4=new Trust;

	p1->withdraw(1000);
	p2->withdraw(1000);
	p3->withdraw(1000);
	p4->withdraw(1000);

	cout<<"====== Freeing up ======"<<endl;
	delete p1;
	delete p2;
	delete p3;
	delete p4;


}



























