#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include"Account.h"
using namespace std;
//Savings account class 
//deposit method increments amount to be deposited by the
//amount *int_rate percentage

//So a 1000 deposit at 5%interest rate 


class Savings_Account:public Account
{
	friend std::ostream &operator<<(std::ostream &os,const Savings_Account &account);

protected:
	double int_rate;
public:
	Savings_Account();
	Savings_Account(double amount);
	void deposit(double amount);
	//Withdraw is inherited
};

#endif //_SAVINGS_ACCOUNT