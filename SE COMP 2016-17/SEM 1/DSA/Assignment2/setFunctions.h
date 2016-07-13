/*
 * setFunctions.h
 *
 *  Created on: 01-Jul-2016
 *      Author: student
 */

#ifndef SETFUNCTIONS_H_
#define SETFUNCTIONS_H_

#include "student.h"

class cSet {
private:
	cStudent s[100];
	int size;
public:
	cSet();
	void vDisplaySetData();
	void vSetUnion(cSet a, cSet b);
	void vSetIntersection(cSet a, cSet b);
	void vGetData();
	void vSetSize(int);
	void vPutDataAtPos(int, std::string , int );
	cSet SetDifference(cSet a, cSet b);
	int iSearchInList(cSet, int);

	virtual ~cSet();
};

#endif /* SETFUNCTIONS_H_ */
