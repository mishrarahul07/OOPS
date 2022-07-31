#include<iostream>
#include<vector>
#include<memory>

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


unique_ptr<vector<shared_ptr<Test>>> make()
{
	unique_ptr<vector<shared_ptr<Test>>>v1=make_unique<vector<shared_ptr<Test>>>();
	return v1;
}

void fill(vector<shared_ptr<Test>>&vec,int num)
{
	cout<<"================================"<<endl;
	int data;
	shared_ptr<Test>s1;

	for(int i=1;i<=num;i++)
	{
		cout<<"Enter data point ["<<i<<"] : ";
		cin>>data;
		s1=make_shared<Test>(data);
		vec.push_back(s1);
	}
}

void display(vector<shared_ptr<Test>>&vec)
{
	cout<<endl<<"======================================"<<endl;
	for(int i=1;i<vec.size();i++)
	{
		cout<<vec[i]->get_data()<<endl;;
	}

}
ostream &operator<<(ostream &os,Test &rhs)
{
	os<<"The data for object called is "<<rhs.get_data()<<endl;
	return os;
}
int main()
{
	unique_ptr<vector<shared_ptr<Test>>>vec_ptr;
	vec_ptr=make();
	cout<<"How many data points do you want to enter "<<endl;
	int num;
	cin>>num;
	fill(*vec_ptr,num);
	display(*vec_ptr);
	return 0;




}