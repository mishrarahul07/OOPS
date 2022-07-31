#include<iostream>
#include <vector>
using namespace std;
/*
	&& means R value refrence



*/
class Mystring
{
	char *str;

public:
	Mystring() 
    : str(nullptr)
    {
    	str = new char[1];
    	*str = '\0';
    	cout<<"No args constructor"<<endl;
	}

	Mystring(const char *s)
	:str(nullptr)
	{
		cout<<"Char* args constructor"<<endl;	
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
	//copy constructor
	Mystring(const Mystring &source)
	:str(nullptr)
	{
		str=new char[strlen(source.str)+1];
		strcpy(str,source.str);
		cout<<"Copy Constructor used"<<endl;
	}
	//move constructor
	Mystring(Mystring &&source)
	:str(source.str)
	{
		source.str=nullptr;
		cout<<"Move constructor used"<<endl;

	}
	//copy assignment
	Mystring &operator=(Mystring &rhs)
	{
		cout<<"Using copy assignment"<<endl;
		if(this==&rhs)
		{
			return *this;
		}
		delete []str;
		str=new char[strlen(rhs.str)+1];
		strcpy(str,rhs.str);
		return *this;
	}
	//move assignment
	Mystring &operator=( Mystring &&rhs)
	{
		cout<<"Using move assignment"<<endl;
		if(this==&rhs)
		{
			return *this;
		}

		delete [] str;
		str=rhs.str;
		rhs.str=nullptr;
		return *this;

	}
	
		
	~Mystring()
	{
		if(str==nullptr)
		{
			cout<<"Calling Destructor for Mystring:nullptr"<<endl;
		}
		else
		{
			cout<<"Calling Destructor for Mystring : "<<str<<endl;	
		}
		delete []str;

	}

// Display method
void display() const 
{
    cout << str << " : " << get_length() << endl;
}

 // getters
 int get_length() const 
 { 
 	return strlen(str); 
 }
 const char *get_str() const 
 { 
 	return str;
 }


};





int main()
{
	// Mystring a("Hello");
	// cout<<endl;
	// //a temp object is created with Hola char* 
	// //arguement
	// a=Mystring("Hola");
	// a="Bonjour";

	// Mystring empty;                      // no-args constructor
 //    Mystring larry("Larry");             // overloaded constructor
 //    Mystring stooge {larry};            // copy constructor 
 //    Mystring stooges;   
 //    cout<<endl; 

	// empty = stooge;                     // copy assignment operator
	// cout<<endl;                                                   // stooge is an l-value
    
 //    empty = "Funny";                    // move assignment operator
 //    cout<<endl;                                               // "Funny" is an r-value
    
 //    empty.display();
 //    larry.display();
 //    stooge.display();
 //    empty.display();
    
 //    stooges = "Larry, Moe, and Curly";  
 //    stooges.display();
 //    cout<<endl;
 //    cout<<endl;


    vector<Mystring> stooges_vec;
 	stooges_vec.push_back("Larry");                // Move constructor
    stooges_vec.push_back("Moe");                // Move constructor
    stooges_vec.push_back("Curly");              // Move constructor    
    
//     cout << "=== Loop 1 ==================" << endl;
//     for (const Mystring &s: stooges_vec) 
//         s.display();
        
//     cout << "=== Loop 2 ==================" << endl;
//     for (Mystring &s: stooges_vec)
//         s = "Changed";                                      // move assignment
        
//     cout << "=== Loop 3 ==================" << endl;
//     for (const Mystring &s: stooges_vec) 
//         s.display();
    


}