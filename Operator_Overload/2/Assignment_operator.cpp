/*
C++ provides a default assignment operator used 
for assigning one object to another.

It is different from initialisation. 

Default is memberwise assignment (shallow copy)
With a raw pointer deep copy should be done


*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Mystring
{
	char *str;
public:
	Mystring()
	:str(nullptr)
	{
		str=new char[1];
		*str='\0';
	}

	Mystring(const char *s)
	:str(nullptr)
	{
		if(s==nullptr)
		{
			str=new char[1];
			*str='\0';
		}
		else
		{
			str=new char[strlen(s)+1];
			strcpy(str,s);
		}
	
	}





	Mystring(const Mystring &source)
	:str(nullptr)
	{
		// cout<<"Copy constructor"<<endl;
		str=new char[strlen(source.str)+1];
		strcpy(str,source.str);

	}

	Mystring & operator=(const Mystring &rhs)
	{
		cout<<"Copy assignment "<<endl;
		if(this==&rhs)
		{
			return *this;
		}

		delete []this->str;
		str=new char[strlen(rhs.str)+1];
		strcpy(this->str,rhs.str);
		return *this ;
	}

	void display() const
	{
		cout<<str<<" : "<<get_length()<<endl;
	}

	int get_length() const
	{
		return strlen(str);
	}

	const char* get_str() const
	{
		return str;
	}


};




int main()
{
	Mystring a("Hello"); //char* args constructor
	Mystring b;			 //no args constructor
	b=a;				 //copy assignment

	b="This is a test";	 	
	cout<<b.get_str()<<endl;

//we can also use 
	b.operator=("This is Ayush");
	cout<<b.get_str()<<endl;

	Mystring empty;
	Mystring larry("larry");
	Mystring stooge(larry);
	Mystring stooges;
	
	empty=stooge;
	empty.display();
	larry.display();
	stooge.display();

	stooges="larry, moe and cury";
	stooges.display();

	vector<Mystring>stooges_vec;
	stooges_vec.push_back("larry");
	stooges_vec.push_back("moe");
	stooges_vec.push_back("curly");

	cout<<"=========Loop 1=========="<<endl;

	for(Mystring s:stooges_vec)
	{
		s.display();
	}

	cout<<"=========Loop 2=========="<<endl;

	for(Mystring s:stooges_vec)
	{
		s="Changed";//copy assignment
	}

	cout<<"=========Loop 3=========="<<endl;

	for(Mystring s:stooges_vec)
	{
		s.display();
	}

cout<<"No changed has happened so far"<<endl<<endl;

	cout<<"=========Loop 1=========="<<endl;

	for(Mystring s:stooges_vec)
	{
		s.display();
	}

	cout<<"=========Loop 2=========="<<endl;

	for(Mystring &s:stooges_vec)
	{
		s="Changed";//copy assignment
	}

	cout<<"=========Loop 3=========="<<endl;

	for(Mystring s:stooges_vec)
	{
		s.display();
	}


	cout<<"Changed has happened "<<endl<<endl;

	stooges_vec.push_back(larry);
	stooges_vec.push_back(stooges);


	for(Mystring s:stooges_vec)
	{
		s.display();
	}















}