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
*****************************************************************************
Enter number of Students:
4
Enter Student1's name:
Ashwin
Enter roll number of student: 
30
Whether present or absent for test (a/p): p
Enter Student1's marks:
45
Enter Student2's name:
Dan
Enter roll number of student: 
21
Whether present or absent for test (a/p): a
Enter Student3's name:
Test
Enter roll number of student: 
56
Whether present or absent for test (a/p): p
Enter Student3's marks:
67
Enter Student4's name:
Rat
Enter roll number of student: 
13
Whether present or absent for test (a/p): p
Enter Student4's marks:
5
Enter choice 
1. Display List of students
2. Show Average Marks
3. Show highest marks
4. Show lowest marks
5. Show marks scored by most
6. List absentees
1
Name		Roll No.	Marks		Ab/P
Ashwin		30		45		p
Dan		21		0		a
Test		56		67		p
Rat		13		5		p
DO YOU WISH TO CONTINUE? (y)y
Enter choice 
1. Display List of students
2. Show Average Marks
3. Show highest marks
4. Show lowest marks
5. Show marks scored by most
6. List absentees
2
Average marks of students who gave the test: 39
DO YOU WISH TO CONTINUE? (y)y
Enter choice 
1. Display List of students
2. Show Average Marks
3. Show highest marks
4. Show lowest marks
5. Show marks scored by most
6. List absentees
3
Highest score is: 67
DO YOU WISH TO CONTINUE? (y)y
Enter choice 
1. Display List of students
2. Show Average Marks
3. Show highest marks
4. Show lowest marks
5. Show marks scored by most
6. List absentees
4
	Lowest score is: 5
DO YOU WISH TO CONTINUE? (y)y
Enter choice 
1. Display List of students
2. Show Average Marks
3. Show highest marks
4. Show lowest marks
5. Show marks scored by most
6. List absentees

DO YOU WISH TO CONTINUE? (y)y
Enter choice 
1. Display List of students
2. Show Average Marks
3. Show highest marks
4. Show lowest marks
5. Show marks scored by most
6. List absentees
6

List of students who were absent:
-Dan
DO YOU WISH TO CONTINUE? (y)n
Enter number of Students:
0
Enter choice 
1. Display List of students
2. Show Average Marks
3. Show highest marks
4. Show lowest marks
5. Show marks scored by most
6. List absentees
1

All were absent
DO YOU WISH TO CONTINUE? (y)

