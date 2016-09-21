//-----------------Ashwin Vaidya-----------------
//------------------202030-----------------------
//--------------------SE1------------------------

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

struct sNode
{
	char cName[40];
	int iPRN;
	char cRole[40];
	sNode *next;
};

class SLL
{
sNode *head;
public:
	SLL();
	//~SLL();
	void vInsert();
	void vDelete();
	void vDisplay();
	void vRevDisplay(){vRevDisplay(head);}
	void vRevDisplay(sNode *);
	void vConcat(SLL);
	int vCount();
};

SLL::SLL()
{
	head=NULL;
	//last=head;
}

void SLL::vConcat(SLL S2)
{
	if(S2.head!= NULL){
	sNode *curr, *temp = head->next;
	head->next = S2.head;
	curr = S2.head;
	if(strcmp(S2.head->cRole, "President")==0)
		strcpy(S2.head->cRole,"Vice President");
	while(curr->next!=NULL)
		{
			curr = curr->next;
		}
		if(strcmp(curr->cRole, "Secretary")==0)
			strcpy(curr->cRole,"Vice Secretary");
			curr->next = temp;
	}
	
}

int SLL::vCount()
{
	int count=0;
	sNode *curr= head;
	while(curr!=NULL)
		{
			count++;
			curr= curr->next;
		}
	return count;
}

void SLL::vDisplay()
{
	cout<<"-----------------------------\n";
	sNode *curr= head;
	if(head==NULL){
		cout<<"Empty List!\n";
	return;
	}
	while(curr!=NULL)
	{
	cout<<"Address of current node: "<<curr<<endl;
	cout<<"Address of next node: "<<(curr->next)<<endl;
	cout<<"Name: "<<curr->cName<<endl;
	cout<<"PRN: "<<curr->iPRN<<endl;
	cout<<"Role: "<<curr->cRole<<endl;
	curr = curr->next;
	cout<<"----------------------------\n";
	}
}

void SLL::vRevDisplay(sNode *n)
{
	if(n->next!= NULL)
		vRevDisplay(n->next);
	cout<<"----------------------------\n";
	cout<<"Address of current node: "<<&n<<endl;
	cout<<"Address of next node: "<<&(n->next)<<endl;
	cout<<"Name: "<<n->cName<<endl;
	cout<<"PRN: "<<n->iPRN<<endl;
	cout<<"Role: "<<n->cRole<<endl;
	cout<<"----------------------------\n";
}

void SLL::vDelete()
{
	if(head==NULL)
		{
			cout<<"Underflow!\n";
			return;
		}
	char cN[40];
	int iP;
	cout<<"Enter details of member you want to remove\n";
	cout<<"Enter name of Member: ";
	cin.ignore();
	gets(cN);
	cout<<"Enter PRN of member: ";
	cin>>iP;
	sNode *prev,*temp,*curr = head;
	
	if(strcmp(cN,head->cName)==0 &&iP==head->iPRN)
			{
				temp = head;
				head = NULL;
				delete temp;
				cout<<"Record deleted!\n";
				return;
			}	
	while(curr!=NULL)
	{

		if(strcmp(cN,curr->cName)==0 &&iP==curr->iPRN)
		{
			temp= curr;
			prev->next = curr->next;
			delete temp;
			cout<<"Record deleted!\n";
			return;
		}
		prev = curr;
		curr=curr->next;
	}
	cout<<"Record not found!\n";
}

void SLL::vInsert()
{
	sNode *temp = new sNode;
	sNode *last = NULL;	
	if(head!=NULL)
	{	
	last = head;
	while(last->next!=NULL)
		last=last->next;
	}
	cout<<"Enter name: ";
	cin.ignore();
	gets(temp->cName);
	cout<<"Enter PRN: ";
	cin>>temp->iPRN;
	cout<<"Enter his/her role: ";
	cin>>(temp->cRole);
	temp->next=NULL;

	if(head==NULL)
		{
		head = temp;
		head->next = last;
		last = head;
		}
	else if(strcmp(temp->cRole, "President") == 0)
		{
			if(strcmp(head->cRole,"President")==0)
				{
				cout<<"President already exists!\n";
				delete temp;
				}
			else
				{
					temp->next = head;
					head = temp;
				}
		}
	else if(strcmp(temp->cRole, "Secretary")==0)
		{
			if(strcmp(last->cRole,"Secretary" )==0)
				{
				cout<<"Secretary already exists!\n";
				delete temp;
				}
			else
				{
					temp->next = NULL;
					last->next = temp;
					last = temp;
				}
		}
	else
	{
		if(last==head)
		{
			head->next = temp;
			temp->next = NULL;
			last=temp;
		}
		else{
		temp->next = head->next;
		head->next = temp;
		}
	}
}

int main()
{
	SLL club,S2;
	int no;
	char n;
	do
	{
	cout<<"1. Add Member\n";
	cout<<"2. Remove Member\n";
	cout<<"3. Display List\n";
	cout<<"4. Number of records\n";
	cout<<"5. Display the list in reverse\n";
	cout<<"6. Concatenate two list\n";
	cin>>n;
	switch(n)
	   {
		case '1':
			club.vInsert();
			break;
		case '2':
			club.vDelete();
			break;
		case '3':
			club.vDisplay();
			break;
		case '4':
			cout<<"Number of members in the club: "<<club.vCount()<<endl;
			break;
		case '5':
			cout<<"List is reverse: \n";
			club.vRevDisplay();
			break;
		case '6':
			cout<<"Enter number of members in another list: \n";
			cin>>no;
			while(no--)
			{
			S2.vInsert();
			}
			cout<<"Members of first club are:\n";
			club.vDisplay();
			cout<<"Members of second club are:\n";
			S2.vDisplay();
			cout<<"Concatenated result\n";
			club.vConcat(S2);
			club.vDisplay();
			break;
	   }
	cout<<"Do you want to continue? (y)";
	cin>>n;
	}while(n=='y');
	return 0;
}
//-----------Output----------------------------
1. Add Member
2. Remove Member
3. Display List
4. Number of records
5. Display the list in reverse
6. Concatenate two list
1
Enter name: sdf 
Enter PRN: 1243
Enter his/her role: asfd
Do you want to continue? (y)y
1. Add Member
2. Remove Member
3. Display List
4. Number of records
5. Display the list in reverse
6. Concatenate two list
1
Enter name: Ashwin
Enter PRN: 12
Enter his/her role: President
Do you want to continue? (y)y
1. Add Member
2. Remove Member
3. Display List
4. Number of records
5. Display the list in reverse
6. Concatenate two list
1
Enter name: ds
Enter PRN: 345
Enter his/her role: Secretary
Do you want to continue? (y)y
1. Add Member
2. Remove Member
3. Display List
4. Number of records
5. Display the list in reverse
6. Concatenate two list
2
Enter details of member you want to remove
Enter name of Member: ds
Enter PRN of member: 345
Record deleted!
Do you want to continue? (y)y
1. Add Member
2. Remove Member
3. Display List
4. Number of records
5. Display the list in reverse
6. Concatenate two list
3
-----------------------------
Address of current node: 0x1476080
Address of next node: 0x1476010
Name: Ashwin
PRN: 12
Role: President
----------------------------
Address of current node: 0x1476010
Address of next node: 0
Name: sdf
PRN: 1243
Role: asfd
----------------------------
Do you want to continue? (y)y
1. Add Member
2. Remove Member
3. Display List
4. Number of records
5. Display the list in reverse
6. Concatenate two list
1
Enter name: dsfg
Enter PRN: 23
Enter his/her role: dsfg
Do you want to continue? (y)y
1. Add Member
2. Remove Member
3. Display List
4. Number of records
5. Display the list in reverse
6. Concatenate two list
1
Enter name: sdfg
Enter PRN: 234
Enter his/her role: Secretary
Do you want to continue? (y)y
1. Add Member
2. Remove Member
3. Display List
4. Number of records
5. Display the list in reverse
6. Concatenate two list
3
-----------------------------
Address of current node: 0x1476080
Address of next node: 0x14760f0
Name: Ashwin
PRN: 12
Role: President
----------------------------
Address of current node: 0x14760f0
Address of next node: 0x1476010
Name: dsfg
PRN: 23
Role: dsfg
----------------------------
Address of current node: 0x1476010
Address of next node: 0x1476160
Name: sdf
PRN: 1243
Role: asfd
----------------------------
Address of current node: 0x1476160
Address of next node: 0
Name: sdfg
PRN: 234
Role: Secretary
----------------------------
Do you want to continue? (y)y
1. Add Member
2. Remove Member
3. Display List
4. Number of records
5. Display the list in reverse
6. Concatenate two list
4
Number of members in the club: 4
Do you want to continue? (y)y
1. Add Member
2. Remove Member
3. Display List
4. Number of records
5. Display the list in reverse
6. Concatenate two list
5
List is reverse: 
----------------------------
Address of current node: 0x7fffa2cc4590
Address of next node: 0x14761b8
Name: sdfg
PRN: 234
Role: Secretary
----------------------------
----------------------------
Address of current node: 0x7fffa2cc45c0
Address of next node: 0x1476068
Name: sdf
PRN: 1243
Role: asfd
----------------------------
----------------------------
Address of current node: 0x7fffa2cc45f0
Address of next node: 0x1476148
Name: dsfg
PRN: 23
Role: dsfg
----------------------------
----------------------------
Address of current node: 0x7fffa2cc4620
Address of next node: 0x14760d8
Name: Ashwin
PRN: 12
Role: President
----------------------------
Do you want to continue? (y)y
1. Add Member
2. Remove Member
3. Display List
4. Number of records
5. Display the list in reverse
6. Concatenate two list
6
Enter number of members in another list: 
3
Enter name: asfed
Enter PRN: 23
Enter his/her role: Secretary
Enter name: sdfg
Enter PRN: 23
Enter his/her role: President
Enter name: dsfg
Enter PRN: 432
Enter his/her role: sdfg
Members of first club are:
-----------------------------
Address of current node: 0x1476080
Address of next node: 0x14760f0
Name: Ashwin
PRN: 12
Role: President
----------------------------
Address of current node: 0x14760f0
Address of next node: 0x1476010
Name: dsfg
PRN: 23
Role: dsfg
----------------------------
Address of current node: 0x1476010
Address of next node: 0x1476160
Name: sdf
PRN: 1243
Role: asfd
----------------------------
Address of current node: 0x1476160
Address of next node: 0
Name: sdfg
PRN: 234
Role: Secretary
----------------------------
Members of second club are:
-----------------------------
Address of current node: 0x1476240
Address of next node: 0x14762b0
Name: sdfg
PRN: 23
Role: President
----------------------------
Address of current node: 0x14762b0
Address of next node: 0x14761d0
Name: dsfg
PRN: 432
Role: sdfg
----------------------------
Address of current node: 0x14761d0
Address of next node: 0
Name: asfed
PRN: 23
Role: Secretary
----------------------------
Concatenated result
-----------------------------
Address of current node: 0x1476080
Address of next node: 0x1476240
Name: Ashwin
PRN: 12
Role: President
----------------------------
Address of current node: 0x1476240
Address of next node: 0x14762b0
Name: sdfg
PRN: 23
Role: Vice President
----------------------------
Address of current node: 0x14762b0
Address of next node: 0x14761d0
Name: dsfg
PRN: 432
Role: sdfg
----------------------------
Address of current node: 0x14761d0
Address of next node: 0x14760f0
Name: asfed
PRN: 23
Role: Vice Secretary
----------------------------
Address of current node: 0x14760f0
Address of next node: 0x1476010
Name: dsfg
PRN: 23
Role: dsfg
----------------------------
Address of current node: 0x1476010
Address of next node: 0x1476160
Name: sdf
PRN: 1243
Role: asfd
----------------------------
Address of current node: 0x1476160
Address of next node: 0
Name: sdfg
PRN: 234
Role: Secretary
----------------------------
Do you want to continue? (y)
