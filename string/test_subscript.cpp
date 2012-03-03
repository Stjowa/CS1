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
		string str;

		// Verify
		assert(str[0] == '\0');
	}

	{
		// Setup
		string str('a');

		// Verify
		assert(str[0] == 'a');
	}

	{
		// Setup
		string str("a");

		// Verify
		assert(str[0] == 'a');
	}

	{
		// Setup
		string str("Hello World!");

		// Verify
        assert(str[0] == 'H');
		assert(str[4] == 'o');
		assert(str[6] == 'W');
		assert(str[12]== '\0');
	}
}
