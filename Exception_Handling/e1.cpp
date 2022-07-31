/*
Exception Handling 
	-dealing with extraordinary situations
	-indicates that an extraordinary situations
	  is detected or occured

What causes errors?
	-insufficient resources
	-missing resources
	-invalid operations
	-range violations
	-underflows and overflows
	-illegal data and many others

throw 
	-throws an exception
	-followed by an arguement

try
	-you place code that may throw up an exception
	-if the code throws an exception the try block
	 is exited
	-the thrown exception is handled by the catch
	 handler
	-if no catch handler exists the program terminates
	 
catch(Exception ex) //code to handle exception
	-code that handles exception
	-can have multiple catch handlers
	-may or may not cause the program to terminate


*/
#include<iostream>
using namespace std;
//if no catch but a throw then program terminates

int main()
{
	int km;
	int ltr;

	double kmpl;

	cout<<"Enter kilometer";
	cin>>km;
	cout<<"Enter ltr";
	cin>>ltr;

	try
	{
		if(ltr==0)
		{
			throw 0;
		}
		kmpl=static_cast<double>(km)/ltr;
		cout<<"Result is "<<kmpl<<endl;	
	}
	catch(int &ex)
	{
		cerr<<"Sorry can't divide by zero "<<endl;

	}
	
	cout<<"Bye"<<endl;






}
























