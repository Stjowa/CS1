//============================================================================
// Name        : Lab9_1.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string tempString;
	bool test=true;
	char array[81] , temp;
	vector<char> list;

	cout << "Please enter your sentence: ";
	getline(cin, tempString);
	for (int count=0;count < tempString.size();count++)
	{
		temp = tempString.at(count);
		for(int i = 0; i < list.size(); i++)
			if(temp==list.at(i))
				test = false;
		if(test)
			list.push_back(temp);
		test=true;
	}
	for(int i=0;i<list.size();i++)
		cout << list.at(i);
	return 0;
}
