/*
 * bigint.h
 *
 *  Created on: Jan 23, 2012
 *      Author: swalenti
 */
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
	bigint(const char[]);
	//String, or char array constructor: Takes in a char or string and makes it a bigint
	void output(std::ostream&);
	//This outputs the bigint, but only up to 80 digits of it
	bool operator==(bigint) const;
	//Overloaded to deal with a bigint to bigint compare
	bigint operator+(bigint) const;
	//Overloaded to add a bigint and bigint together
	int operator[](int) const;
	void times_10(int);
	void times_single_digit(int);
	bigint operator*(bigint) const;


//friends
	friend std::ostream& operator<<(std::ostream&, bigint);
	friend std::istream& operator>>(std::istream&, bigint&);

private:
	int num, charLength;
	char numList[MAX_SIZE];
};
#endif /* SW_CS33001_BIGINT_H */
