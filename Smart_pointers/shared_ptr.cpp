/*
A shared ptr provides shared ownership of heap 
object.
It can be copied and assigned and even moved




*/

#include<iostream>
#include<vector>
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

	friend ostream &operator<<(ostream &os,Test &rhs);

	
};
class Test1:public Test
{
public:
Test1()
	:Test()
	{
		cout<<"Test1 constructor { "<<get_data()<<" }"<<endl;
	}

	Test1(int data)
	:Test(data)
	{
		cout<<"Test1 constructor { "<<get_data()<<" }"<<endl;
	}
	
	~Test1()
	{
		cout<<"Test1 destructor { "<<get_data()<<" }"<<endl;
	}

};

ostream &operator<<(ostream &os,Test &rhs)
{
	os<<"The data for object called is "<<rhs.get_data()<<endl;
	return os;
}

void func(shared_ptr<Test>p)
{
	cout<<"Use count - "<<p.use_count()<<endl;
	// as p is also pointing to the same heap 
	//object therefore use count will be 
	//incremented by one
}

int main()
{
	//use count- number of ptr to a shared object
	//using any of that pointers

	// shared_ptr<int>p1(new int(100));
	// cout<<"Use count - "<<p1.use_count()<<endl;

	// shared_ptr<int>p2(p1);
	// cout<<"Use count - "<<p1.use_count()<<endl;

	// p1.reset();// p1 is nullptr and now p2.use_count()
	// //will be decremented
	// cout<<"After p1.reset()"<<endl;
	// cout<<"Use count p1 - "<<p1.use_count()<<endl;
	// cout<<"Use count p2 - "<<p2.use_count()<<endl;


	// cout<<" ============ ============== ============"<<endl<<endl;
	// shared_ptr<Test>ptr1=make_shared<Test>(100);
	// func(ptr1);
	// //^^here by are making a copy by passing of
	// // shared ptr 
	// cout<<"Use count - "<<ptr1.use_count()<<endl;
	
	// {
	// 	shared_ptr<Test>ptr2=ptr1;
	// 	cout<<"Use count - "<<ptr1.use_count()<<endl;	
	// 	{
	// 		shared_ptr<Test>ptr3=ptr1;
	// 		cout<<"Use count - "<<ptr1.use_count()<<endl;
	// 		ptr1.reset();

	// 	}
	// 	cout<<"Use count - "<<ptr1.use_count()<<endl;

	// }


	// cout<<"Use count - "<<ptr1.use_count()<<endl;

	cout<<" ============ ============== ============"<<endl<<endl;
	shared_ptr<Test>t1=make_shared<Test1>(100);
	shared_ptr<Test>t2=make_shared<Test1>(200);
	shared_ptr<Test>t3=make_shared<Test1>(300);

	vector<shared_ptr<Test>>tests;
	tests.push_back(t1);
	tests.push_back(t2);
	tests.push_back(t3);

	for(auto &t:tests)
	{
		cout<<*t<<endl;
		cout<<"Use count - "<<t.use_count()<<endl;
		cout<<endl;
	}













}