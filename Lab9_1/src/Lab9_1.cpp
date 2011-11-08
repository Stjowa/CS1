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
	//"lab attendance is required."
	string tempString;
	int count=0;
	bool test=true;
	char array[81] , temp;
	vector<char> list;

	cout << "Please enter your sentence: ";
	getline(cin, tempString);
	while (count < tempString.size())
	{
		temp = tempString.at(count);
		for(int i = 0; i < list.size(); i++)
			if(temp==list.at(i))
				test = false;
		if(test)
			list.push_back(temp);
		test=true;
		count++;
	}
	for(int i=0;i<list.size();i++)
		cout << list.at(i);
	return 0;
}
