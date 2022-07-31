#include<iostream>

#include"Mystring.hpp"

using namespace std;

int main()
{
	Mystring empty;          //no args
	Mystring larry("Larry"); // overloaded const
	Mystring stooge(larry);   // copy const

	empty.display();
	larry.display();
	stooge.display();

	return 0;
	
}