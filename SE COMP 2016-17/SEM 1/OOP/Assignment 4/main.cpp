#include <iostream>
#include "complex.h"

int main()
{
	Complex cNo1, cNo2,ret;
	char inp;
	cout<<"Enter a complex number: \n";
	cin>>cNo1;
	cout<<"Enter another number: \n";
	cin>>cNo2;	
	do
	{
	cout<<"\n1. Add a complex number to it";
	cout<<"\n2. Multiply a complex number to it\n";	
	cin>>inp;
	switch(inp)
	{
		case '1':

		ret = cNo1 + cNo2;
		cout<<"Sum is: "<<ret<<endl;		
		break;
		case '2':
		
		ret = cNo1 * cNo2;
		cout<<"Product is: "<<ret<<endl;
		break;
		default:
		cout<<"Please enter a valid input";
		break;
	}
	cout<<"Do you want to continue ?(y)\n";
	cin>>inp;
	}while(inp=='y');
	return 0;
}
