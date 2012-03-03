#ifndef CS33001_STRING_CLASS_SW_H
#define CS33001_STRING_CLASS_SW_H

#include <iostream>

int const SIZE = 128;

class string{
	public:
		string();
		//deconstructor
		~string();
		string(const int);
		string(const char);
		string(const char[]);
		string operator=(const char[]);
	//boolean compare methods
		bool operator==(const string&)const;
		bool operator!=(const string&)const;
		bool operator<(const string&)const;
		bool operator<=(const string&)const;
		bool operator>(const string&)const;
		bool operator>=(const string&)const;
	//concate 
		string operator+(const string&);
		string operator+(const char[]);
	//subtract
		string operator-(const int);
		string operator-(const char);
		string operator-(const string&);
	//array
		char operator[](const int)const;
		char& operator[](const int);
	//length
		int length()const;
	//substring
		string substr(const int);
		string substr(const int, const int);
	//find character
		int findchar(const char)const;
	//find string
		int findstr(const string&)const;
	//I/O
		friend std::ostream& operator<<(std::ostream&, const string&);
		friend std::istream& operator>>(std::istream&, const string&);

	private:
		char stringList[SIZE];
		//char *stringList;
		int capacity;
};

#endif
