//============================================================================
// Name        : Lab10_1.cpp
// Author      : Stephen Walentik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

//final - 50%
//midterm - 25%
//quiz (both) - 25%

struct StudentRecord
{
	double quiz1;
	double quiz2;
	double midterm;
	double finalExam;
};

int main()
{
	double average;
	char option, charGrade;
	StudentRecord grade;
	grade.quiz1=-1;
	for (int i=0; i < 4 ;i++)
	{
		cout << "1) Quiz" << endl
				<< "2) Midterm" << endl
				<< "3) Final Exam" << endl
				<< "Please enter in an option: ";
		cin >> option;
		switch(option)
		{
		case '1':
			//quiz
			if(grade.quiz1<0)
			{
				cout << "Please enter in a test score for the first quiz: ";
				cin >> grade.quiz1;
			}
			else
			{
				cout << "Please enter in a test score for the second quiz: ";
				cin >> grade.quiz2;
			}
			break;
		case '2':
			//midterm
			cout << "Please enter in a midterm score: ";
			cin >> grade.midterm;
			break;
		case '3':
			//final exam
			cout << "Please enter in a Final Exam score: ";
			cin >> grade.finalExam;
			break;
		default:
			cout << "Please enter a valid entry, Program will close";
		}
		cout << endl << endl << endl;
	}
	cout << endl << endl << endl;
	average=grade.quiz1*10*(.25/2.0);
	average+=grade.quiz2*10*(.25/2.0);
	average+=grade.midterm*.25;
	average+=grade.finalExam*.50;
	if(average>90)
		charGrade='A';
	else if(average>80)
		charGrade='B';
	else if (average>70)
		charGrade='C';
	else if (average>60)
		charGrade='D';
	else
		charGrade='F';
	cout << "The students grade is a(n) " << charGrade << " with and average of " << average << " percent.";
	return 0;
}
