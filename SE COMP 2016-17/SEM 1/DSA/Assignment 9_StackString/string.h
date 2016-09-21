//-----------------Ashwin Vaidya-----------------
//------------------202030-----------------------
//--------------------SE1------------------------

#ifndef STRING_H_
#define STRING_H_

class String {
char cStr[25];
public:
	String();
	void vGetString();
	void vPutString();
	void vReverse();
	bool isPalindrome();
	void vRemove();
	~String();
};

#endif /* STRING_H_ */
