#include<iostream>
#include"Savings_Account.h"
#include"Account.h"
using namespace std;

int main()
{
	cout<<"===Account Class==="<<endl;
	Account a1(1000.00);
	cout<<a1<<endl;

	a1.deposit(500.00);
	cout<<a1<<endl;

	a1.withdraw(1000);
	cout<<a1<<endl;

	// cout<<"===Savings Account Class==="<<endl;
	// Savings_Account s1(1000,5.0);
	// cout<<s1<<endl;

	// s1.deposit(1000);
	// cout<<s1<<endl;

	// s1.withdraw(1000);
	// cout<<s1<<endl;

}