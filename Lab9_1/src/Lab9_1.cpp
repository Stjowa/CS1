#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	typedef char* charPtr;
	charPtr p;
	p = new char[64];
	int pSize;
	string tempString;
	bool test=true;
	char temp;

	cout << "Please enter your sentence: ";
	getline(cin, tempString);
	for (int count=0;count < tempString.size();count++)
	{
		temp = tempString.at(count);
		for(int i = 0; i < pSize; i++)
			if(temp==p[i])
				test = false;
		if(test)
		{
			p[pSize]=temp;
			pSize++;
		}
		test=true;
	}
	for(int i=0;i<pSize;i++)
		cout << p[i];
	delete p;
	return 0;
}
