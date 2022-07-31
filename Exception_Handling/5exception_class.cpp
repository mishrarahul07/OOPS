/*

We can create exception classes and throw instances
of those classes

Best Practice:
	throw an object not a primitive type
	throw an object by value
	catch an object by refrence



*/


#include<iostream>
using namespace std;
class DivideByZeroException
{

};

class NegativeValueException
{

};
double calc_kmpl(int km,int ltr)
{
	if(ltr==0)
	{
		throw DivideByZeroException();
	}
	if(km<0||ltr<0)
	{
		throw NegativeValueException();
	}
	return static_cast<double>(km)/ltr;

}
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
		kmpl=calc_kmpl(km,ltr);
		kmpl=static_cast<double>(km)/ltr;
		cout<<"Result is "<<kmpl<<endl;	
	}
	catch(DivideByZeroException &ex)
	{
		cerr<<"Sorry can't divide by zero "<<endl;

	}
	catch(NegativeValueException &ex)
	{
		cerr<<"Negative value error"<<endl;
	}
	
	cout<<"Bye"<<endl;






}
