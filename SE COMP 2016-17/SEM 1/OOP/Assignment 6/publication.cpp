/*
 * publication.cpp
 *
 *  Created on: 20-Aug-2016
 *      Author: student
 */

#include "publication.h"

Publication::Publication() {
	// TODO Auto-generated constructor stub

}

Publication::~Publication() {
	// TODO Auto-generated destructor stub
}

int Publication::getData()
{

	cout<<"Enter title:\n";
	cin.ignore();
	cin>>title;
	cout<<"Enter the price:\n";

	try{
	cin>>price;
	if(price==0)
		{
					cout<<"Error occurred\n";
					throw(1);
		}
		}
		catch (int i)
		{
				price = 0;
				title = "";
			cout<<"Error handled\n";
			return 1;
		}
		return 0;
}
void Publication::showData()
{
	cout<<"\t"<<title<<"\t\t"<<price<<"\t\t";
}
