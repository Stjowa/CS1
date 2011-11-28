//============================================================================
// Name        : Lab10_2.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Grade
{
public:
	double quiz1;
	double quiz2;
	double midterm;
	double finalExam;
	double average;
	char charGrade;

	char letterGrade();
	void output();
	void input();
	double averageCalc();
};

char Grade::letterGrade()
{
	if(average>=90)
		charGrade='A';
	else if(average>=80)
		charGrade='B';
	else if (average>=70)
		charGrade='C';
	else if (average>=60)
		charGrade='D';
	else
		charGrade='F';
	return charGrade;
}
void Grade::output()
{
	cout << endl << endl << endl << "The students grade is a(n) " << charGrade << " with and average of " << average << " percent.";
}
void Grade::input()
{
	cout << "1) Quiz" << endl
			<< "2) Midterm" << endl
			<< "3) Final Exam" << endl
			<< "Please enter in an option: ";
	char option;
	cin >> option;
	switch(option)
	{
	case '1':
		//quiz
		if(quiz1<0)
		{
			cout << "Please enter in a test score for the first quiz: ";
			cin >> quiz1;
		}
		else
		{
			cout << "Please enter in a test score for the second quiz: ";
			cin >> quiz2;
		}
		break;
	case '2':
		//midterm
		cout << "Please enter in a midterm score: ";
		cin >> midterm;
		break;
	case '3':
		//final exam
		cout << "Please enter in a Final Exam score: ";
		cin >> finalExam;
		break;
	default:
		cout << "Please enter a valid entry, Program will close";
	}
}
double Grade::averageCalc()
{
	average=quiz1*10*(.25/2.0);
	average+=quiz2*10*(.25/2.0);
	average+=midterm*.25;
	average+=finalExam*.50;
	return average;
}

int main()
{
	Grade grader;
	grader.quiz1=-1;
	for(int i = 0; i<4 ; i++)
		grader.input();
	grader.averageCalc();
	grader.letterGrade();
	grader.output();
	return 0;
}
