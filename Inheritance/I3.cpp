 /*
 	During initialisation 

 	Base part of the derived class must be initialized BEFORE the derived class part is intialized

	When a derived object is created 
		base class constructor executes then
		derived class constructor executes
	
	Destructors are called in opposite order

	A derived class does not inherit 
		Base class constructor
		Base class destructor
		Base class overloaded assignment operator
		Base class friend functions

	However we can invoke base class constructors and desturctors
		
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
	Derived():doubled_value(0)
	{
		cout<<"Derived No args constructor"<<endl;
	}

	Derived(int x):doubled_value(x*2)
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