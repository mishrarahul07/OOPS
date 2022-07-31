#include<iostream>
#include<cstring>
using namespace std;

class Mystring
{
	char *str;

public:
	friend ostream &operator<<(ostream &os,const Mystring &rhs);
	friend istream &operator>>(istream &in, Mystring &rhs);
	//no args constructor
	Mystring()
	:str(nullptr)
	{
		str=new char[1];
		*str='\0';
	}
	//char * args const
	Mystring(char *s)
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
		
	}

	//move constructor
	Mystring(Mystring &&source)
	{
		str=source.str;
		source.str=nullptr;
		
	}

	~Mystring()
	{
		delete[] str;
	}	

	Mystring &operator-()
	{
		char *newstr=new char[strlen(str)+1];
		for(int i=0;i<strlen(str);i++)
		{
			newstr[i]=tolower(str[i]);
		}
		strcpy(str,newstr);
		delete[] newstr;
		return *this;
	}

	char* getstr()
	{
		return str;
	}

	Mystring &operator=(Mystring &rhs)
	{
		if(*str==*rhs.str)
		{
			return *this;
		}
		delete[]str;
		str= new char[strlen(rhs.str)+1];
		strcpy(str,rhs.str);
		return *this;

	}

	Mystring &operator=(Mystring &&rhs)
	{
		if(*str==*rhs.str)
		{
			return *this;
		}
		delete[]str;
		str= new char[strlen(rhs.str)+1];
		str=rhs.str;
		rhs.str=nullptr;
		return *this;

	}
	bool operator==(Mystring &rhs)
	{
		if(strcmp(str,rhs.str)==0)
		{
			
			return true;
		}
		else
		{
			
			return false;
		}
	}
	bool operator>(Mystring &rhs)
	{
		if(strcmp(str,rhs.str)>0)
		{
			
			return true;
		}
		else
		{
			
			return false;
		}
	}

	bool operator<(Mystring &rhs)
	{
		if(strcmp(str,rhs.str)<0)
		{
			
			return true;
		}
		else
		{
			
			return false;
		}
	}
	bool operator!=(Mystring &rhs)
	{
		if(strcmp(str,rhs.str)!=0)
		{
			
			return true;
		}
		else
		{
			
			return false;

		}
	}	

	Mystring operator+(Mystring &obj)
	{
		char *newstr=new char[strlen(str)+strlen(obj.str)+2];
		strcpy(newstr,str);
		strcat(newstr," ");
		strcat(newstr,obj.str);
		Mystring newobj(newstr);
		delete[]newstr;
		return newobj;
	}

	Mystring operator+(Mystring &&obj)
	{
		char *newstr=new char[strlen(str)+strlen(obj.str)+2];
		strcpy(newstr,str);
		strcat(newstr," ");
		strcat(newstr,obj.str);
		Mystring newobj(newstr);
		delete[]newstr;
		return newobj;
	}

	Mystring &operator+=(Mystring &obj)
	{
		char *newstr=new char[strlen(str)+strlen(obj.str)+2];
		strcpy(newstr,str);
		strcat(newstr," ");
		strcat(newstr,obj.str);
		delete[]str;
		str=new char[strlen(newstr)];
		strcpy(str,newstr);
		delete[]newstr;
		return *this;	
	}
	Mystring &operator+=(Mystring &&obj)
	{
		char *newstr=new char[strlen(str)+strlen(obj.str)+2];
		strcpy(newstr,str);
		strcat(newstr," ");
		strcat(newstr,obj.str);
		delete[]str;
		str=new char[strlen(newstr)];
		strcpy(str,newstr);
		delete[]newstr;
		return *this;	
	}
	Mystring &operator*(int x)
	{
		int y=x*(strlen(str));
		char *newstr=new char[y+1];
		newstr=strcpy(newstr,str);
		for(int i=1;i<x;i++)
		{
			strcat(newstr,str);
		}
		delete[]str;
		str=new char[strlen(newstr)];
		strcpy(str,newstr);
		delete[]newstr;
		return *this;

	}
	Mystring &operator*=(int x)
	{
		int y=x*(strlen(str));
		char *newstr=new char[y+1];
		newstr=strcpy(newstr,str);
		for(int i=1;i<x;i++)
		{
			strcat(newstr,str);
		}
		delete[]str;
		str=new char[strlen(newstr)];
		strcpy(str,newstr);
		delete[]newstr;
		return *this;

	}

	
};

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
	Mystring ayush("AYUSH");
	Mystring sania("SANIA");
	Mystring b=-ayush;
	cout<<b.getstr()<<endl;
	b=-sania;
	cout<<b.getstr()<<endl;
	b="ayush";
	cout<<b.getstr()<<endl;
	cout<<"B is equal to "<<b<<endl;
	Mystring mom;
	cout<<"Enter Mom"<<endl;
	cin>>mom;
	cout<<mom<<endl;
	Mystring housewife(mom);
	cout<<boolalpha;
	cout<<endl;
	cout << (mom==housewife) << endl;                                         // false
    cout << (mom!=housewife) << endl;
    cout<<(ayush>sania)<<endl;
    cout<<(ayush<sania)<<endl;
    cout<<(ayush==sania)<<endl;

    Mystring Ayush("Ayush");
    Mystring Praveen("Praveen");
    Mystring Kaushik("Kaushik");
    Ayush+=Kaushik;
    cout<<Ayush<<endl;

    Mystring coder=sania+Kaushik;
    cout<<coder;

    Mystring family=Ayush+" "+sania+" "+Praveen+" "+mom;
    cout<<family<<endl;

    Mystring cat("Nattu");
    cat+="Loves papa";
    cout<<cat<<endl;

    Mystring laugh("ha");
    laugh*4;
    cout<<laugh;

    cat*=2;
    cout<<endl<<cat;

}