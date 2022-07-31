/*
weak ptr 
	points to an object of any type on the heap
	does not participate in the owning relationship
	always created from a shared ptr

	Does not increment or decrement refrence use
	count

*/

#include<iostream>
using namespace std;


class B;

class A
{
	shared_ptr<B>b_ptr;

public:
	void set_B(shared_ptr<B>&b)
	{
		b_ptr=b;
	}
	A()
	{
		cout<<"A constructor "<<endl;

	}
	~A()
	{
		cout<<"A destructor "<<endl;
	}
	
};

class B
{
	weak_ptr<A>a_ptr;
public:
	void set_A(shared_ptr<A>&a)
	{
		a_ptr=a;
	}
	B()
	{
		cout<<"B constructor "<<endl;
	}
	~B()
	{
		cout<<"B destructor "<<endl;	
	}
	
};
int main()
{
	shared_ptr<A>a=make_shared<A>();
	shared_ptr<B>b=make_shared<B>();
	
	a->set_B(b);
	b->set_A(a);
	//if we dont make any one weak ptr then 
	// memory leak occurs as destructors dont
	//get called




}