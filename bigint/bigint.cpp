#include "bigint.h"
#include <iostream>

bigint::bigint(){
	for(int i=0; i<200; ++i){
	   numList[i]='0';
	}
	charLength=0;
}
bigint::bigint(int num){
	int i=0,temp=num;
	for(int i=0; i<200; ++i){
	   numList[i]='0';
	}
	while(num!=0){
	   numList[i]=(num%10) + '0';
	   num=num/10;
	   ++i;
	}
	if(temp!=0){
	   charLength=i-1;
	}
	else
	   charLength=0;
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
}
void bigint::output(std::ostream& out){
	for(int i=0; i<=79 && i<charLength+1;++i){
 	   out << numList[charLength-i];
	}
	out << std::endl;
}
bool bigint::operator==(bigint rhs){
	bool result = true;
	for(int i=0; i<MAX_SIZE;++i){
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
int bigint::operator+(bigint rhs){

}
int bigint::operator+(int rhsNum){
	bigint rhs(rhsNum);
}
