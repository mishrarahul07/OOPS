#include<iostream>
using namespace std;

class dummy
{
private: 
	int a,b;
	int *p;

public:
	dummy()
	{
		p=new int;
	}

	void setdata(int x,int y,int z)
	{
		a=x;
		b=y;
		*p=z;

	}

	void showdata()
	{
		cout<<"a: "<<a<<" b: "<<b<<" *p: "<<*p<<endl;
	}

	dummy(dummy &d)
	{
		a=d.a;
		b=d.b;
		p=new int;  // in shallow it would be p= d.p
		*p=*(d.p);  //value of p pointer from d is stored in 
		// the new p
	}

	~dummy()
	{
		delete p;
	}
};


int main()
{
	dummy d1;
	d1.setdata(3,4,5);
	dummy d2=d1; 
	d2.showdata();
	d1.showdata();
}