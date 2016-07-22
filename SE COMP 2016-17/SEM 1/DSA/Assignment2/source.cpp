#include<iostream>

#include "student.h"
#include "setFunctions.h"

using namespace std;


int main()
{
	cSet cTotal, cCricket, cBadminton;
	cout<<"Set of students in Class: \n";
	cTotal.vGetData();
	cout<<"Set of students who play cricket: \n";
	cCricket.vGetData();
	cout<<"Set of students who play Badminton: \n";
	cBadminton.vGetData();
	char inp;
	do
	{
		cout<<"1. Set of students who play either cricket or badminton or both\n";
		cout<<"2. Set of students who play both cricket and badminton\n";
		cout<<"3. Set of students who play only Cricket\n";
		cout<<"4. Set of students who play only Badminton\n";
		cout<<"5. Set of students who play neither badminton nor cricket\n";
		cin>> inp;
		cSet cret;
		switch (inp)
		{
			case '1':
				cTotal.vSetUnion(cCricket, cBadminton);
				break;
			case '2':
				cTotal.vSetIntersection(cCricket, cBadminton);
				break;
			case '3':
				cret = cTotal.SetDifference(cCricket, cBadminton);
				cret.vDisplaySetData();
				break;
			case '4':
				cret = cTotal.SetDifference(cBadminton,cCricket);
				cret.vDisplaySetData();
				break;
			case '5':
				cret = cTotal.SetDifference(cTotal,cCricket);
				cret = cTotal.SetDifference(cret,cBadminton);
				cret.vDisplaySetData();
				break;
			default:
				cout<<"Please enter a valid input!";
				break;
		}
		cout<<"Do you want to continue? (y)";
		cin>>inp;
	}while(inp =='y');
	return 0;
}
***********************************************************************
Set of students in Class: 
Enter size of set: 4
Enter student name: Ashwin
Enter roll number: 30
Enter student name: Tony
Enter roll number: 32
Enter student name: Stark  
Enter roll number: 45
Enter student name: Bruce
Enter roll number: 12
Set of students who play cricket: 
Enter size of set: 2
Enter student name: Tony
Enter roll number: 32
Enter student name: Bruce
Enter roll number: 12
Set of students who play Badminton: 
Enter size of set: 2
Enter student name: Bruce
Enter roll number: 12
Enter student name: Bruce
Enter roll number: 12
Input data already exists in the set
Enter student name: Stark
Enter roll number: 45
1. Set of students who play either cricket or badminton or both
2. Set of students who play both cricket and badminton
3. Set of students who play only Cricket
4. Set of students who play only Badminton
5. Set of students who play neither badminton nor cricket
1
Union of Sets is:
Bruce		12
Stark		45
Tony		32
Do you want to continue? (y)y
1. Set of students who play either cricket or badminton or both
2. Set of students who play both cricket and badminton
3. Set of students who play only Cricket
4. Set of students who play only Badminton
5. Set of students who play neither badminton nor cricket
2

Intersection of Sets is:
Bruce		12
Do you want to continue? (y)y
1. Set of students who play either cricket or badminton or both
2. Set of students who play both cricket and badminton
3. Set of students who play only Cricket
4. Set of students who play only Badminton
5. Set of students who play neither badminton nor cricket
3
Tony		32
Do you want to continue? (y)y
1. Set of students who play either cricket or badminton or both
2. Set of students who play both cricket and badminton
3. Set of students who play only Cricket
4. Set of students who play only Badminton
5. Set of students who play neither badminton nor cricket
4
Stark		45
Do you want to continue? (y)y
1. Set of students who play either cricket or badminton or both
2. Set of students who play both cricket and badminton
3. Set of students who play only Cricket
4. Set of students who play only Badminton
5. Set of students who play neither badminton nor cricket
5
Ashwin		30
Do you want to continue? (y)n
