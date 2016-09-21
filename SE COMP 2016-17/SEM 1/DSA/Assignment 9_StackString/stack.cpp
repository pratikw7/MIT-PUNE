//-----------------Ashwin Vaidya-----------------
//------------------202030-----------------------
//--------------------SE1------------------------

#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
	top = -1;

}

void Stack::vPush(char elem)
{
	if(!isFull())
	{
		top++;
		cStack[top] = elem;
	}
	else
		cout<<"Overflow!\n";

}
char Stack::cPop()
{
	char ret = '\0';
	if(!isEmpty())
	{
		ret = cStack[top];
		top--;
	}
	else
		cout<<"Underflow!\n";
	return ret;
}
inline bool Stack::isEmpty()
{
	if(top==-1)
		return true;
	return false;
}
inline bool Stack::isFull()
{
	if(top >=49)
		return true;
	return false;
}

Stack::~Stack() {

}

