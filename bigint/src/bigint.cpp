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
	bigint bignum("123434345456");
	bigint bignum2(12789);
	bigint bignum4;

	//code tester
	bignum4.print();
	bignum.print();
	bignum2.print();
	if(bignum==bignum2)
		std::cout << "Yeah !! ";

	return 0;
}
