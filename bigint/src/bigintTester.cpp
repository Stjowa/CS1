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
	//using
	using std::cout;
	using std::cin;
	using std::endl;
	//variables
	bigint bignum("123456789");
	bigint bignum2("12345");

	//code tester
	bignum + bignum2;

	return 0;
}
