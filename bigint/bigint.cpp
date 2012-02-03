#include "bigint.h"

bigint::bigint(){
	for(int i=0; i<MAX_SIZE; ++i){
	   numList[i]='0';
	}
	charLength=0;
}
bigint::bigint(int num){
	int i=0,temp=num;
	for(int i=0; i<MAX_SIZE; ++i){
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
bigint::bigint(const char tempList[]){
	for(int i=0; i<MAX_SIZE; ++i){
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
}
bool bigint::operator==(bigint rhs) const{
	bool result = true;
	for(int i=0; i<MAX_SIZE;++i){
		if(numList[i]!=rhs.numList[i])
			result = false;
	}

	return result;
}
bigint bigint::operator+(bigint rhs) const
{
	bigint list;
	int carry=0;
	int carryPlace=0;
	for (int i=0; i<MAX_SIZE; ++i){
	   if(int(numList[i])+int(rhs.numList[i])+carry>int('9')){
	      carry=1;
	      carryPlace=i+1;
	   }
	   else carry=0;
//	   if(carry==1 && i==carryPlace){
//	      list.numList[i]=int(rhs.numList[i])+int(numList[i])-10;
// 	   }		
//	   else{
	      list.numList[i]=int(rhs.numList[i])+int(numList[i])-int('0');
//	   }
	}
	return list;
}
int bigint::operator[](int rhs) const{
	return int(numList[rhs])-int('0');
}
std::ostream& operator<<(std::ostream& out, bigint rhs){
	for(int i=0; i<=79 && i<rhs.charLength+1;++i){
	   out << rhs.numList[rhs.charLength-i];
	}
	return out;
std::istream& operator>>(std::istream& in, bigint& rhs){
	char ch;
	in >> ch;
	int i=0;
	while (i<MAX_SIZE && ch != ';'){
	   in >> ch;
	   rhs.numList[i]=ch;
	   ++i;
	}
	return in;
}
