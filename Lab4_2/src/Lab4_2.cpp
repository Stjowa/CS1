//============================================================================
// Name        : Lab4_2.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <time.h>
#include <cstdlib>
using namespace std;

int main()
{
	int random, user;

	srand(time(NULL));
	random = rand()%100;
	do
	{
		cout << "Please enter a guess: ";
		cin >> user;
		cout << endl;
		if (user<random)
		{
			cout << "Your guess is too low! ";
		}
		else if (user>random)
		{
			cout << "Your guess is too high! ";
		}
	}
	while(random!=user);
	cout << "Your guess matches the random number! Good job!";
	return 0;
}
