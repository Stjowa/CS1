//============================================================================
// Name        : Lab11_1.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class RationalNumber
{
public:
	int num1, num2, denom1, denom2;
	int newNum1, newNum2, newNum3, newDenom1, newDenom2;

	void input();
	void addition();
	void subtraction();
	void product();
	void division();
	void compareTo();
};

void RationalNumber::input()
{
	cout<<"Please input the first fraction"<<endl;
	cin >> num1 >> denom1;
	cout<<"Please input the second fraction"<<endl;
	cin >> num2 >> denom2;
}
void RationalNumber::addition()
{
	cout << "Addition:" <<endl;
	newNum1=num1*denom2;
	newDenom1=denom1*denom2;
	newNum2=num2*denom1;
	newDenom2=denom2*denom1;
	newNum3=newNum1+newNum2;
	cout << "     " << newNum3 << "/" << newDenom1 <<endl;
	double num3=newNum3;
	cout << "     " << num3/newDenom1<<endl;
}
void RationalNumber::subtraction()
{
	cout << "Subtraction:" <<endl;
	newNum3=newNum1-newNum2;
	cout << "     " << newNum3 << "/" << newDenom1 <<endl;
	double num3=newNum3;
	cout << "     " << num3/newDenom1<<endl;
}
void RationalNumber::product()
{
	cout << "Multiplication:" <<endl;
	cout << "     " << num1*num2 << "/" << denom1*denom2 <<endl;
	double newerNum=num1*num2, newerDenom=denom1*denom2;
	cout << "     " << newerNum/newerDenom<<endl;
}
void RationalNumber::division()
{
	cout << "Division:" <<endl;
	cout << "     " << num1*denom2 << "/" << denom1*num2 <<endl;
	double newerNum=num1*denom2, newerDenom=denom1*num2;
	cout << "     " << newerNum/newerDenom<<endl;
}
void RationalNumber::compareTo()
{
	cout << "Compare:" <<endl;
	double newerNum1=num1,newerNum2=num2,frac1,frac2;
	frac1= newerNum1/denom1;
	frac2= newerNum2/denom2;
	if(frac1>frac2)
	{
		cout << "     " << num1 << "/" << denom1 <<endl;
		cout << "     " << newerNum1/denom1 <<endl;
	}
	else if(frac1<frac2)
	{
		cout << "     " << num2 << "/" << denom2 <<endl;
		cout << "     " << newerNum2/denom2 <<endl;
	}
	else
	{
		cout << "     " << "The fractions are equal.";
	}
}

int main()
{
	RationalNumber ratNum;
	ratNum.input();
	ratNum.addition();
	ratNum.subtraction();
	ratNum.product();
	ratNum.division();
	ratNum.compareTo();
	return 0;
}
