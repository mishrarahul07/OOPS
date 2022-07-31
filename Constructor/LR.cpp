#include<iostream>

using namespace std;
int main()
{
	int total=0;
	total=100+200;
	cout<<total<<endl;

	int x=100;
	int &l_ref=x;
	l_ref=10;

	int &&r_ref=200;
	r_ref=300;

	//int &&x_ref=x; //error

/*
	int a=100;
	void func(int &num);
	{
		int y=x;
	} // it demands a L value arguement

	func(x);
	
	// func(200); error 200 is R value
*/
	
/*
	void func(int &&num);

	func(200);
	//func(x);  //error

*/



}