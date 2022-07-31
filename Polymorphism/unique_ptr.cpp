/*
	Unique pointers are unique
	you can't have multiple pointers pointing to 
	the same space
	
	Unique pointers can't be copied or assigned
	so it has no copy or assignment operators

	can be movers




*/
#include<iostream>
#include<memory>

using namespace std;

class Test
{
	int data;
public:
	Test()
	:data(0)
	{
		cout<<"Test constructor { "<<data<<" }"<<endl;
	}

	Test(int data)
	:data(data)
	{
		cout<<"Test constructor { "<<data<<" }"<<endl;
	}
	int get_data() const
	{
		return data;
	}
	~Test()
	{
		cout<<"Test destructor { "<<data<<" }"<<endl;
	}

};

int main()
{
	Test t1(1000);

	//unique_ptr<int>p1=new int
}