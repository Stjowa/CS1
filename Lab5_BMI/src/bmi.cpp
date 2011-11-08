//============================================================================
// Name        : Lab5_BMI.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

double bmi (int height, int weight);
void input(int& input1, int& input2);
void bmiChecker(double bmi);

int main()
{
	int input1, input2;
	input(input1, input2);
	cout << "The Body Mass Index is: " << bmi(input2,input1);
	bmiChecker(bmi(input2,input1));
	return 0;
}

double bmi (int height, int weight)
{
	return (weight*703)/(double)(height * height);
}
void input (int& input1, int& input2)
{
	int input3;
	cout << "Please enter the weight: ";
	cin >> input1;
	cout << "Please enter the height in the format (4 8): ";
	cin >> input2 >> input3;
	input2 = (input2*12)+input3;
}
void bmiChecker(double bmi)
{
	cout << endl;
	if (bmi<18.5)
	{
		cout << "This Body Mass Index is Underweight.";
		return;
	}
	else if (bmi>=18.5 && bmi<25)
	{
		cout << "This Body Mass Index is Normal.";
		return;
	}
	else if(bmi>=25 && bmi<30)
	{
		cout << "This Body Mass Index is Overweight.";
		return;
	}
	else if (bmi>=30)
	{
		cout << "This Body Mass Index is Obese.";
		return;
	}
}
