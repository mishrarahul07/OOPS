#include<iostream>
using namespace std;

/*
	consider a class that has a pointer as an attribute

	constructor allocates storage dynamically and 
	initialises the pointer

	destructor releases the memory allocated by the 
	constructor

*/
  
/*
	Shallow copy is memberwise copy of all the attributes
	basically system provided copy constructor

	Utimately both the newly created object and the 
	original object both point to same memory location

	The problem arises when one of the object is destroyed
	by destructor which means that the compiler has 
	deleted the memory on the heap it created for 
	that object.
	
	But the other object is still pointing to this memory
	location.

	This will lead to errors


*/

class Shallow
{
private:
	int *data;
public:
	Shallow(int d)
	{
		data=new int; //allocated 
		*data=d;
	}

	Shallow(const Shallow &source)
	:data(source.data)
	{
		cout<<"Copy constructor - Shallow"<<endl
	}

	~Shallow()
	{
		delete data;
		cout<<"Destructor freeing data"<<endl;
	}

	void display_shallow(obj1)
	{
		cout<<*data<<endl;
	}

};


int main()
{
	Shallow obj1(100);
	display_shallow(obj1);
	cout<<"Hello World"<<endl;

	//error 

}


































