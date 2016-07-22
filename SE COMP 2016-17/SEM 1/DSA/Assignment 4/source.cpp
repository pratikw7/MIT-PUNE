#include <iostream>
#include <stdio.h>
#include <cstring>
#include "stringFunctions.h"
using namespace std;

int main()
{
	stringFunctions sStr1, sStr2, sStr3;
	char cStr1[15], cStr2[15];
	
	char inp;


	cout<<"1. Use Library functions\n";
	cout<<"2. Use User created functions\n";
	cin>>inp;
	cin.ignore();
	if(inp=='1')
	{
        cout<<"Enter string 1\n";
	gets(cStr1);
        cout<<"Enter string 2\n";
	gets(cStr2);
	do
	{

	cout<<"1. Get string length of both\n";
	cout<<"2. Copy string 1 in string 2\n";
	cout<<"3. Concatenate strings\n";
	cout<<"4. Check if both are equal\n";
	cout<<"5. Change values of strings\n";
	cin>>inp;
	cin.ignore();
	switch(inp)
	{
	case '1':
      		cout<<"Length of string 1: "<<strlen(cStr1)<<endl;
  		cout<<"Length of string 2: "<<strlen(cStr2)<<endl;
  		break;
	case '2':
      		strcpy(cStr2, cStr1);
  		cout<<"New string 2 is : ";
  		puts(cStr2);
		cout<<endl;
  		break;
	case '3':
		cout<<"New String is : ";
		strcat(cStr1, cStr2);
  		puts(cStr1);
		cout<<endl;
  		break;
	case '4':
        	if(!strcmp(cStr1, cStr2))
          	 cout<<"Both are Equal\n";
		else
		 cout<<"Both are not equal\n";
  		break;
	case '5':
        cout<<"Enter string 1\n";
	gets(cStr1);
        cout<<"Enter string 2\n";
	gets(cStr2);
  		break;
	default:
		cout<<"Enter a valid option\n";
		break;
	}

	puts("Do you want to continue? (y)\n");
	cin>>inp;
	cin.ignore();
	}while(inp=='y');
	}
	else if(inp=='2')
	{
        cout<<"Enter string 1\n";
	sStr1.vGetStr();
        cout<<"Enter string 2\n";
        sStr2.vGetStr();
	do
	{

	cout<<"1. Get string length of both\n";
	cout<<"2. Copy string 1 in string 2\n";
	cout<<"3. Reverse Strings\n";
	cout<<"4. Concatenate strings\n";
	cout<<"5. Check if both are equal\n";
	cout<<"6. Check substring in string 1\n";
	cout<<"7. Change values of strings\n";
	cin>>inp;
	cin.ignore();
	switch(inp)
	{
	case '1':
      		cout<<"Length of string 1: "<<sStr1.iStrLen()<<endl;
  		cout<<"Length of string 2: "<<sStr2.iStrLen()<<endl;
  		break;
	case '2':
      		sStr2.vStrcpy(sStr1);
  		cout<<"New string 2 is : ";
  		sStr1.vPutStr();
		cout<<endl;
  		break;
	case '3':
		cout<<"Reverse of fist string is : ";
		sStr1.vReverse(sStr3);
		sStr3.vPutStr();
  		cout<<"\nReverse of second string is : ";
      		sStr2.vReverse(sStr3);
		sStr3.vPutStr();
		cout<<endl;
  		break;
	case '4':
		cout<<"New String is : ";
		sStr1.vConcat(sStr2);
  		sStr1.vPutStr();
		cout<<endl;
  		break;
	case '5':
        	if(sStr1.bIsEqual(sStr2))
          	 cout<<"Both are Equal\n";
		else
		 cout<<"Both are not equal\n";
  		break;
	case '6':
        	cout<<"Enter substring\n";
        	sStr3.vGetStr();
		if(sStr1.bCheckSubstr(sStr3))
			cout<<"It is a substring!\n";
		else		
			cout<<"It is not a substring!\n";
  		break;
	case '7':
        cout<<"Enter string 1\n";
	sStr1.vGetStr();
        cout<<"Enter string 2\n";
        sStr2.vGetStr();

  		break;
	default:
		cout<<"Enter a valid option\n";
		break;
	}

	puts("Do you want to continue? (y)\n");
	cin>>inp;
	cin.ignore();
	}while(inp=='y');
	}
	
	return 0;
}
/**************************************************************************
1. Use Library functions
2. Use User created functions
1
Enter string 1
ashwin
Enter string 2
vaidya
1. Get string length of both
2. Copy string 1 in string 2
3. Concatenate strings
4. Check if both are equal
5. Change values of strings
1
Length of string 1: 6
Length of string 2: 6
Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Concatenate strings
4. Check if both are equal
5. Change values of strings
2
New string 2 is : ashwin

Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Concatenate strings
4. Check if both are equal
5. Change values of strings
4
Both are Equal
Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Concatenate strings
4. Check if both are equal
5. Change values of strings
3
New String is : ashwinashwin

Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Concatenate strings
4. Check if both are equal
5. Change values of strings
4
Both are not equal
Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Concatenate strings
4. Check if both are equal
5. Change values of strings
5
Enter string 1
ashwin
Enter string 2
vaidya
Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Concatenate strings
4. Check if both are equal
5. Change values of strings
3
New String is : ashwinvaidya

Do you want to continue? (y)

1. Use Library functions
2. Use User created functions
2
Enter string 1
ashwin
Enter string 2
vaidya
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
1
Length of string 1: 6
Length of string 2: 6
Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
2
New string 2 is : ashwin

Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
3
Reverse of fist string is : niwhsa

Reverse of second string is : niwhsa

Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
7
Enter string 1
ashwin
Enter string 2
vaidya
Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
5
Both are not equal
Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
2
New string 2 is : ashwin

Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
5
Both are Equal
Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
3
Reverse of fist string is : niwhsa

Reverse of second string is : niwhsa

Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
6
Enter substring
win
It is a substring!
Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
6
Enter substring
was
It is not a substring!
Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
7
Enter string 1
ashwin
Enter string 2
vaidya
Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
4
New String is : ashwinvaidya

Do you want to continue? (y)

y
1. Get string length of both
2. Copy string 1 in string 2
3. Reverse Strings
4. Concatenate strings
5. Check if both are equal
6. Check substring in string 1
7. Change values of strings
3
Reverse of fist string is : aydiavniwhsa

Reverse of second string is : aydiav

Do you want to continue? (y)





*/


