/*
 * Source.cpp
 *	Assignment 1
 *  Created on: 17-Jun-2016
 *      Author: Ashwin
 */
#include<iostream>
#include"student.h"

using namespace std;

void displayMenu(Student s[], int present, int n)
{
	char inp;
	cout<<"Enter choice \n";
	cout<<"1. Display List of students\n";
	cout<<"2. Show Average Marks\n";
	cout<<"3. Show highest marks\n";
	cout<<"4. Show lowest marks\n";
	cout<<"5. Show marks scored by most\n";
	cout<<"6. List absentees\n";
	cin>>inp;
	switch (inp)
	{
		case '1':
			s[0].ShowDetails(s,n,present);
			break;
		case '2':
			if (present>0)
				cout << "Average marks of students who gave the test: "<<s[0].CalculateAvg(s,n,present)<<endl;
			else
				cout<<"All were absent\n";
			break;
		case '3':
			if (present>0)
				cout <<"Highest score is: "<< s[0].CalcHigh(s,n)<<endl;
			else
				cout<<"All were absent\n";
			break;
		case '4':
			if (present>0)
				cout <<"\tLowest score is: "<< s[0].CalcLow(s,n)<<endl;
			else
				cout<<"All were absent\n";
			break;
		case '5':
			if (present>0)
				cout<<"Maximum marks scored by most: "<<s[0].ModeofMarks(s,n);
			else
				cout<<"All were absent\n";
			break;
		case '6':
			if (present>0)
				s[0].ListAbsentees(s,n);
			else
				cout<<"All were absent\n";
			break;
		default:
			cout<<"Please enter a valid input\n";
			break;

	}
}

int main()
{
	int n,present;
	cout <<"Enter number of Students:\n";
	cin >> n;
	Student s[n];
	s[0].GetDetails(s,n);
	present = s[0].CalcPresent(s,n);
	char inp = 'y';
	while(inp=='y')
	{
		displayMenu(s, present, n);
		cout<<"DO YOU WISH TO CONTINUE? (y)";
		cin>>inp;
	}
	return 0;
}

