/*
 * student.h
 *
 *  Created on: 28-Jun-2016
 *      Author: student
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class cStudent {

private:
	int iRollNo;
	std::string sName;

public:


	cStudent();
	int iGetRoll(){return iRollNo;}
	std::string sGetName(){return sName;}
	void vSetName(std::string s){sName =s;}
	void vSetRoll(int roll){iRollNo = roll;}

	virtual ~cStudent();
};

#endif /* STUDENT_H_ */
