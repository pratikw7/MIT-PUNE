//-----------------Ashwin Vaidya-----------------
//------------------202030-----------------------
//--------------------SE1------------------------

#include "string.h"
#include "stack.h"
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

String::String() {


}

void String::vGetString()
{
	//cin.ignore();
	gets(cStr);
}
void String::vPutString()
{
	puts(cStr);
}

void String::vReverse()
{
	int i=0;
	Stack temp;
	while(cStr[i]!= '\0')
	{
		temp.vPush(cStr[i]);
		i++;
	}
	i=0;
	while(!temp.isEmpty())
	{
		cStr[i] = temp.cPop();
		i++;
	}
	cStr[i] = '\0';
}
bool String::isPalindrome()
{
	String sStr1;
	strcpy(sStr1.cStr,cStr);
	sStr1.vReverse();
	if(strcmp(sStr1.cStr,cStr)==0)
		return true;
	return false;

}
void String::vRemove()
{
	String sTemp;
	int i=0, j=0;
	while(cStr[i]!= '\0')
		{
			if(cStr[i]>=65&&cStr[i]<=90)
			{
				sTemp.cStr[j] = cStr[i]+32;
				j++;
				i++;
			}
			else if(cStr[i]>=97&&cStr[i]<=122)
			{
				sTemp.cStr[j] = cStr[i];
				j++;
				i++;
			}
			else
				i++;
		}
sTemp.cStr[j] = '\0';
	strcpy(cStr,sTemp.cStr);
}

String::~String() {

}

