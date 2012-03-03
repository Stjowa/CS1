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
		string str1, str2;

		// Test & Verify
		assert(str1 >= str2);
		assert(str1 == str2);
	}

	{
		// Setup
		string str1 = "a",str2 = "a";

		// Test & Verify
		assert(str1 == str2);
		assert(str1 >= str2);
		assert(str1 <= str2);
	}

	{
		// Setup
		string str1 = "a",str2 = "zz";

		// Test & Verify
		assert(str1 < str2);
		assert(str1 <= str2);
		assert(str1 != str2);
	}

	{
		// Setup
		string str1 = "az",str2 = "z";

		// Test & Verify
		assert(str1 > str2);
		assert(str1 >= str2);
		assert(str1 != str2);
	}
}
