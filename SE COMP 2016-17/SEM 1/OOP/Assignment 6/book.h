/*
 * book.h
 *
 *  Created on: 20-Aug-2016
 *      Author: student
 */

#ifndef BOOK_H_
#define BOOK_H_
#include "publication.h"
class Book : public Publication
{
public:
	Book();
	void getData();
	void showData();
	virtual ~Book();
private:
	int pageCount;
};

#endif /* BOOK_H_ */
