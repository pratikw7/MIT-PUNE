/*
 * setFunctions.cpp
 *
 *  Created on: 01-Jul-2016
 *      Author: student
 */

#include "setFunctions.h"
#include <iostream>

using namespace std;

cSet::cSet() {
}

cSet::~cSet() {
}

void cSet::vSetUnion(cSet a, cSet b)
{
	cout<<"Union of Sets is:\n";
	for(int i=0; i<b.size; i++)
		{
			cout<<b.s[i].sGetName()<<"\t\t"<<b.s[i].iGetRoll()<<endl;
		}
	for(int i=0; i<a.size; i++)
	{
		int ret = iSearchInList(b,a.s[i].iGetRoll());
		if(ret == -1)
			cout<<a.s[i].sGetName()<<"\t\t"<<a.s[i].iGetRoll()<<endl;
	}

}
int cSet::iSearchInList(cSet a, int roll)
{
	for(int i=0; i<a.size; i++)
		if(a.s[i].iGetRoll() == roll)
			return i;
	return -1;
}
void cSet::vGetData()
{
	cout<<"Enter size of set: ";
	cin>>size;
	for(int i=0; i<size; i++)
	{
		cout<<"Enter student name: ";
		string name;
		cin>>name;
		cout<<"Enter roll number: ";
		int roll;
		cin>>roll;
        if(iSearchInList(*this, roll) != -1)
		{
			cout<<"Input data already exists in the set\n";
			i--;
			continue;
        }
		s[i].vSetName(name);
		s[i].vSetRoll(roll);

	}
}
void cSet::vSetIntersection(cSet a, cSet b)
{
	cout<<"\nIntersection of Sets is:\n";
	for(int i=0; i<a.size; i++)
		{
			int ret = iSearchInList(b,a.s[i].iGetRoll());
			if(ret != -1)
				cout<<b.s[ret].sGetName()<<"\t\t"<<b.s[ret].iGetRoll()<<endl;
		}
}

void cSet::vSetSize(int sz)
{
	size = sz;
}
void cSet::vPutDataAtPos(int i, std::string name, int roll)
{
	s[i].vSetName(name);
	s[i].vSetRoll(roll);
}

cSet cSet::SetDifference(cSet a, cSet b)
{
	cSet retSet;
	int sz=0;
	for(int i=0; i<a.size; i++)
			{
				int ret = iSearchInList(b,a.s[i].iGetRoll());
				if(ret == -1)
				{
					retSet.vPutDataAtPos(sz, a.s[i].sGetName(), a.s[i].iGetRoll());
					sz++;
				}

			}
	retSet.vSetSize(sz);
	return retSet;

}

void cSet::vDisplaySetData()
{
	for(int i=0; i<size; i++)
		cout<<s[i].sGetName()<<"\t\t"<<s[i].iGetRoll()<<endl;
}


