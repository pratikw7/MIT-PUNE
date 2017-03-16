//----Ashwin Vaidya---
//------SE202030------
//--------------------
#include <iostream>
using namespace std;

class cNode
{
	string sName;
	long int ph_number;
	cNode *next;
	friend class cHashTable;
public:
	cNode();
};
cNode::cNode()
{
	sName = " ";
	ph_number = -1;
}
class cHashTable
{
	cNode *Buckets[10];
public:
	cHashTable();
	int iCalculateKey(string);
	void vInsert();
	void vDisplay();
	bool bSearch();
	
};
bool cHashTable::bSearch()
{
	string name;
	int key;
	cout<<"Enter Name: ";
	cin>>name;
	key = iCalculateKey(name);
	cNode *curr = Buckets[key]->next;
	while(curr!=NULL)
	{
		if(name.compare(curr->sName)==0)
		{
			cout<<curr->sName<<endl<<curr->ph_number<<endl;
			return true;
		}
		curr=curr->next;
	}
	return false;
}
void cHashTable::vDisplay()
{
	cNode *curr;
	for (int i = 0; i < 10; ++i)
	{
		curr=Buckets[i]->next;
		cout<<"Bucket "<<i<<' ';
		while(curr!=NULL)
		{
			cout<<" : "<<curr->sName<<' '<<curr->ph_number;
			curr=curr->next;
		}
		cout<<endl;
	}
}
void cHashTable::vInsert()
{
	cNode *temp, *curr;
	int key;
	temp = new cNode;
	cout<<"Enter Name: ";
	cin>>temp->sName;
	cout<<"Enter Phone Number: ";
	cin>>temp->ph_number;
	key = iCalculateKey(temp->sName);
	curr = Buckets[key];
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next = temp;
	temp->next = NULL;
}
int cHashTable::iCalculateKey(string sName)
{
	int total=0;
	for (int i = 0; i < sName.length(); ++i)
	{
		total += (int)sName[i];
	}
	return total%10;
}
cHashTable::cHashTable()
{
	for(int i=0; i<10; i++)
	{
		Buckets[i]=new cNode;
		Buckets[i]->next=NULL;
	}
}
int main()
{
	cHashTable table;
	char inp;
	do{
		cout<<"1. Insert\n";
		cout<<"2. Display\n";
		cout<<"3. Search Phone Number\n";
		cin>>inp;
		switch(inp)
		{
			case '1':
			table.vInsert();
				break;
			case '2':
			table.vDisplay();
				break;
			case '3':
			if(!table.bSearch())
				cout<<"Record not found!";
				break;
		}
		cout<<"Enter y to continue: ";
		cin>>inp;
	}while(inp=='y');
	return 0;
}