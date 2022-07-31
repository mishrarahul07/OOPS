#include <iostream>
#include<cstring>
using namespace std;
/*
operator-() // - sign
operator+() // + sign
operator*() // * sign
operator/() // / sign
operator%() // % sign
operator++() // ++ preincrement sign
operator++(int) // ++ postincrement sign
operator!() // ! operator

*/

class Mystring
{
	char *str;
public:
	friend bool operator==(Mystring &lhs,Mystring &rhs);
	friend Mystring operator+(Mystring &lhs,Mystring &rhs);
	friend Mystring operator-(Mystring &obj);
	friend Mystring operator+(Mystring &lhs,Mystring &&rhs);
	friend Mystring operator+(Mystring &&lhs,Mystring &rhs);
	friend Mystring operator+(Mystring &&lhs,Mystring &&rhs);
	//no args const
	Mystring()
	:str(nullptr)
	{
		str=new char[1];
		*str='\0';
	}

	//char* args constructor
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
	//copy constructor
	Mystring(Mystring &source)
	:str(nullptr)
	{
		str=new char[strlen(source.str)+1];
		strcpy(str,source.str);
		cout<<"Copy constructor used"<<endl;
	}

	//move constructor
	Mystring(Mystring &&source)
	{
		str=source.str;
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
	Mystring &operator=(Mystring &&rhs)
	{
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
		delete[] str;
	}
	

	void display()
	{
		cout<<str<<" : "<<getlength()<<endl;
	}

	int getlength()
	{

		return strlen(str);
	}
	char *get_str()
	{
		return str;
	}


};

	Mystring operator+(Mystring &lhs,Mystring &rhs)
	{
		char *newstr=new char[strlen(lhs.str)+strlen(rhs.str)+1];
		strcpy(newstr,lhs.str);
		strcat(newstr,rhs.str);
		Mystring temp(newstr);
		delete[] newstr;
		return temp;
	}

	Mystring operator-(Mystring &obj)
	{
		char *newstr=new char[strlen(obj.str)+1];
		strcpy(newstr,obj.str);
		for(int i=0;i<strlen(newstr);i++)
		{
			newstr[i]=tolower(newstr[i]);
		}

		Mystring temp(newstr);
		delete [] newstr;
		return temp;
	}

	bool operator==(Mystring &lhs,Mystring &rhs)
	{
		if(strcmp(lhs.str,rhs.str)==0)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	Mystring operator+(Mystring &lhs,Mystring &&rhs)
	{
		char *newstr=new char[strlen(lhs.str)+strlen(rhs.str)+1];
		strcpy(newstr,lhs.str);
		strcat(newstr,rhs.str);
		Mystring temp(newstr);
		delete[] newstr;
		return temp;
	}

	Mystring operator+(Mystring &&lhs,Mystring &rhs)
	{
		char *newstr=new char[strlen(lhs.str)+strlen(rhs.str)+1];
		strcpy(newstr,lhs.str);
		strcat(newstr,rhs.str);
		Mystring temp(newstr);
		delete[] newstr;
		return temp;
	}

	Mystring operator+(Mystring &&lhs,Mystring &&rhs)
	{
		char *newstr=new char[strlen(lhs.str)+strlen(rhs.str)+1];
		strcpy(newstr,lhs.str);
		strcat(newstr,rhs.str);
		Mystring temp(newstr);
		delete[] newstr;
		return temp;
	}


int main()
{
	cout<<boolalpha<<endl;

	Mystring larry("LARRY");
	Mystring moe("MOE");

	Mystring stooge = larry;
    larry.display();                                                                      // Larry
    moe.display();  

    cout << (larry == moe) << endl;                                         // false
    cout << (larry == stooge) << endl;                                      // true

    larry.display();                                                                    // Larry
    Mystring larry2 = -larry;
    larry2.display();

     Mystring stooges = larry +" "+ "Moe"; 
     stooges.display();

     Mystring two_stooges = moe + " " + "Larry";
    two_stooges.display();      
                                                   // Moe Larry
    Mystring three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();
}























