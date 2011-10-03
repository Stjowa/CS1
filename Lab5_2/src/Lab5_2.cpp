//============================================================================
// Name        : Lab5_2.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void compute_coins(int coin_value, int& num, int& amount_left);

int main()
{
	int num, amountLeft;
	do
	{
		cout << "Please enter the amount of change: ";
		cin >> amountLeft;
		if(amountLeft<0)
			return 0;
		cout << amountLeft << " cents can be given as" << endl;
		compute_coins(25, num, amountLeft);
		cout << num << " quarter(s) ";
		compute_coins(10, num, amountLeft);
		cout << num << " dime(s) and ";
		compute_coins(1, num, amountLeft);
		cout << num << " penny(pennies)" << endl << endl;
		cout << "To quit enter a negative number";
		cout << endl;
	}
	while(amountLeft>=0);
	return 0;
}

void compute_coins(int coin_value, int& num, int& amount_left)
{
	if (amount_left<0)
		return;
	num = amount_left/coin_value;
	amount_left = amount_left%coin_value;
}
