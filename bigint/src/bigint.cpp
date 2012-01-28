#include "bigint.h"
#include <iostream>

bigint::bigint(){
	//maxint = 2147483648
	for(int i=0; i<200; ++i){
	   numList[i]='0';
	}
	numList[1]=0;
	charLength=2;
}
bigint::bigint(int num){
	int i=0,temp=num;
	for(int i=0; i<200; ++i){
	   numList[i]='0';
	}
	if(num==0){
	   numList[0]='0';
	   numList[1]=0;
	}
	while(num!=0){
	   numList[i]=(num%10) + '0';
	   num=num/10;
	   ++i;
	}
	if(temp!=0){
	   numList[i]=0;
	   charLength=i-1;
	}
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
void bigint::output(std::ostream& out){
//charLength
	for(int i=0; i<=79 && numList[i]!=0;++i){
 	   out << numList[charLength-i];
	}
	out << std::endl;
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
bool bigint::operator==(int rhsNum){
	bigint rhs(rhsNum);
	bool result = true;
	for (int i=0;i<MAX_SIZE;++i){
	   if(numList[i]!=rhs.numList[i])
		result = false;
	}
	return result;
}
