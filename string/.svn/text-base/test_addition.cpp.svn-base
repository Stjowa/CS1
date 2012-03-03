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
		string str1,str2,result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == '\0');
		assert(str2 == '\0');
		assert(result == '\0');
	}

	{
		// Setup
		string str1,str2('a'),result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == '\0');
		assert(str2 == "a");
		assert(result == "a");
	}

	{
		// Setup
		string str1 = 'a',str2 = 'b',result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "a");
		assert(str2 == "b");
		assert(result == "ab");
	}

	{
		// Setup
		string str1("a"),str2("b"),result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "a");
		assert(str2 == "b");
		assert(result == "ab");
	}

	{
		// Setup
		string str1('a'),str2("b"),result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "a");
		assert(str2 == "b");
		assert(result == "ab");
	}

	{
		// Setup
		string str1("a"),str2('b'),result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "a");
		assert(str2 == "b");
		assert(result == "ab");
	}

	{
		// Setup
		string str1("Hello "),str2("World!"),result;

		// Test
		result = str1 + str2;

		// Verify
		assert(str1 == "Hello ");
		assert(str2 == "World!");
		assert(result == "Hello World!");
	}

	{
		// Setup
		string str1("Hello"),result;

		// Test
		result = str1 + " World!";

		// Verify
		assert(str1 == "Hello");
		assert(result == "Hello World!");
	}

}
