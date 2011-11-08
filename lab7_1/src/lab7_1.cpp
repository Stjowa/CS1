//============================================================================
// Name        : lab7_1.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cctype>
#include <vector>
using namespace std;


bool choice();
//int* fileInput(int num[],int& entry);
double averageSum(double sum, double entry);
void standardDeviation (vector<int> list,double average,double entry);


int main()
{
	vector<int> list;
	char tempChar;
	double average=0, entry=0, temp;
	if(!choice())
	{
		for(int i=0;i<10;i++)
		{
			cout << "Enter number: ";
			cin >> temp;
			list.push_back(temp);
			average+=list.at(i);
			entry++;
			cout << "Do you want to continue? (y/n)";
			cin >> tempChar;
			if(tempChar=='n')
			{
				break;
			}
		}
	}
	else
	{
		ifstream inFile;
		string fileName;
		int next;
		cout << "Please type in the file name that you would like to use.";
		cin >> fileName;
		inFile.open(fileName.c_str());
		if(inFile.fail())
		{
			cout<<"ERROR: File was not able to be opened";
		}
		else
		{
			while(inFile >> next)
			{
				list.push_back(next);
				average+=list.at(entry);
				entry++;
			}
			inFile.close();
		}
	}
	standardDeviation(list,average,entry);
	return 0;
}


bool choice()
{
	char temp;
	cout << "Do you want to use a file? (y/n)\nIf no then user will input numbers manually.";
	cin >> temp;
	if(temp=='y')
	{
		return true;
	}
	return false;
}
double averageSum(double sum, double entry)
{
	return sum/entry;
}
void standardDeviation (vector<int> list,double average,double entry)
{
	double sum;
	for(int i=0;i<entry;i++)
	{
		sum+=(list.at(i)-averageSum(average,entry))*(list.at(i)-averageSum(average,entry));
	}
	sum = sqrt((double)sum/(entry-1));
	cout << endl <<"Standard Deviation: "<< sum;
}
