#include<iostream>
using namespace std;

//best way is throw by value and catch by refrence

double calc_kmpl(int km,int ltr)
{
	if(ltr==0)
	{
		throw 0;
	}
	return static_cast<double>(km)/ltr;

}
//if ltr=0 then this func did not execute properly
// so in main in try we call the function so if 
// it fails to work then catch happens

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
		cout<<"Result is "<<kmpl<<endl;	
	}
	catch(int &ex)
	{
		cerr<<"Sorry can't divide by zero "<<endl;

	}
	
	cout<<"Bye"<<endl;






}

