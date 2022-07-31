#include<iostream>
using namespace std;

class Base
{
	// Friends of bas have accessto all 3 private public and protected

public:
	int a=0;
	void display()
	{
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
protected:
	int b=0;
private:
	int c=0;

};
/*
Friends of derived only have access to what derived has access to
a will be public
b will be protected
c will not be accessible
*/
class Derived: public Base
{
	void access_base_members()
	{
		a=100;
		b=200;
		//c=300;//not accessible ERROR
		cout<<a<<" "<<b<<endl;
	}
};

int main()
{
	cout<<"=====Base member access from base objects"<<endl;	
 	Base base;
 	base.a=100;//ok
 //	base.b=200;//error
 //	base.c=300;//error

	cout<<"=====Derived member access from derived objects"<<endl;	
	Derived d;
	d.a=100;
//	d.b=200; protected error
//	d.c=300; private not accessible error

	return 0;






}