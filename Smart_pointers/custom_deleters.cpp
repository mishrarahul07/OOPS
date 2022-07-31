/*

*/
#include<iostream>
using namespace std;
class Test
{
public:
	int data;

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

void my_delete(Test *ptr)
	{
		cout<<"Using my custom delete function "<<endl;
		delete ptr;
	}



int main()
{

//using a function
	{
		shared_ptr<Test>ptr1(new Test(100),my_delete);
	}

{
		shared_ptr<Test>ptr2(new Test(1000), 
		[](Test *ptr)
		{
			cout<<"Using my custom delete function "<<endl;
			delete ptr;
		});

}























}