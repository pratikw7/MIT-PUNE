//------------Ashwin Vaidya---------------
//---------------SE202030-----------------
//-------------------S1-------------------

#include <iostream>
using namespace std;

struct sNode
{
int data;
sNode *nNext;
sNode *nPrev;
};

class cDLL
{
sNode *head;
public:
cDLL();
void vCreateList();
void vMerge(cDLL, cDLL);
void vDisplayList();

};
void cDLL::vMerge(cDLL D1, cDLL D2)
{
sNode *curr = new sNode;
//head = new sNode;
	head = curr;
	curr->nNext= NULL;
	curr->nPrev = NULL;
	sNode *temp1 = D1.head->nNext, *temp2 = D2.head->nNext;
	while(temp1!=NULL && temp2!=NULL)
    {
        if(temp2->data>temp1->data)
        {
 	curr->nNext = new sNode;
	sNode *tempCur = curr;
            curr = curr->nNext;
            curr->data=temp1->data;
	    curr->nPrev = tempCur;
            curr->nNext = NULL;
	temp1 = temp1->nNext;
        }
        else
        {
	 curr->nNext = new sNode;
	sNode *tempCur = curr;
            curr = curr->nNext;
            curr->data=temp2->data;
	    curr->nPrev = tempCur;
            curr->nNext = NULL;
	temp2 = temp2->nNext;
        }
    }
    
    while(temp1!=NULL)
    {
      
curr->nNext = new sNode;
	sNode *tempCur = curr;
            curr = curr->nNext;
            curr->data=temp1->data;
	    curr->nPrev = tempCur;
            curr->nNext = NULL;
	 temp1 = temp1->nNext;
	
    }
    while(temp2!=NULL)
    {
curr->nNext = new sNode;
	sNode *tempCur = curr;
            curr = curr->nNext;
            curr->data=temp2->data;
	    curr->nPrev = tempCur;
            curr->nNext = NULL;
	 temp2 = temp2->nNext;
	
    }
}
void cDLL::vCreateList()
{
	char inp;
	int a;
	do{
		cout<<"Enter value:";
		cin>>a;
		if(head == NULL)
		{
			head = new sNode;
			sNode *temp = new sNode;
			head->nNext = temp;
			temp->nPrev = head;
			temp->data = a;
			temp->nNext = NULL;
		}
		else
		{
			sNode *curr = head;
			while(curr->nNext!= NULL)
				curr = curr->nNext;
			sNode *temp = new sNode;
			curr->nNext = temp;
			temp->nPrev = curr;
			temp->data = a;
			temp->nNext = NULL;
		}

		cout<<"Do you want to continue adding?(y)";
		cin>>inp;
	}while(inp=='y');
}

cDLL::cDLL()
{
	head = NULL;
}
void cDLL::vDisplayList()
{
	sNode *temp= head->nNext;
	while(temp!= NULL)
	{
		cout<<"---------------------\n";
		cout<<temp->data<<endl;
		temp = temp->nNext;
	}
}

int main()
{
	cDLL l1,l2,l3;
	cout<<"Enter first list:\n";
	l1.vCreateList();
	l1.vDisplayList();
	cout<<"Enter second list:\n";
	l2.vCreateList();
	l2.vDisplayList();
	l3.vMerge(l1,l2);
	cout<<"Merged list is\n";
	l3.vDisplayList();
	return 0;
}
//----------------OUTPUT----------------------
/*
Enter first list:
Enter value:-2
Do you want to continue adding?(y)y
Enter value:0
Do you want to continue adding?(y)y
Enter value:3
Do you want to continue adding?(y)n
---------------------
-2
---------------------
0
---------------------
3
Enter second list:
Enter value:-3
Do you want to continue adding?(y)y
Enter value:-1
Do you want to continue adding?(y)y
Enter value:1
Do you want to continue adding?(y)y
Enter value:5
Do you want to continue adding?(y)n
---------------------
-3
---------------------
-1
---------------------
1
---------------------
5
Merged list is
---------------------
-3
---------------------
-2
---------------------
-1
---------------------
0
---------------------
1
---------------------
3
---------------------
5
*/
