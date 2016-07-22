#ifndef STRING_FUNCTIONS
#define STRING_FUNCTIONS

class stringFunctions
{
char cStr[100];
public:
	stringFunctions();
	void vStrcpy(stringFunctions);
	void vConcat(stringFunctions);
	void vPutStr();
	void vGetStr();
	void vReverse(stringFunctions &);
	int iStrLen();
        bool bIsEqual(stringFunctions);
        bool bCheckSubstr(stringFunctions);
};

#endif
