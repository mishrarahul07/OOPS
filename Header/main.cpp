#include<iostream>
#include "account.h"

using namespace std;

int main()
{
	account frank_account;
	frank_account.set_balance(1000.00);
	double bal=frank_account.get_balance();
	cout<<bal<<endl;

}