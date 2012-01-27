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
	bigint(int);
	bigint(char[]);
	void output(std::ostream&);
	bool operator==(bigint);
	bool operator==(int);

private:
	int num, charLength;
	char revNumList[200], numList[200];
};
#endif /* SW_CS33001_BIGINT_H */
