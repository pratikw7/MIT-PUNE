/*
 * publication.h
 *
 *  Created on: 20-Aug-2016
 *      Author: student
 */

#ifndef PUBLICATION_H_
#define PUBLICATION_H_
#include <iostream>
#include <string>
using namespace std;
class Publication {
public:
	Publication();
	int getData();
	void showData();
	virtual ~Publication();
protected:
	string title;
	float price;
};

#endif /* PUBLICATION_H_ */

