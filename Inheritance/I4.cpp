/*

In this we are deliberately calling specific constructors
fron BASE class using initialiser list
*/
#include<iostream>
using namespace std;

class Base
{
private:
	int value;
public:
	Base():value(0)
	{
		cout<<"Base no args constructor"<<endl;

	}

	Base(int x):value(x)
	{
		cout<<"Base(int) args constructor called"<<endl;
	}

	~Base()
	{
		cout<<"Base destructor called"<<endl;
	}
};

class Derived:public Base
{
private:
	int doubled_value;
public:
	Derived():Base(),doubled_value(0)
	{
		cout<<"Derived No args constructor"<<endl;
	}

	Derived(int x):Base(x),doubled_value(x*2)
	{
	 	cout<<"Derived Double Int args constructor"<<endl;
	}

	~Derived()
	{
		cout<<"Derived destructor called"<<endl;
	}
}; 

int main()
{
	Base b;

	Base c(100);
	Derived d;
	Derived e(50);
	return 0;

}