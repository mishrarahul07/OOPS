/*
Inheritance provides a method of creating new classes from existing classes.

These new classes contain the data and behaviors of the existing classes.

Allows reuse of existing classes

Allows us to focus on common attributes among a set of classes

Inheritance
	process of creating new classes from existing classes
	reuse mechanism

Single Inheritance 
	a new class is created from another single class

Multiple Inheritance
	a new class is created from two or more other classes

Base Class (parent class)			

Derived class(child class)
	inherits attributes and operations from base class

Is-A relationship
	public inheritance
	derived classes are sub types of their base classes
	eg:- Employee is a person
		checking account is-a account
		circle is a shape

	

Composition
	has-a relationship
	eg:-
	Person has a account
*/
#include <iostream>
#include<string>
using namespace std;

class account
{
public:
	double balance;
	string name;
	void deposit(double amount)
	{
		cout<<"Account deposited with "<<amount<<endl;
	}
	void withdraw(double amount)
	{
		cout<<"Account withdrawn with "<<amount<<endl;
	}
	account()
	:balance(0),name("None"){

	}
	~account()
	{

	}
};

class savings_account:public account
{
public:
	double int_rate;
	savings_account():int_rate(3.5)
	{

	}
	~savings_account()
	{

	}
	void deposit(double amount)
	{
		cout<<"Savings Account deposited with "<<amount<<endl;
	}

	void withdraw(double amount)
	{
		cout<<" Savings Account withdrawn with "<<amount<<endl;
	}
};

int main()
{
	cout<<"\n Account =========="<<endl;
	account acc;
	acc.deposit(2000);
	acc.withdraw(500);

	cout<<endl;

	account *p_acc=nullptr;

	cout<<" Account using ptr"<<endl;
	p_acc=new account;
	p_acc->deposit(1000);
	p_acc->withdraw(500);
	delete p_acc;

	cout<<"\nSavings Account======= "<<endl;
	savings_account sav_acc;
	sav_acc.deposit(2000);
	sav_acc.withdraw(500);

	cout<<endl;

	cout<<" Savings Account using ptr"<<endl;

	savings_account *p_sav_acc=nullptr;
	p_sav_acc=new savings_account;
	p_sav_acc->deposit(1000);
	p_sav_acc->withdraw(500);




	return 0;




















}






























