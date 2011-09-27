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
	switch(selection)
	{
	case 1:
		cout << absoluteValue();
		break;
	case 2:
		cout << ceiling();
		break;
	case 3:
		cout << power();
		break;
	case 4:
		cout << logfun();
		break;
	}
	return 0;
}

int absoluteValue ()
{
	int absol;
	cout << "Please enter a number: ";
	cin >> absol;
	cout << "The absolute value of the integer entered is: ";
	return abs(absol);
}
int ceiling ()
{
	double input;
	cout << "Please enter a number: ";
	cin >> input;
	cout << "The number rounded up is: ";
	return ceil(input);
}
double power ()
{
	double base, power;
	cout << "Please enter a base: ";
	cin >> base;
	cout << "Please enter a power: ";
	cin >> power;
	cout << "The product of this power is: ";
	return pow(base, power);
}
double logfun()
{
	double input;
	cout << "Please enter a number for Ln: ";
	cin >> input;
	cout << "The natural log is: ";
	return log(input);
}
