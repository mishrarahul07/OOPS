/*
Polymorphism
	1)Compile time/early binding/ static binding
	2)Runtime/late binding/ dynamic binding

Runtime Polymorphism
	Being able to assign different meanings to
	the same function at run time	

Allows us to program more abstractly
	Think general vs specific
	Let C++ figure out which function to call at
	runtime

Not the default in C++, runtime polymorphism is 
achieved via 
	Inheritance
	Base class pointers or refrences
	virtual functions

C++ is static by default
*/
#include<iostream>
using namespace std;

class Base
{
public:
	void say_hello()
	{
		cout<<"Hello I am a base class object"<<endl;

	}
};

class Derived:public Base
{
public:
	void say_hello()
	{
		cout<<"Hello I am a derived class object"<<endl;

	}	
};

void greetings(Base &obj)
{
	cout<<"Greetings ";
	obj.say_hello();
}

int main()
{
	Base b;
	b.say_hello();

	Derived d;
	d.say_hello();

	greetings(b);
	greetings(d);//problem

	Base *ptr=new Derived;
	ptr->say_hello();
}

















































































