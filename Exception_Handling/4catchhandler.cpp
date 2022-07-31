/*
if an exception is thrown but not caught in the
current scope then c++ tries to find a handler 
for the exception by unwinding the stack

function in which the exception was not caught
terminates and is removed from the call stack

if a try block was used to then catch blocks are
checked for a match

if no try block was used then or the catch handler
doesn't match then stack unwinding occurs again

if the stack is unwound back to main and no catch
handler handles the exception then the program
terminates



*/
#include<iostream>
using namespace std;
void func_b(),func_c();
void func_a()
{
	cout<<"Stating func_a"<<endl;
	func_b();
	cout<<"Ending func_a"<<endl;

}

void func_b()
{
	cout<<"Stating func_b"<<endl;
	try
	{
		func_c();
			
	}
	catch(int &ex)
	{
		cout<<"Error caught in func_b"<<endl;
	}
	cout<<"Ending func_b"<<endl;	
}
void func_c()
{
	cout<<"Stating func_c"<<endl;
	throw 100;
	cout<<"Ending func_c"<<endl;

	
}


int main()
{
	cout<<"Starting main"<<endl;
	try
	{
		func_a();	
	}
	catch(int &ex)
	{
		cout<<"Error caught in main"<<endl;
	}
	cout<<"Ending main"<<endl;
}