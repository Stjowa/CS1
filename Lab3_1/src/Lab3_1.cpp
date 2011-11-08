//============================================================================
// Name        : Lab3_1.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int num1, count1=1, count2=1;

int main()
{
	cout << "Please enter the size of the figures you would like: ";
	cin >> num1;
	while(num1 >= count1)
	{
		while(num1 >= count2)
		{
			cout << "*";
			count2++;
		}
		count2=1;
		cout << endl;
		count1++;
	}
	cout << endl;
	count1=1;
	//Triangle one
	while (num1 >= count1)
	{
		while (count2 <= count1)
		{
			cout << "*";
			count2++;
		}
		count2=1;
		cout << endl;
		count1++;
	}
	count1=num1;
	cout << endl;
	//Triangle two
	while(count1>=1)
	{
		while(num1 >= count2)
		{
			if(count2<count1)
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
			count2++;
		}
		count2=1;
		cout << endl;
		count1--;
	}
	return 0;
}