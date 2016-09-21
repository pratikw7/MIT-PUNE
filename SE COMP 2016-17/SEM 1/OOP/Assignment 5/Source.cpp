//-----------------Ashwin Vaidya----------------
//-----------------SE202030---------------------
//-----------------SE COMP I--------------------
#include <iostream>
#include <stdio.h>
using namespace std;

class Search{
	
};

class Student {
	static int iNoOfStudents;
	char* sName;
	char* sAddr;
	char *sClass;
	char *sBloodGrp;
	int iRoll;
	unsigned long int iPhoneNo;
	struct sDOB{int DD; int MM; int YY;}DOB;
	friend class Search;
public:
	Student();
	Student(Student &s);
	//Student(char*, char*,char*, char*, int, unsigned long int, int, int, int);
	static int iGetCount();
	static void vDeleteData();
	void vAddDetails();
	void vDisplayData();
	~Student();
};
Student::Student()
{
	
	iRoll = -1;
	iPhoneNo = -1;
	DOB.DD= -1;
	DOB.MM= -1;
	DOB.YY= -1;
}
Student::Student(Student &s)
{
		
		sName = s.sName;
		iRoll = s.iRoll;
		iPhoneNo = s.iPhoneNo;
		sAddr = s.sAddr;
		sClass= s.sClass;
		sBloodGrp = s.sBloodGrp;
		DOB.DD = s.DOB.DD;
		DOB.MM = s.DOB.MM;
		DOB.YY = s.DOB.YY;
		iNoOfStudents++;
}
/*Student::Student(char* name, char* address,char* sCls, char* BG, int roll, unsigned long int phoneNo, int D, int M, int Y)
{
	//sName = new char[15];
	//sAddr = new char[15];
	//sClass = new char[2];
	sName = name;
	sAddr = address;
	sClass = sCls;
	sBloodGrp = BG;
	iRoll = roll;
	iPhoneNo = phoneNo;
	DOB.DD = D;
	DOB.MM = M;
	DOB.YY = Y;
}*/
int Student::iNoOfStudents =0;
void Student::vDeleteData()
{
	char *name  = new char[15];
	int roll;
	cout<<"Enter the name";
	cin.ignore();
	gets(name);
	cout<<"Enter roll number: ";
	cin>>roll;
	delete name;
}
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


int main()
{
	Student *record;
	char inp;
	int n;
	cout<<"Enter the number of records you want to add: ";
	cin>>n;
	record = new Student[n+5];
	for(int i =0; i<n; i++)
	{
	   record[i].vAddDetails();
	}
	do
	{
	cout<<"1. Add Entry to Database\n";
	cout<<"2. Delete Entry from Database\n";
	cout<<"3. Display Database\n";
	cin>>inp;
	switch(inp)
	{
	case '1':
		{
		if(Student::iGetCount()==n+4)
		{
			cout<<"Cannot add more entries to database!\n";
			break;
		}
		record[Student::iGetCount()].vAddDetails();		
		break;
		}
	case '2':
		
		break;
	case '3':
		cout<<"Number of records are: "<<Student::iGetCount()<<endl;
		for(int i=0; i<Student::iGetCount(); i++)
			record[i].vDisplayData();
		break;
	default:
		cout<<"Enter a valid input!\n";
	}
	cout<<"Do you want to continue? (y)\n";
	cin>>inp;
	}while(inp=='y');	


		
	return 0;
}
