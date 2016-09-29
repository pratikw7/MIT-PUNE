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
#include <string.h>
using namespace std;

class Stack1D {      //1 dimentional stack
char cStack[50];
int top;
public:
	void vPush(char);
	char cPop();
	bool bIsEmpty();
	bool bIsFull();
	Stack1D();
	virtual ~Stack1D();
	friend class Convert;
};

Stack1D::Stack1D() {
	top = -1;

}

void Stack1D::vPush(char elem)
{
	if(!bIsFull())
	{
		top++;
		cStack[top] = elem;
	}
	else
		cout<<"Overflow!\n";

}
char Stack1D::cPop()
{
	char ret = ' ';
	if(!bIsEmpty())
	{
		ret = cStack[top];
		top--;
	}
	else
		cout<<"Underflow!\n";
	return ret;
}
inline bool Stack1D::bIsEmpty()
{
	if(top==-1)
		return true;
	return false;
}
inline bool Stack1D::bIsFull()
{
	if(top >=49)
		return true;
	return false;
}

Stack1D::~Stack1D() {

}
class Stack2D			//2 dimentional stack
{
	char cStack[20][20];
	int top;
public:
  void vPush(string &elem);
	string cPop();
	bool bIsEmpty();
	bool bIsFull();
	Stack2D();
	virtual ~Stack2D();
	friend class Convert;
};

bool Stack2D::bIsEmpty()
{
    if (top<0)
        return true;
    else
        return false;
}
bool Stack2D::bIsFull()
{
    if (top>=20)
        return true;
    else
        return false;
}

void Stack2D::vPush(string &elem)
{
    if(!bIsFull())
    {
        top++;
        elem.copy(cStack[top],20);
    }
    else
        cout<<"Overflow!\n";

}
string Stack2D::cPop()
    {
    if(!bIsEmpty())				//Check empty condition
		{
			string temp;
			temp = cStack[top];
			top--;
			return temp;
		}
		else
			cout<<"Underflow\n";

		return " ";
    }
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
	void vInfixPostfix(Convert &cExp); //Infix to postfix
	void vInfixPrefix(Convert &cExp);  //Infix to prefix
	void vPostfixInfix(Convert &cExp); //Postfix to infix
	void vPrefixInfix(Convert &cExp);  //Prefix to infix
  void vPostfixPrefix(Convert &cExp);	   //Postfix to prefix
	void vPrefixPostfix(Convert &cExp);//Prefix to postfix
void vGetData()
{
	cout<<"Enter Expression in standard form :";
	cin>>cExpr;
}
void vDisplayData()
{
	cout<<cExpr<<endl;
}
		void vReverse();
	int iPriority(char c)
	{
		if(c=='^')
			return 4;
		else if(c=='*'||c=='/')
			return 3;
		else if(c=='+'||c=='-')
			return 2;
		else if(c=='(')
			return 1;
		return 0;
	}
};

void Convert::vInfixPostfix(Convert &cExp)
{
	Stack1D s1 ;
  int k=0,i=0;
  char tkn ;

  tkn=cExp.cExpr[i];

  while(tkn!='\0'){
      if(((tkn >= 'a') && (tkn <= 'z') )|| ((tkn >= 'A') && (tkn <= 'Z')) )

      {
     	 cExpr[k]=cExp.cExpr[i];
          k++ ;
      }
      else{
            if(tkn=='(')
              s1.vPush('(');
            else {
              if(tkn==')')
             {
							 while((tkn=s1.cPop())!='('){
                    cExpr[k]=tkn ;k++ ;
                }
             }
               else {
                      while((!s1.bIsEmpty()) && (iPriority(s1.cStack[s1.top])>=iPriority(tkn) )){
                       cExpr[k]=s1.cPop();
                       k++ ;
                        }
                           s1.vPush(tkn);
                    }
           }
    }
         i++ ;
         tkn=cExp.cExpr[i];
  }

  while(!s1.bIsEmpty()){

 	 cExpr[k]=s1.cPop();
 	 k++ ;

  }
 cExpr[k]='\0';



}
void Convert::vInfixPrefix(Convert &cExp)
{
	Stack1D s2 ;
	int k=0,i=0;
	char tkn ;
	cExp.vReverse();
	tkn=cExp.cExpr[i];

	while(tkn!='\0'){
	          if(tkn!='^' && tkn!='*' && tkn!='/' && tkn!='+' && tkn!='-' && tkn!='(' && tkn!=')')
	          {
	                  cExpr[k]=cExp.cExpr[i];
	                  k++ ;
	          }
	         else{
	                if(tkn==')')
	                { s2.vPush(')');}
	              else {

	                    if(tkn=='(')
	                    {
	                          while((tkn=s2.cPop())!=')'){
	                               cExpr[k]=tkn ;k++ ;
	                    }
	                  }
	                    else {
	                            while((!s2.bIsEmpty()) && (iPriority(s2.cStack[s2.top])>iPriority(tkn) )){
	                               cExpr[k]=s2.cPop();
	                               k++ ;
	                            }
	                          s2.vPush(tkn);
	                   }
	             }
	      }
	    i++ ;
	    tkn=cExp.cExpr[i];
	}
	while(!s2.bIsEmpty()){
	    cExpr[k]=s2.cPop();
	    k++ ;
	}
	vReverse();
}
void Convert::vPrefixPostfix(Convert &cExp)
{
		cExp.vReverse();
			Stack2D s ;
				 int i=0;
				 string p1,p2,p3 ;
				 char tkn=cExp.cExpr[i];
				 while(tkn!='\0'){
				     if(((tkn >= 'a') && (tkn <= 'z') )|| ((tkn >= 'A') && (tkn <= 'Z')) )
				     {
				    	  p1=tkn;
				    	  s.vPush(p1);
				     }
				     else{

				    	 if(s.top<1)					//Check for errors
				    		 cout<<"Error! Not enough Input Values!\n"<<endl;
				    	 else{
				    		 p1=s.cPop();
				    		 p2=s.cPop();
				    		 p3=p1+p2+tkn ;
				    		 s.vPush(p3);
				    	 }

				     }
        					tkn=cExp.cExpr[++i];
			            strcpy(cExpr,s.cStack[s.top]);

				 }
	tkn=cExp.cExpr[i] ;
				 while(tkn!='\0'){
					 p1=s.cPop();
					 p3=p3+tkn;
					 s.vPush(p3);
					 i++ ;
					 tkn=cExp.cExpr[i] ;
					 strcpy(cExpr,s.cStack[s.top]);
				 }
}
void Convert::vPrefixInfix(Convert &cExp)
{
	cExp.vReverse();
	Stack2D s ;
		 int i=0;
		 string p1,p2,p3 ;
		 char tkn=cExp.cExpr[i];
		 while(tkn!='\0'){
		     if(((tkn >= 'a') && (tkn <= 'z') )|| ((tkn >= 'A') && (tkn <= 'Z')) )
		     {
		    	  p1=tkn;
		    	  s.vPush(p1);
		     }
		     else{
		    	 if(s.top<1)						//Check for errors
		    		 cout<<"Error! Not enough Input Values!\n"<<endl;
		    	 else{
		    		 p1=s.cPop();
		    		 p2=s.cPop();
		    		 p3="("+p1+tkn+p2+")" ;
		    		 s.vPush(p3);
		    	 }
		     }
	            tkn=cExp.cExpr[++i];
	            strcpy(cExpr,s.cStack[s.top]);
		 }
}
void Convert::vPostfixInfix(Convert &cExp)
{
	Stack2D s ;
	int i=0;
	string p1,p2,p3 ;
	char tkn=cExp.cExpr[i];
	while(tkn!='\0'){
			if(((tkn >= 'a') && (tkn <= 'z') )|| ((tkn >= 'A') && (tkn <= 'Z')) )
			{
				 p1=tkn;
				 s.vPush(p1);
			}
			else{
				if(s.top<1)					//Check for errors
					cout<<"Error! Not enough Input Values!\n"<<endl;
				else{
					p1=s.cPop();
					p2=s.cPop();
					p3="("+p2+tkn+p1+")" ;
					s.vPush(p3);
				}
			}
					 tkn=cExp.cExpr[++i];
					 strcpy(cExpr,s.cStack[s.top]);
	}
}

void Convert::vPostfixPrefix(Convert &cExp)
{
	Stack2D s ;
 	 int i=0;
 	 string p1,p2,p3 ;
 	 char tkn=cExp.cExpr[i];

 	 while(tkn!='\0'){
 			 if(((tkn >= 'a') && (tkn <= 'z') )|| ((tkn >= 'A') && (tkn <= 'Z')) )
 			 {
 					p1=tkn;
 					s.vPush(p1);
 					cout<<p1<<"  "<<endl;
 			 }

 			 else{

 				 if(s.top<1)			//Check for errors
 					 cout<<"Error! Not enough Input Values!\n"<<endl;
 				 else

 				 {
 					 p1=s.cPop();
 					 p2=s.cPop();
 					 p3=tkn+p2+p1 ;
 					 s.vPush(p3);
 				 }

 			 }
 						tkn=cExp.cExpr[++i];
 						strcpy(cExpr,s.cStack[s.top]);
 	 }
 while(!s.bIsEmpty() && s.top>0){
 										 p1=s.cPop();
 						 p2=s.cPop();
 						 p3=p2+p1 ;
 						 s.vPush(p3);
 						 tkn=cExp.cExpr[++i];
 						 strcpy(cExpr	,s.cStack[s.top]);
 }
}
void Convert::vReverse()
{
	Stack1D t1 ;
  int i=0;

  while(cExpr[i]!='\0'){
      t1.vPush(cExpr[i]);
    i++ ;
  }
   i=0;
  do{
    cExpr[i]=t1.cPop();
       i++ ;

  }while(!t1.bIsEmpty());
  cExpr[i]='\0';
}

int main()
{
    Convert g1, c1;			//Two objects, one to store original other to store result
	char inp;
	do
	{
		cout<<"1. Infix to Postfix\n";
		cout<<"2. Infix to Prefix\n";
		cout<<"3. Postfix to Infix\n";
		cout<<"4. Prefix to Infix\n";
		cout<<"5. Postfix to Prefix\n";
		cout<<"6. Prefix to Postfix\n";
		cin>>inp;
		switch(inp)
		{
		case '1':
		g1.vGetData();
		c1.vInfixPostfix(g1);
		cout<<"Expression in Post-fix form : ";
		c1.vDisplayData();
			break;
		case '2':
			g1.vGetData();
			c1.vInfixPrefix(g1);
			cout<<"Expression in Prefix form : ";
			c1.vDisplayData();
			break;
		case '3':
		g1.vGetData();
		c1.vPostfixInfix(g1);
		cout<<"Expression in Post-fix form : ";
		c1.vDisplayData();
		break;

		case '4':
		g1.vGetData();
		c1.vPrefixInfix(g1);
		cout<<"Expression in Infix form : ";
		c1.vDisplayData();
		break;

		case '5':
		g1.vGetData();
		c1.vPostfixPrefix(g1);
		cout<<"Expression in Infix form : ";
		c1.vDisplayData();
		break;

		case '6':
		g1.vGetData();
		c1.vPrefixPostfix(g1);
		cout<<"Expression in Prefix form : ";
		c1.vDisplayData();
			break;
		}
		cout<<"Do you want to continue?(y)";
		cin>>inp;
	}while(inp=='y');
	return 0;
}
/*-------------OUTPUT---------------------
1. Infix to Postfix
2. Infix to Prefix
3. Postfix to Infix
4. Prefix to Infix
5. Postfix to Prefix
6. Prefix to Postfix
1
Enter Expression in standard form :(a+b)*c
Expression in Post-fix form : ab+c*
Do you want to continue?(y)y
1. Infix to Postfix
2. Infix to Prefix
3. Postfix to Infix
4. Prefix to Infix
5. Postfix to Prefix
6. Prefix to Postfix
2
Enter Expression in standard form :(a+b)*c
Expression in Prefix form : *+abc
Do you want to continue?(y)y
1. Infix to Postfix
2. Infix to Prefix
3. Postfix to Infix
4. Prefix to Infix
5. Postfix to Prefix
6. Prefix to Postfix
3
Enter Expression in standard form :ab+c*
Expression in Post-fix form : ((a+b)*c)
Do you want to continue?(y)y
1. Infix to Postfix
2. Infix to Prefix
3. Postfix to Infix
4. Prefix to Infix
5. Postfix to Prefix
6. Prefix to Postfix
4
Enter Expression in standard form :*+abc
Expression in Infix form : ((a+b)*c)
Do you want to continue?(y)y
1. Infix to Postfix
2. Infix to Prefix
3. Postfix to Infix
4. Prefix to Infix
5. Postfix to Prefix
6. Prefix to Postfix
5
Enter Expression in standard form :ab+c*   
a  
b  
c  
Expression in Infix form : *+abc
Do you want to continue?(y)y
1. Infix to Postfix
2. Infix to Prefix
3. Postfix to Infix
4. Prefix to Infix
5. Postfix to Prefix
6. Prefix to Postfix
6
Enter Expression in standard form :*+abc
Expression in Prefix form : ab+c*
Do you want to continue?(y)n

*/
