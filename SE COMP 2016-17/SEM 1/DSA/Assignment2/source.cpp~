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
