//============================================================================
// Name        : Lab8_1.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

void userInput();
void NumberSpell(char num1, char num2, int num3, int& stringCount);
void checkMaker(string date, string name, string payee, char num1, char num2, int num3);

int main()
{
	userInput();
	return 0;
}

void userInput()
{
	string date, name, payee,temp;
	char num1, num2;
	int num3;
	cout << "Date: ";
	getline(cin, date);
	cout << "Name: ";
	getline(cin, name);
	cout << "Amount in Dollars: ";
	cin >> num1 >> num2;
	cout << "Amount in Cents: ";
	cin >> num3;
	cout << "Payee: ";
	cin >> payee;
	payee += " ";
	cin >> temp;
	payee += temp;
	cout << endl;
	checkMaker(date, name, payee, num1, num2, num3);
}
void checkMaker(string date, string name, string payee, char num1, char num2, int num3)
{
	int stringCount=0;
	const int SPACE = 40;
	int count=0;
	cout << "Your Check: " << endl << endl << name;
	while ((count+name.size())<SPACE)
	{
		cout << " ";
		count++;
	}
	cout << date << endl;
	cout << "Pay to: " << payee;
	count=0;
	while ((count+payee.size()+8)<SPACE)
	{
		cout << " ";
		count++;
	}
	if(num3<10)
		cout << "$" << num1 << num2 << ".0" << num3 << endl;
	else
		cout << "$" << num1 << num2 << "." << num3 << endl;
	NumberSpell(num1, num2, num3, stringCount);
	count=0;
	while ((count+stringCount)<SPACE)
	{
		cout << " ";
		count++;
	}
	cout << "Dollars";
}
void NumberSpell(char num1, char num2, int num3, int& stringCount)
{
	switch(num1)
	{
	case '1':
		switch (num2)
		{
		case '0':
			cout << "Ten";
			stringCount=3;
			break;
		case '1':
			cout << "Eleven";
			stringCount=6;
			break;
		case '2':
			cout << "Twelve";
			stringCount=6;
			break;
		case '3':
			cout << "Thirteen";
			stringCount=8;
			break;
		case '4':
			cout << "Fourteen";
			stringCount=8;
			break;
		case '5':
			cout << "Fitfteen";
			stringCount=8;
			break;
		case '6':
			cout << "Sixteen";
			stringCount=7;
			break;
		case '7':
			cout << "Seventeen";
			stringCount=9;
			break;
		case '8':
			cout << "Eighteen";
			stringCount=8;
			break;
		case '9':
			cout << "Nineteen";
			stringCount=8;
			break;
		default:
			cout << "ERROR";
		}
		break;
	case '2':
			cout << "Twenty ";
			stringCount=7;
			break;
	case '3':
			cout << "Thirty ";
			stringCount=7;
			break;
	case '4':
			cout << "Fourty ";
			stringCount=7;
			break;
	case '5':
			cout << "Fifty ";
			stringCount=6;
			break;
	case '6':
			cout << "Sixty ";
			stringCount=6;
			break;
	case '7':
			cout << "Seventy ";
			stringCount=8;
			break;
	case '8':
			cout << "Eighty ";
			stringCount=7;
			break;
	case '9':
			cout << "Ninety ";
			stringCount=7;
			break;
	default:
		cout << "Please enter a number between 10-99 " << endl;
	}
	if (num1!='1')
	{
		switch(num2)
		{
		case '1':
			cout << "one";
			stringCount+=3;
			break;
		case '2':
			cout << "two";
			stringCount+=3;
			break;
		case '3':
			cout << "three";
			stringCount+=5;
			break;
		case '4':
			cout << "four";
			stringCount+=4;
			break;
		case '5':
			cout << "five";
			stringCount+=4;
			break;
		case '6':
			cout << "six";
			stringCount+=3;
			break;
		case '7':
			cout << "seven";
			stringCount+=5;
			break;
		case '8':
			cout << "eight";
			stringCount+=5;
			break;
		case '9':
			cout << "nine";
			stringCount+=4;
			break;
		default:
			break;
		}
	}
	if(num3<10)
		stringCount+=6;
	else
		stringCount+=7;
	cout << " " << num3 << "/100";
}
