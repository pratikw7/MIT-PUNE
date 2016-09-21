/*
 * tape.cpp
 *
 *  Created on: 20-Aug-2016
 *      Author: student
 */

#include "tape.h"
#include <iostream>
using namespace std;

Tape::Tape() {
	playingTime =0;
	price = 0;
	title = "";
}

void Tape::getData()
{
	cout<<"Enter the play time (mm.ss):\n";
	try{
		cin>>playingTime;
		if((playingTime-(int)playingTime) >0.6)
		{
			cout<<"Error occured\n";
			throw(1);
		}
	}
	catch(int i) {
			playingTime =0;
			price = 0;
			title = "";
			cout<<"Error handled\n";
			return;

	}
	cout<<"Enter title of tape:\n";
	cin.ignore();
	cin>>title;
	cout<<"Enter the price of tape:\n";
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
		playingTime =0;
		price = 0;
		title = "";
		cout<<"Error handled\n";
		return;
	}
}

void Tape::showData()
{
	cout<<"\t"<<title<<"\t\t"<<price<<"\t\t"<<playingTime<<"\tType: Tape\n";
}

Tape::~Tape() {
	// TODO Auto-generated destructor stub
}

