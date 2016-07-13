/*
 * Student.h
 *
 *  Created on: 21-Jun-2016
 *      Author: student
 */

#ifndef STUDENT_H_
#define STUDENT_H_


class Student
{

	int marks, rollNo;
	char name[25], status;
public:
	void ListAbsentees(Student [], int );
	void GetDetails(Student [], int);
	void ShowDetails(Student [], int,int);
	float CalculateAvg(Student[],int ,int);
	int CalcPresent(Student [],int );
	int CalcHigh(Student [],int );
	int CalcLow(Student [],int );
	int ModeofMarks(Student [],int );


};

#endif /* STUDENT_H_ */
