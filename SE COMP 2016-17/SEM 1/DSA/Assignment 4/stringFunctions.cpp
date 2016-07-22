#include "stringFunctions.h"
#include <stdio.h>
#include <iostream>
using namespace std;
stringFunctions::stringFunctions()
{
	cStr[0] = '\0';
}
void stringFunctions::vStrcpy(stringFunctions sStr2)
{
	int i=0;
	for(; sStr2.cStr[i]!='\0'; i++)
	{
	cStr[i] = sStr2.cStr[i];
	}
	cStr[i] = '\0';
}
void stringFunctions::vConcat(stringFunctions sStr2)
{
	int i=0, j=0;
	i = this->iStrLen();
	for(; sStr2.cStr[j]!='\0'; j++,i++)
		cStr[i] = sStr2.cStr[j];
	cStr[i] = '\0';
	
}
void stringFunctions::vPutStr()
{
	puts(cStr);
}
void stringFunctions::vGetStr()
{
	gets(cStr);
}
void stringFunctions::vReverse(stringFunctions &sRev)
{

	int i,len;
	len = this->iStrLen();
	for(i=0; i<len;i++)
		sRev.cStr[i] = cStr[len-1-i];
	sRev.cStr[i] = '\0';

}
int stringFunctions::iStrLen()
{	
	int len;
	for(len =0; cStr[len]!='\0'; len++);
	return len;
}

bool stringFunctions::bIsEqual(stringFunctions str2)
{
  if(this->iStrLen() == str2.iStrLen())
   {
    for(int i =0; cStr[i] != '\0'; i++)
	{
		if(cStr[i] != str2.cStr[i])
 		   return false;
	}
        return true;
   }
   else
     return false;
}
bool stringFunctions::bCheckSubstr(stringFunctions str2)
{
   int j=0, flag=0;
   for(int i =0; cStr[i] != '\0'; i++)
	{
	  if(cStr[i] == str2.cStr[j])
            {
              for(j=0;str2.cStr[j]!='\0'; j++)
		{
		  if(cStr[i+j] != str2.cStr[j])
		   {
			flag=0;
			break;
		   }
			flag=1;
		}
		if(flag)
		   break;
            }
	}
   if(!flag)
	return false;
   else
 	return true;
}
