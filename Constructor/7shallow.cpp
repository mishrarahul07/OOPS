#include<iostream>
using namespace std;

class shallow
{
private:
	int *data;

public:
	void set_data_value(int d)
	{
		*data=d;
	}
	int get_data_value()
	{
		return *data;
	}
	//constructor

	shallow(int d);
	//copy
	shallow(const shallow &source);
	//destructor

	~shallow();
};

shallow::shallow(int d)
{
	data=new int;
	*data=d;
}

shallow::shallow(const shallow &source)
	:data(source.data)  //data in blue is the data of the 
	//object to which we are copying the source
{
	cout<<"Copy const- shallow copy"<<endl;
} 

shallow::~shallow()
{
	delete data;
	cout<<"Destructor freeing data"<<endl;
}


void display_shallow(shallow s)
{
	cout<<s.get_data_value()<<endl;
}

int main()
{
	shallow obj1(100);
	display_shallow(obj1);
	/*
	now data of s and data of obj1 point towards same integer
	100 as set by the user

	now as the function display_shallow goes out of scope 
	the destructor is called for "s" which means that the 
	memory is destroyed but the obj1 points to 
	that memory location only and that memory location now does
	not exist


		
	*/
	// shallow obj2(obj1);
	// obj2.set_data_value(1000);
	return 0;
}




































