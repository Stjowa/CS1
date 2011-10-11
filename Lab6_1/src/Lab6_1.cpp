//============================================================================
// Name        : Lab6_1.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outStream;
	ifstream inStream;
	char next;
	int space=0;
	inStream.open("proj-8.dat");
	outStream.open("Out.dat");
	inStream.get(next);
	while(!inStream.eof())
	{
		if (next==' ')
		{
			if(space==0)
				outStream << ' ';
			space++;
		}
		else
		{
			outStream << next;
			space=0;
		}
		inStream.get(next);
	}
	inStream.close();
	outStream.close();
	return 0;
}
