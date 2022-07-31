#include<iostream>
using namespace std;
  
class Mystring
{
private:
	friend ostream &operator<<(ostream &os,const Mystring &rhs);
	friend istream &operator>>(ostream &is,Mystring &rhs);
	char *str;
public:
	
	Mystring() 
    : str(nullptr) 
    {
	    str = new char[1];
	    *str = '\0';
	}

// Overloaded constructor
	Mystring(const char *s) 
    : str(nullptr) 
    {
        if (s==nullptr) 
        {
            str = new char[1];
            *str = '\0';
        } else 
        {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
	}

// Copy constructor
	Mystring(const Mystring &source) 
    : str(nullptr) 
    {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
        std::cout << "Copy constructor used" << std::endl;

	}

// Move constructor
	Mystring( Mystring &&source) 
    :str(source.str) 
    {
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
	}	

 // Destructor
~Mystring()
 {
    delete [] str;
}

 // Copy assignment
	Mystring &operator=(const Mystring &rhs)
	{

	    cout << "Using copy assignment" << std::endl;

	    if (this == &rhs) 
	    {
	        return *this;
	    }
	    delete [] str;
	    str = new char[strlen(rhs.str) + 1];
	    strcpy(str, rhs.str);
	    return *this;
	}

// Move assignment
	Mystring &operator=( Mystring &&rhs) 
	{
	    std::cout << "Using move assignment" << std::endl;
	    if (this == &rhs) 
	        return *this;
	    delete [] str;
	    str = rhs.str;
	    rhs.str = nullptr;
	    return *this;
	}


// Display method
	void display() const 
	{
	    cout << str << " : " << get_length() << std::endl;
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
//insertion

ostream &operator<<(ostream &os,const Mystring &rhs)
{
	os<<rhs.str;
	return os;
}

istream &operator>>(istream &in, Mystring &rhs)
{
	char *buff=new char[1000];
	in>>buff;
	rhs=Mystring(buff);
	delete[]buff;
	return in;
}


int main()
{
	Mystring larry ("Larry");
    Mystring moe ("Moe");
    Mystring curly;
    
    cout << "Enter the third stooge's first name: ";
    cin >> curly;
    
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;
    
    cout << "\nEnter the three stooges names separated by a space: ";
    cin >> larry >> moe >> curly;
    
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;
    
    return 0;
}