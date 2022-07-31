#include<iostream>
#include<string>
using namespace std;

double calc_kmpl(int km,int ltr)
{
	if(ltr==0)
	{
		throw 0;
	}
	if(km<0||ltr<0)
	{
		throw string("Negative value error");
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
		cout<<"Result is "<<kmpl<<endl;	
	}
	catch(int &ex)
	{
		cerr<<"Sorry can't divide by zero "<<endl;

	}
	
	catch(string &ex)
	{
		cerr<<ex<<endl;
	}
	cout<<"Bye"<<endl;

	catch(...)
	{
		// it is catch all handler
		cerr<<"Unknown error "<<endl;
	}





}

