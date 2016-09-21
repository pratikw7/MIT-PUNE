/*
 * student.h
 *
 *		SE 202030
 *      Author: Ashwin Vaidya
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
class Student {
	static int iNoOfStudents;
	char* sName;
	char* sAddr;
	char *sClass;
	char *sBloodGrp;
	int iRoll;
	unsigned long int iPhoneNo;
	struct sDOB{int DD; int MM; int YY;}DOB;
	friend class cSearch;
public:
	Student();
	static int iGetCount();
	static void decreaseCount();
	void vAddDetails();
	void vDisplayData();
	~Student();
};
class cSearch
{
public:
	int Search(Student *s,int n);
		
};

#endif /* STUDENT_H_ */
