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
	bigint sum;
	int carry=0;
	for(int i=0; i<MAX_SIZE; ++i){
		if(int(numList[i]) + int(rhs.numList[i]) - int('0') + carry > int('9')){
			sum.numList[i]=(int(numList[i]) + int(rhs.numList[i]) - int('0') + carry -10);
			carry=1;
		}
		else{
			sum.numList[i] = int(numList[i]) + int(rhs.numList[i]) - int('0') + carry;
			carry=0;
		}
	}
	if(charLength > rhs.charLength){
		sum.charLength = charLength;
		if(sum.numList[charLength+1] != '0'){
			++sum.charLength;
		}
	}
	else{
		sum.charLength = rhs.charLength;
		if(sum.numList[rhs.charLength+1] != '0'){
			++sum.charLength;
		}
	}
return sum;
}
int bigint::operator[](int rhs) const{
	return int(numList[rhs])-int('0');
}
std::ostream& operator<<(std::ostream& out, bigint rhs){
	for(int i=0; i<=79 && i<rhs.charLength+1;++i){
		out << rhs.numList[rhs.charLength-i];
	}
	return out;
}
std::istream& operator>>(std::istream& in, bigint& rhs){
	rhs = bigint();
	char ch, tempList[MAX_SIZE];
	in >> ch;
	int i=0;
	while (i<MAX_SIZE && ch != ';'){
		tempList[i]=ch;
		in >> ch;
		++i;
		++rhs.charLength;
	}
	for(int i=0; i<rhs.charLength;++i){
		rhs.numList[rhs.charLength-i-1]=tempList[i];
	}
	--rhs.charLength;
	return in;
}
