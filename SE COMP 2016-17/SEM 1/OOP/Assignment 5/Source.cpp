//Ashwin Vaidya
//SE202030
//SE COMP I
#include <iostream>
#include "student.h"
#include <stdio.h>

int main()
{
	Student *record;
	cSearch a;
	char inp;
	int n, flag;
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
	cout<<"4. Modify Record\n";
	cin>>inp;
	switch(inp)
	{
	case '1':
		if(Student::iGetCount()>= n+4)
		{
			cout<<"Overflow!\n";
			break;
		}
		record[Student::iGetCount()].vAddDetails();
		break;
	case '2':
		flag=a.Search(record,Student::iGetCount());
		if(flag==-1)
		{
			cout<<"The student's name is not in the database\n";
		}
		else
		{
			for(int i=flag; i<Student::iGetCount();i++)
				record[i] = record[i+1];
			Student::decreaseCount();
		}
		break;
	case '3':
		cout<<"Number of records are: "<<Student::iGetCount()<<endl;
		for(int i=0; i<Student::iGetCount(); i++)
			record[i].vDisplayData();
		break;
	case '4':
		flag = a.Search(record, Student::iGetCount());
		if(flag==-1)
				{
					cout<<"The student's name is not in the database\n";
				}
		else
		{
			record[flag].vAddDetails();
		}
		break;
	default:
		cout<<"Enter a valid input!\n";
		break;
	}
	cout<<"Do you want to continue? (y)\n";
	cin>>inp;
	}while(inp=='y');	
	

		
	return 0;
}
//-------------OUTPUT----------------------
/*
Enter the number of records you want to add: 3
Enter name: Ashwin
Enter roll number: 30
Enter phone number: 8826347839
Enter Address: Nr. Mit
Enter class: S1
Enter Blood group: O+
Enter D.O.B (DD/MM/YY): 17 03 97
------------------------------------------------
Name: Ashwin
Address: Nr. Mit
Roll no.: 30
Phone no.: 8826347839
Class: S1
Blood Group: O+
D.O.B: 17/3/97
------------------------------------------------
Enter name: asdf
Enter roll number: 34
Enter phone number: 3245789345
Enter Address: zsfg wer
Enter class: S2
Enter Blood group: A+
Enter D.O.B (DD/MM/YY): 12 12 12
------------------------------------------------
Name: asdf
Address: zsfg wer
Roll no.: 34
Phone no.: 3245789345
Class: S2
Blood Group: A+
D.O.B: 12/12/12
------------------------------------------------
Enter name: fasd
Enter roll number: 34
Enter phone number: 34686
Enter Address: sdf sd
Enter class: S1
Enter Blood group: B
Enter D.O.B (DD/MM/YY): 12 03 99
------------------------------------------------
Name: fasd
Address: sdf sd
Roll no.: 34
Phone no.: 34686
Class: S1
Blood Group: B
D.O.B: 12/3/99
------------------------------------------------
1. Add Entry to Database
2. Delete Entry from Database
3. Display Database
4. Modify Record
1
Enter name: sad
Enter roll number: 23
Enter phone number: 2347895
Enter Address: 50 sdjh
Enter class: S2 
Enter Blood group: B+
Enter D.O.B (DD/MM/YY): 13 13 97
------------------------------------------------
Name: sad
Address: 50 sdjh
Roll no.: 23
Phone no.: 2347895
Class: S2
Blood Group: B+
D.O.B: 13/13/97
------------------------------------------------
Do you want to continue? (y)
y
1. Add Entry to Database
2. Delete Entry from Database
3. Display Database
4. Modify Record
3
Number of records are: 4
------------------------------------------------
Name: Ashwin
Address: Nr. Mit
Roll no.: 30
Phone no.: 8826347839
Class: S1
Blood Group: O+
D.O.B: 17/3/97
------------------------------------------------
------------------------------------------------
Name: asdf
Address: zsfg wer
Roll no.: 34
Phone no.: 3245789345
Class: S2
Blood Group: A+
D.O.B: 12/12/12
------------------------------------------------
------------------------------------------------
Name: fasd
Address: sdf sd
Roll no.: 34
Phone no.: 34686
Class: S1
Blood Group: B
D.O.B: 12/3/99
------------------------------------------------
------------------------------------------------
Name: sad
Address: 50 sdjh
Roll no.: 23
Phone no.: 2347895
Class: S2
Blood Group: B+
D.O.B: 13/13/97
------------------------------------------------
Do you want to continue? (y)
y
1. Add Entry to Database
2. Delete Entry from Database
3. Display Database
4. Modify Record
2
Enter Name of student:	sad
Enter Roll Number:	23
Do you want to continue? (y)
y
1. Add Entry to Database
2. Delete Entry from Database
3. Display Database
4. Modify Record
3
Number of records are: 3
------------------------------------------------
Name: Ashwin
Address: Nr. Mit
Roll no.: 30
Phone no.: 8826347839
Class: S1
Blood Group: O+
D.O.B: 17/3/97
------------------------------------------------
------------------------------------------------
Name: asdf
Address: zsfg wer
Roll no.: 34
Phone no.: 3245789345
Class: S2
Blood Group: A+
D.O.B: 12/12/12
------------------------------------------------
------------------------------------------------
Name: fasd
Address: sdf sd
Roll no.: 34
Phone no.: 34686
Class: S1
Blood Group: B
D.O.B: 12/3/99
------------------------------------------------
Do you want to continue? (y)
y
1. Add Entry to Database
2. Delete Entry from Database
3. Display Database
4. Modify Record
4
Enter Name of student:	Ashwin
Enter Roll Number:	30
Enter name: sadf
Enter roll number: 25 
Enter phone number: 2345
Enter Address: dfg 3245
Enter class: S2
Enter Blood group: AB
Enter D.O.B (DD/MM/YY): 14 12 99
------------------------------------------------
Name: sadf
Address: dfg 3245
Roll no.: 25
Phone no.: 2345
Class: S2
Blood Group: AB
D.O.B: 14/12/99
------------------------------------------------
Do you want to continue? (y)
n


*/

