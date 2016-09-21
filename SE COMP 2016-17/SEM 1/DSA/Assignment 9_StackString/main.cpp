//-----------------Ashwin Vaidya-----------------
//------------------202030-----------------------
//--------------------SE1------------------------
#include <iostream>
#include <stdio.h>
#include "string.h"

using namespace std;

int main()
{
	char inp;
	String temp;
	cout<<"Enter a string: ";
	temp.vGetString();
	cout<<"String is: ";
	temp.vPutString();
	do
	{
	cout<<"1. Check whether the string is palindrome\n";
	cout<<"2. Remove spaces, punctuations and convert to lowercase & check for palindrome\n";
	cout<<"3. Print string in reverse order\n";
	cout<<"4. Modify string\n";
	cin>>inp;
	switch(inp)
	{
	case '1':
		if(temp.isPalindrome())
				cout<<"It is a palindrome!\n";
		else
			cout<<"NOT a Palindrome!\n";
		break;
	case '2':
		temp.vRemove();
		cout<<"New string is: ";
		temp.vPutString();
		cout<<"\n";
		if(temp.isPalindrome())
				cout<<"It is a palindrome!\n";
		else
				cout<<"NOT a Palindrome!\n";
		break;
	case '3':
		temp.vReverse();
		cout<<"New string is: ";
		temp.vPutString();
		cout<<endl;
		break;
	case '4':
		cin.ignore();
		cout<<"Enter a string: ";
		temp.vGetString();
		cout<<"String is: ";
		temp.vPutString();
		break;
	}
	cout<<"Do you want to continue?(y)";
	cin>>inp;
	}while(inp=='y');
	return 0;
}
/*---------------OUTPUT------------------------
 * Enter a string: TacO c@at
String is: TacO c@at
1. Check whether the string is palindrome
2. Remove spaces, punctuations and convert to lowercase & check for palindrome
3. Print string in reverse order
4. Modify string
3
New string is: ta@c OcaT

Do you want to continue?(y)y
1. Check whether the string is palindrome
2. Remove spaces, punctuations and convert to lowercase & check for palindrome
3. Print string in reverse order
4. Modify string
1
NOT a Palindrome!
Do you want to continue?(y)y
1. Check whether the string is palindrome
2. Remove spaces, punctuations and convert to lowercase & check for palindrome
3. Print string in reverse order
4. Modify string
2
New string is: tacocat

It is a palindrome!
Do you want to continue?(y)y
1. Check whether the string is palindrome
2. Remove spaces, punctuations and convert to lowercase & check for palindrome
3. Print string in reverse order
4. Modify string
4
Enter a string: T@CO Cat
String is: T@CO Cat
Do you want to continue?(y)y
1. Check whether the string is palindrome
2. Remove spaces, punctuations and convert to lowercase & check for palindrome
3. Print string in reverse order
4. Modify string
2
New string is: tcocat

NOT a Palindrome!
Do you want to continue?(y)
 */

