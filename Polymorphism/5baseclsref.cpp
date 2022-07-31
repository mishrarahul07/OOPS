/*
We can use Base class refrences with dynamic 
polymorphism
	Useful when we pass objects to functions that
	expect a Base class refrence
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

void do_withdraw(Account &account,double amount)
{
	account.withdraw(amount);
	//&account is not a refrence to an Account
	//object. It is an account refrence
}

int main()
{
	Account a;
	Account &ref=a;
	ref.withdraw(1000);

	Trust t;
	Account &ref1=t;
	ref1.withdraw(1000);

	Account a1;
	Savings a2;
	Checking a3;
	Trust a4;

	do_withdraw(a1,1000);
	do_withdraw(a2,2000);
	do_withdraw(a3,3000);
	do_withdraw(a4,4000);
	cout<<endl<<endl;

	//this will make &account a ref to a1,a2,a3,a4;



}




























































