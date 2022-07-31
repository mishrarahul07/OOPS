#include<iostream>
using namespace std;

class account
{
	private:	
		double balance;

	public:
		
		void set_balance(double bal)
		{
			balance=bal;
		}	
		double get_balance()
		{
			return balance;
		}


};
void account::set_balance(double bal)
{
	balance=bal;
}
double account::get_balance()
{
	return balance;
}

int main()
{
	
}