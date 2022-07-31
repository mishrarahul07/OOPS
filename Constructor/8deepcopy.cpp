#include<iostream>
using namespace std;


/*
	in deep copying We don't just simply copy the pointer 
	instead  we copy the data pointed to by the pointer.

	This usually means that we have to allocate storage 
	for the copy data and then perform the copy 

	with deep copy Each object will have a pointer to unique
    storage in the heap and both areas will contain 
    the same data.

    You always want to use a copy constructor that does a deep 
    copy when you have raw c++ pointers.
*/

class deep
{
private:
	int *data;
public:
	void set_data(int d)
	{
		*data=d;
	}
	int get_data()
	{
		return *data;
	}
	//constructor
	deep(int d);
	deep(const deep &source);
	//destructor
	~deep();


};

deep::deep(int d)
{
	data=new int;
	*data=d;
}

deep::deep(const deep &source)
	:deep(*source.data)
// we are using delegating constructor over here which is 
//calling the int arg const which itself creates a new 
//memory location for the new object	
{
	cout<<"Copy constructor deep copy"<<endl;
}

deep::~deep()
{
	delete data;
	cout<<"Destructor freeing data"<<endl;

}

void display_deep(deep s)
{
	cout<<s.get_data()<<endl;
}

int main()
{
	deep obj1(100);
	display_deep(obj1);

	deep obj2(obj1);

	return 0;
}	