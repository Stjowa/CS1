//============================================================================
// Name        : Lab4_1.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int absoluteValue();
int ceiling ();
double power();
double logfun();


int main()
{
	int selection;
	cout << "1. Absolute Value \n2. Ceiling \n3. Power \n4.Logarithm \nSelect an operation: ";
	cin >> selection;
	if(selection==1)
	{
		cout << "The absolute value of the integer entered is: " << absoluteValue();
	}
	else if (selection==2)
	{
		cout << "The number rounded up is: " << ceiling();
	}
	else if (selection==3)
	{
		cout << "The product of this power is: " << power();
	}
	else if (selection==4)
	{
		cout << "The natural log is: " << logfun();
	}
	return 0;
}

int absoluteValue ()
{
	int absol;
	cout << "Please enter a number: ";
	cin >> absol;
	return abs(absol);
}
int ceiling ()
{
	double input;
	cout << "Please enter a number: ";
	cin >> input;
	return ceil(input);
}
double power ()
{
	double base, power;
	cout << "Please enter a base: ";
	cin >> base;
	cout << "Please enter a power: ";
	cin >> power;
	return pow(base, power);
}
double logfun()
{
	double input;
	cout << "Please enter a number for Ln: ";
	cin >> input;
	return log(input);
}
