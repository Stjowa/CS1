#include "string.h"
#include <iostream>
#include <cassert>


//default
string::string(){
	//stringList = new char[SIZE];
	stringList[0]='\0';
}
//deconstructor
string::~string(){
	//delete stringList;
}
//set capacity constructor
string::string(const int paraNum){
	//stringList = new char[paraNum];
	stringList[0] = '\0';
	capacity=paraNum;
}
//char constructor
string::string(const char paraChar){
	//stringList = new char[2];
	stringList[0]=paraChar;
	stringList[1]='\0';
}
//char array, "string" constuctor
string::string(const char paraString[]){
	//stringList = new char[SIZE];
	int i =0;
	for(i=0;paraString[i]!='\0';++i){
		stringList[i]=paraString[i];
	}
	stringList[i]='\0';
}



string string::operator=(const char paraString[]){
	int i;
	for(i=0; paraString[i] != '\0'; ++i){
		stringList[i]=paraString[i];
	}
	stringList[i]='\0';
	//return a handle
	return *this;
}
bool string::operator==(const string& rhs)const{
	int i=0;
	for(i=0; stringList[i] != '\0'; ++i)
		if(stringList[i] != rhs.stringList[i])
			return false;
	if(rhs.stringList[i]=='\0')
		return true;
	return false;
}
bool string::operator!=(const string& rhs)const{
	return !(*this == rhs);
}
bool string::operator<(const string& rhs)const{
	return length() < rhs.length();
}
bool string::operator<=(const string& rhs)const{
	return length() <= rhs.length();
}
bool string::operator>(const string& rhs)const{
	return length() > rhs.length();
}
bool string::operator>=(const string& rhs)const{
	return length() >= rhs.length();
}
string string::operator+(const string& rhs){
	string result=*this;
	for(int i=length(), j=0; i <= length()+rhs.length(); ++i, ++j)
		result.stringList[i]=rhs.stringList[j];
	return result;

//	string result=*this;
//	int i=length();
//	for(i=0; i<length(); ++i)
//		result.stringList[i]=stringList[i];
//	for(int j=0; i<length()+rhs.length();++j,++i)
//		result.stringList[i]=rhs.stringList[j];
//	result.stringList[length()+rhs.length()+1]='\0';
//	return result;
}
string string::operator+(const char temprhs[]){
	string rhs=temprhs;
	return *this+rhs;
}
string string::operator-(const int paraNum){
	if(paraNum <= 0)
		return *this;
	if(paraNum >= length())
		return "";
	string result;
	for(int i=0; i<(length()-paraNum); ++i)
		result = result + stringList[i];
	return result;
}
string string::operator-(const char paraChar){
	string result;
	for(int i=0; i<length(); ++i)
		if(stringList[i]!=paraChar)
			result=result+stringList[i];
	return result;
}
string string::operator-(const string& paraString){
	string result;
	for(int i=0, j=0; i<length(); ++i, j=0){
		while(stringList[i+j]==paraString.stringList[j] && j <= paraString.length()){
			++j;
			if(j==paraString.length())
				i=i+j;
		}
		result = result+stringList[i];
	}
	return result;
}
char string::operator[](const int index)const{
	return stringList[index];
}
char& string::operator[](const int index){
	return stringList[index];
}
int string::length()const{
	int stringLength;
	for(stringLength=0; stringList[stringLength]!='\0';++stringLength);
	return stringLength;
}
string string::substr(const int paraStart){
	string result;
	for(int i=paraStart; i < length(); ++i)
		result = result + stringList[i];
	return result;

	//return substr(paraStart, length());
}
string string::substr(const int paraStart, const int paraEnd){
	string result;
	for(int i=paraStart; i<paraEnd; ++i)
		result=result+stringList[i];
	return result;
}
int string::findstr(const string& paraString) const{
	int numOfStrings=0;
	for(int i=0, j=0; i<length(); ++i, j=0)
		while(stringList[i+j]==paraString.stringList[j] && j <= paraString.length()){
			++j;
			if(j==paraString.length()){
				++numOfStrings;
				i=i+j;
			}
		}
	return numOfStrings;
}
int string::findchar(const char paraChar) const{
	int numOfChars=0;
	for(int i=0; stringList[i] != '\0'; ++i)
		if(stringList[i]==paraChar)
			++numOfChars;
	return numOfChars;
}
std::ostream& operator<<(std::ostream& out, const string& rhs){
	out << rhs.stringList;
	return out;
}
std::istream& operator>>(std::istream& in, const string& rhs){
	in >> rhs.stringList;
	return in;
}
