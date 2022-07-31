 /*
Copy/Move constructors and assignment operators
are not automatically inherited from the base class.

We can explicitly invoke these special constructors
and the overloaded assignment operators in our base
class from derived class if necessary.

If we need to copy a Derived object then we need to 
ensure that the base part of that derived object is 
also copied.

If the Base class has a copy constructor then we
can explicitly invoke it in our derived copy 
constructors

But the thing is Base copy constructor requires a 
base object as arguement but we pass Derived object
because Derived is a base. 

The compiler uses a technique called slicing. It 
takes out only the base part from the Derived object
passed.

Often you do not need your own copy/assignment 
operators.

IF you DO NOT define then in derived then the 
compiler will create them automatically and call
the base class's version

IF you DO provide the Derived Versions
	then YOU must invoke the Base Versions 
	explicitly yourself.

Be careful with raw pointers.
	Use deep copy semantics.


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
		cout<<"Base No-args constructor"<<endl;
	}
	Base(int x):value(x)
	{
		cout<<"Base Int-args constructor"<<endl;
	}

	Base(const Base &other):value(other.value)
	{
		cout<<"Base Copy constructor"<<endl;
	}

	// Base &operator=(const Base &rhs)
	// {
	// 	cout<<"Base operator ="<<endl;
	// 	if(*this==rhs)
	// 	{
	// 		return *this;
	// 	}
		
	// 	value=rhs.value;
	// 	return *this;
		
	// }

	~Base()
	{
		cout<<"Base Destructor"<<endl; 
	} 
};

class Derived:public Base
{
	int doubled_value;

public:
	Derived():Base()
	{
		cout<<"Derived no args constructor"<<endl;

	}
	Derived(int x):Base(x),doubled_value(x*2)
	{
		cout<<"Derived int args constructor"<<endl;
		
	}
	Derived(const Derived &other)
	:Base(other),doubled_value(other.doubled_value)
	{
		cout<<"Derived Copy constructor"<<endl;
	}
	~Derived()
	{
		cout<<"Derived Destructor"<<endl;
	}
	
};


int main()
{
	Base b(100); //overloaded const
	Base b1(b);//copy const  
	//b=b1;

	cout<<endl;

	Derived d(100);//overloaded const
	Derived d1(d); //copy const





}




























