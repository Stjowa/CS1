//============================================================================
// Name        : Lab9_1.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int count=0;
	bool test=true;
	char array[81] = "lab attendance is required.", temp;
	vector<char> list;

	while (count < 81)
	{
		temp = array[count];
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
