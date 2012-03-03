//  String class test program
//
//  Tests: XXX
//

#include "string.h"
#include <cassert>

//===========================================================================
int main ()
{
	{
		// Setup
		string str1;

		// Test & Verify
		std::cout << str1 << std::endl;
	}

	{
		// Setup
		string str1 = 'a';

		// Test & Verify
		std::cout << str1 << std::endl;
	}

	{
		// Setup
		string str1 = "a";

		// Test & Verify
		std::cout << str1 << std::endl;
	}

	{
		// Setup
		string str1 = "Hello World!";

		// Test & Verify
		std::cout << str1 << std::endl;
	}
}
