//-----------------Ashwin Vaidya-----------------
//------------------202030-----------------------
//--------------------SE1------------------------

#ifndef STACK_H_
#define STACK_H_

class Stack {
char cStack[50];
int top;
public:
	void vPush(char elem);
	char cPop();
	bool isEmpty();
	bool isFull();
	Stack();
	virtual ~Stack();
};

#endif /* STACK_H_ */
