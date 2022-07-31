#include<cstring>
#include<iostream>
#include"Mystring.hpp"
//
Mystring::Mystring()
:str(nullptr)
{
	str=new char[1];
	*str='\0';

}

Mystring::Mystring(const char *s)
:str(nullptr)
{
	if(s==nullptr)
	{
		str=new char[1];
		*str='\0';
	}
	else
	{
		str=new char[std::strlen(s)+1];
		//makes str's length one more than s length
		std::strcpy(str,s);
		//copying s in str;
	}


}

Mystring::Mystring(const Mystring &source)
:str(nullptr)
{
	str=new char[std::strlen(source.str)+1];
	std::strcpy(str,source.str);
}

Mystring::~Mystring()
{
	delete str;
}

//Display method

void Mystring::display()const
{
	std::cout<<str<<" : "<<get_length()<<std::endl;
}

//length getter
int Mystring::get_length()const
{
	return std::strlen(str);
}
//string getter

const char* Mystring::get_str()const
{
	return str;
}














 