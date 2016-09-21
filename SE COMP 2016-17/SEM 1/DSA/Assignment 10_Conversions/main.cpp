//----------Ashwin Vaidya----------
//-------------202030--------------
//---------------SE-1--------------
//a.Infix to post fix
//b.Infix to prefix
//c.prefix to postfix
//d.Prefix to infix
//e.Postfix to infix
//f.Postfix to prefix
#include <iostream>
#include <cstdio>
using namespace std;
class Stack1D {
char cStack[50];
int top;
public:
	void vPush(char elem);
	char cPop();
	bool isEmpty();
	bool isFull();
	Stack1D();
	virtual ~Stack1D();
};

Stack1D::Stack1D() {
	top = -1;

}

void Stack1D::vPush(char elem)
{
	if(!isFull())
	{
		top++;
		cStack[top] = elem;
	}
	else
		cout<<"Overflow!\n";

}
char Stack1D::cPop()
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
inline bool Stack1D::isEmpty()
{
	if(top==-1)
		return true;
	return false;
}
inline bool Stack1D::isFull()
{
	if(top >=49)
		return true;
	return false;
}

Stack1D::~Stack1D() {

}

class Stack2D
{
	char cStack[20][20];
	int top;
public:
	void vPush(char *elem);
	char* cPop();
	bool bIsEmpty();
	bool bIsFull();
	Stack2D();
	virtual ~Stack2D();
};
Stack2D::Stack2D()
{
	top = -1;
	for(int i=0; i<20; i++)
		for(int j=0; j<20; j++)
			cStack[i][j]='\0';
}
Stack2D::~Stack2D()
{}

class Convert
{
	char cExpr[50];
public:
	void vInfixPostfix(Convert &cExp);
	void vInfixPrefix(Convert &cExp);
	void vPrefixPostfix(Convert &cExp);
	void vPostfixInfix(Convert &cExp);
	void vPostfixPrefix(Convert &cExp);
	int iPriority(char c)
	{
		if(c=='^')
			return 4;
		else if(c=='*'||c=='/')
			return 3;
		else if(c=='+'||c=='-')
			return 2;
		else if(c=='('||c==')')
			return 1;
		return 0;
	}
};

void Convert::vInfixPostfix(Convert &cExp)
{
	cout<<"Enter a Infix expression: ";
	gets(cExpr);
}
void Convert::vInfixPrefix(Convert &cExp)
{
	cout<<"Enter a Infix expression: ";
	gets(cExpr);
}
void Convert::vPrefixPostfix(Convert &cExp)
{
	cout<<"Enter a Prefix expression: ";
	gets(cExpr);
}
void Convert::vPostfixInfix(Convert &cExp)
{
	cout<<"Enter a Postfix expression: ";
	gets(cExpr);
}
void Convert::vPostfixPrefix(Convert &cExp)
{
	cout<<"Enter a Postfix expression: ";
	gets(cExpr);
}


int main()
{
	char inp;
	do
	{
		cout<<"1. Infix to Postfix\n";
		cout<<"2. Infix to Prefix\n";
		cout<<"3. Prefix to Postfix\n";
		cout<<"4. Prefix to Infix\n";
		cout<<"5. Postfix to Infix\n";
		cout<<"6. Postfix to Prefix\n";
		cin>>inp;
		switch(inp)
		{
		case '1':
			break;
		case '2':
			break;
		case '3':
				break;
		case '4':
				break;
		case '5':
				break;
		case '6':
				break;
		}
		cout<<"Do you want to continue?(y)";
		cin>>inp;
	}while(inp=='y');
	return 0;
}

