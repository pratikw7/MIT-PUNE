/*
 * student.cpp
 *
 *  	SE 202030
 *      Author: Ashwin Vaidya
 */

#include "student.h"
#include <stdio.h>

int cSearch::Search(Student *s,int n)
		{
			char *name = new char[15];
			cout<<"Enter Name of student:\t";
			cin.ignore();
			gets(name);
			cout<<"Enter Roll Number:\t";
			int roll;
			cin>>roll;
			int i,flag;
			for(i=0;i<n;i++)
			{
				if(strcmp(s[i].sName,name)==0&&s[i].iRoll==roll)
				{
						flag=i;
						return flag;
				}
				else
				{
						flag=-1;
				}
			}
			return flag;
		}

Student::Student()
{
	
	iRoll = -1;
	iPhoneNo = -1;
	DOB.DD= -1;
	DOB.MM= -1;
	DOB.YY= -1;
}
int Student::iNoOfStudents =0;
void Student::vAddDetails() 
{
		sName = new char[15];
		cout<<"Enter name: ";
		cin.ignore();
		gets(sName);
		cout<<"Enter roll number: ";
		cin>>iRoll;
		cout<<"Enter phone number: ";
		cin>>iPhoneNo;
		sAddr = new char[15];
		cout<<"Enter Address: ";
		cin.ignore();
		gets(sAddr);
		sClass = new char[2];
		cout<<"Enter class: ";
		cin>>sClass;
		sBloodGrp = new char[2];
		cout<<"Enter Blood group: ";
		cin>>sBloodGrp;
		cout<<"Enter D.O.B (DD/MM/YY): ";
		cin>>DOB.DD>>DOB.MM>>DOB.YY;
		vDisplayData();
		iNoOfStudents++;

}
int Student::iGetCount()
{
	return iNoOfStudents;
}
void Student::decreaseCount()
{
	iNoOfStudents--;
}

void Student::vDisplayData()
{
	cout<<"------------------------------------------------\n";
	cout<<"Name: "<<sName<<endl;
	cout<<"Address: "<<sAddr<<endl;
	cout<<"Roll no.: "<<iRoll<<endl;
	cout<<"Phone no.: "<<iPhoneNo<<endl;
	cout<<"Class: "<<sClass<<endl;
	cout<<"Blood Group: "<<sBloodGrp<<endl;
	cout<<"D.O.B: "<<DOB.DD<<"/"<<DOB.MM<<"/"<<DOB.YY<<endl;
	cout<<"------------------------------------------------\n";
}

Student::~Student() {
	delete sName;
	delete sAddr;
	delete sClass;
	delete sBloodGrp;
}

