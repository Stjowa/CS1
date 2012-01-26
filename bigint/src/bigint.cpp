//============================================================================
// Name        : bigint.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "bigint.h"

int main() {
	//variables
	bigint bignum("12347755467898765434567898765434567890987658765689097656");
	bigint bignum2(127893443);
	bigint bignum4;

	//code tester
	bignum4.print();
	bignum.print();
	bignum2.print();
	if(bignum==bignum2)
		std::cout << "Yeah !! ";

	return 0;
}
