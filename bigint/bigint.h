/*
 * bigint.h
 *
 *  Created on: Jan 23, 2012
 *      Author: swalenti
 */
#include <string.h>
#include <iostream>

#ifndef SW_CS33001_BIGINT_H
#define SW_CS33001_BIGINT_H

const int MAX_SIZE = 200;

class bigint {
public:
	bigint();
	//Default constructor: Makes bigint equal to 0
	bigint(int);
	//Int constructor: Takes in an int and assigns it to bigint
	bigint(char[]);
	//String, or char array constructor: Takes in a char or string and makes it a bigint
	void output(std::ostream&);
	//This outputs the bigint, but only up to 80 digits of it
	bool operator==(bigint);
	//Overloaded to deal with a bigint to bigint compare
	bool operator==(int);
	//Overloaded to deal with a bigint to int comare
	int operator+(bigint);
	//Overloaded to add a bigint and bigint together
	int operator+(int);
	//Overleaded to add a bigint to a int together

private:
	int num, charLength;
	char numList[MAX_SIZE];
};
#endif /* SW_CS33001_BIGINT_H */
