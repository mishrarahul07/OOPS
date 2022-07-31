/*
	Unique pointers are unique
	you can't have multiple pointers pointing to 
	the same space
	
	Unique pointers can't be copied or assigned
	so it has no copy or assignment operators

	can be movers
	
	you dont need to delete it. It automatically
	deletes it when not in use




*/
#include<iostream>
#include<memory>
#include<vector>
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
class Test1:public Test
{
public:
Test1()
	:Test()
	{
		cout<<"Test1 constructor { "<<data<<" }"<<endl;
	}

	Test1(int data)
	:Test(data)
	{
		cout<<"Test1 constructor { "<<data<<" }"<<endl;
	}
	
	~Test1()
	{
		cout<<"Test1 destructor { "<<data<<" }"<<endl;
	}

};

ostream &operator<<(ostream &os,Test &rhs)
{
	os<<"The data for object called is "<<rhs.get_data()<<endl;
	return os;
}

int main()
{
	// Test t1(1000);
	// Test *t2=new Test(1100);
	// delete t2;
	cout<<endl<<endl;
	unique_ptr<Test>t3(new Test(100));

	unique_ptr<Test>t4=make_unique<Test>(1200);	
	cout<<endl<<endl;

	// unique_ptr<Test>t5;
	// t5=t3;
	// it does not happen because it can't be assigned
	// or copied because only one owner is allowed	

	unique_ptr<Test>t6;
	t6=move(t3);
	//it moves t3's content to t6 and then makes t3
	//a nullptr
	cout<<endl;
	//checks if t3 a mullptr or not
	if(!t3)
	{
		cout<<"t3 is nullptr"<<endl;
	}

	cout<<"t6 has "<<t6->get_data()<<endl;

	cout<<*t6<<endl;
	cout<<endl;

	unique_ptr<Test>a1(make_unique<Test1>(50));
	cout<<*a1;

	vector<unique_ptr<Test>>tests;

	tests.push_back(make_unique<Test1>(1234));
	tests.push_back(make_unique<Test1>(2345));

	// for(auto tes:tests)
	// {
	// 	cout<<*tes<<endl;
	// } ERROR because it copies unique ptr to tes

	//a refrence to tests is made which is an
	//alias to the unique ptr
	for(auto &tes:tests)
	{
		cout<<*tes<<endl;
	}

}