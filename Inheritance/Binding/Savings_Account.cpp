#include"Savings_Account.h"
using namespace std;
Savings_Account::Savings_Account(double balance,double int_rate)
	:Account(balance),int_rate(int_rate)
{

}

Savings_Account::Savings_Account()
:Savings_Account(0.0,0.0)
{

}

void Savings_Account::deposit(double amount)
{
	amount=amount+(amount*int_rate/100);
	Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os,Savings_Account &account)
{
	os<<"Savings Account balance"<<account.balance<<" Interest Rate "<<account.int_rate;
	return os;
}