/*
 * book.cpp
 *
 *  Created on: 20-Aug-2016
 *      Author: student
 */

#include "book.h"
#include <iostream>
using namespace std;
Book::Book() {
	pageCount =0;
	price = 0;
	title = "";

}

void Book::getData()
{
	cout<<"Enter the number of pages:\n";
	try{
	cin>>pageCount;
		if(pageCount>1000)
		{
			cout<<"Error occurred\n";
			throw(1);
		}
	}
	catch (int i)
	{
		pageCount =0;
		price = 0;
		title = "";
		cout<<"Error handled\n";
		return;
	}
	
	if(Publication::getData())
	{
		pageCount =0;
		return;
	}
}

void Book::showData()
{
	Publication::showData();
	cout<<pageCount<<"\tType: Book\n";
}

Book::~Book() {
	// TODO Auto-generated destructor stub
}

