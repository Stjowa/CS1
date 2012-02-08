#include "bigint.h"
#include "cassert"

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
	for(int i=0; i<=MAX_SIZE && i<charLength+1;++i){
		if(i % 80 == 0 && i != 0)
			out << std::endl;
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
	//This gives the charLength a value to allow output to work
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
	for(int i=0; i<MAX_SIZE && i<rhs.charLength+1;++i){
		if( i % 80 == 0 && i!=0)
			out << std::endl;
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
void bigint::times_10(int num){
	int i=0;
	//Shifts everything in the array over to the right and adding a zero to the end.
	//The inside for loop shifts over once and then the while loop will have the
	//for loop shift over for the power of ten that is put in
	while(i<num){
		for(int j=MAX_SIZE-1; j>0; --j){
			numList[j]=numList[j-1];
		}
		numList[0]='0';
		++i;
	}
}
void bigint::times_single_digit(int num){
	//Checks to make sure 0<=num<10
	assert(num < 10 && num >= 0);
	bigint temp, tempAdd;
	int lhsTemp=0, carry=0;
	//lhsTemp is the int of numList at that index
	//then lhsTemp is multiplied by num and stored back into numList
	//if there is a carry then it is dealt with through carry
	for(int i=MAX_SIZE; i>=0; --i){
		//gives lhsTemp the int value of the numList char
		lhsTemp = numList[i] - int('0');
		lhsTemp*=num;
		numList[i]=(lhsTemp%10) + int('0');
		carry=lhsTemp/10;
		//adds the carry to the number before
		numList[i+1]= int(numList[i+1]) + carry;
	}
}
bigint bigint::operator*(bigint rhs) const{
	//this.times_single_digit() pass in rhs.numList[i] as an int
	//that will give you the multiplication of the whole bigint 
	//at that rhs index and then add it to each of the indexes
	//as the program continues, this should be able to give you
	//the entire multiplication but make sure to keep track of the
	//charLength because that is what allows the bigint to output
	//correctly without having to output extra '0' using times_10
	//to add the amount of zeros between the index.
	bigint result, temp=*this;
	int lhstemp=0,rhstemp=0;
	
	for(int i=0; i<MAX_SIZE; i++){
		temp=*this;
		rhstemp = rhs.numList[i] - int('0');
		temp.times_single_digit(rhstemp);
		temp.times_10(i);
		result = result + temp;
	}
	return result;
}
