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
	void print();
	bool operator==(bigint);

private:
	int num, charLength;
	char revNumList[200], numList[200];
};

bigint::bigint(){
	//maxint = 2147483648
	for(int i=0; i<200; ++i){
	   numList[i]='0';
	}
	numList[1]=0;
	charLength=2;
}
bigint::bigint(int num){
	int i=0;
	for(int i=0; i<200; ++i){
	   numList[i]='0';
	}
	while(num!=0){
	   numList[i]=(num%10) + '0';
	   num=num/10;
	   ++i;
	}
	numList[i]=0;
	charLength=i-1;
}
bigint::bigint(char tempList[]){
	for(int i=0; i<200; ++i){
		numList[i]='0';
	}
	int i=0;
	charLength=-1;
	while(tempList[i]!=0){
		++charLength;
		++i;
	}
	i=0;
	while(tempList[i]!=0){
		numList[charLength-i]=tempList[i];
		++i;
	}
	numList[charLength+1]=0;
}
void bigint::print(){
//charLength
	for(int i=0; i<=79 && numList[i]!=0;++i){
 	   std::cout << numList[charLength-i];
	}
	std::cout << std::endl;
}
bool bigint::operator==(bigint rhs){
	bool result = true;
	for(int i=0; i<MAX_SIZE;++i){
	   //check all the characters in each function
		if(numList[i]!=rhs.numList[i])
			result = false;
	}

	return result;
}
#endif /* SW_CS33001_BIGINT_H */
