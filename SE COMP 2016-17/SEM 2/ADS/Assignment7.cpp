#include <iostream>
using namespace std;

class cNode
{
	string sName;
	long int ph_number;
	cNode *next;
	friend class cSymbolTable;
public:
	cNode();
};
cNode::cNode()
{
	sName = " ";
	ph_number = -1;
}

class cSymbolTable
{
	cNode *Buckets[10];
	int iCalculateKey(string);
	public:
	cSymbolTable();
	int iHashfunction(string name);
	bool bSearch(string);
	cNode *nGetRecord(string name);
	void vDelete();
	void vInsert_REP();//with replacement
	void vInsert_WREP();//without replacement
	void vModify();
	void vDisplay();

};
int cSymbolTable::iCalculateKey(string sName)
{
	int total=0;
	for (int i = 0; i < sName.length(); ++i)
	{
		total += (int)sName[i];
	}
	return total%10;
}
void cSymbolTable::vDisplay()
{
	cout<<"-----------------------\n";
	cout<<"\tName\t Phone Number\n";
	for (int i = 0; i < 10; ++i)
	{
		cout<<"Bucket "<<i<<endl;
		cNode *curr = Buckets[i]->next;
		while(curr!= NULL)
		{
			cout<<curr->sName<<"\t"<<curr->ph_number<<endl;
			curr = curr->next;
		}
	}
}
void cSymbolTable::vModify()
{
	cout<<"Enter the name of person whose record you want to modify: ";
	string name;
	cin>>name;
	cNode *result = nGetRecord(name);
	if(result!=NULL)
	{
		cout<<"Enter new phone number: ";
		cin>>result->ph_number;
	}
	else
		cout<<"Record not found\n";
}
int cSymbolTable::iHashfunction(string sName)
{
	int total=0;
	for (int i = 0; i < sName.length(); ++i)
	{
		total += (int)sName[i];
	}
	return total%10;
}
bool cSymbolTable::bSearch(string name)
{
	int key;
	key = iCalculateKey(name);
	cNode *curr = Buckets[key]->next;
	while(curr!=NULL)
	{
		if(name.compare(curr->sName)==0)
		{
			cout<<"Record found!\n";
			cout<<"Name\tPhone Number\n";
			cout<<curr->sName<<"\t"<<curr->ph_number<<endl;
			return true;
		}
		curr=curr->next;
	}
	return false;
}
cNode *cSymbolTable::nGetRecord(string name)
{
	cNode *temp=NULL;
	int key;
	key = iCalculateKey(name);
	cNode *curr = Buckets[key]->next;
	while(curr!=NULL)
	{
		if(name.compare(curr->sName)==0)
		{
			temp = curr;
			
			return temp;
		}
		curr=curr->next;
	}
	return NULL;
}
void cSymbolTable::vDelete()
{
	int index;
	cNode *temp,*curr;
	cout<<"Enter name of person: ";
	string name;
	cin>>name;
	if(!bSearch(name))
	{
		cout<<"Record does not exist!";
		return;
	}
	index = iHashfunction(name);
	curr = Buckets[index];
	while(curr->next->sName.compare(name)!=0)
	{
		curr = curr->next;
	}
	temp = curr->next;
	curr->next = curr->next->next;
	delete temp;
	cout<<"Record deleted!\n";
}
void cSymbolTable::vInsert_REP()
{
	int index;
	cNode *temp,*curr;
	cout<<"Enter name: ";
	string name;
	cin>>name;
	cout<<"Enter ph_number: ";
	temp = new cNode;
	temp->sName = name;
	cin>>temp->ph_number;
	index = iHashfunction(name);
	curr = Buckets[index];
	if(curr->next!=NULL)
     {
    	 temp->next=curr->next;
    	 curr->next = temp;
     }
     else
     {
     	curr->next = temp;
     	temp->next = NULL;
     }
}
void cSymbolTable::vInsert_WREP()
{
	int index;
	cNode *temp,*curr;
	cout<<"Enter name: ";
	string name;
	cin>>name;
	temp = new cNode;
	temp->sName = name;
	cout<<"Enter phone number: ";
	cin>>temp->ph_number;
	index = iHashfunction(name);
	curr = Buckets[index];
	while(curr->next!=NULL)
	{
		curr = curr->next;
	}
	curr->next = temp;
	temp->next = NULL;
}

cSymbolTable::cSymbolTable()
{
   for(int i=0; i<10; i++)
   {
   	Buckets[i] = new cNode;
   	Buckets[i]->next = NULL;
   }
}
 int main()
 {
 	cSymbolTable STdirectory;
 	char n;
 	string name;	
 	do{
 	cout<<"1. Search record\n";
 	cout<<"2. Modify record\n";
 	cout<<"3. Delete record\n";
 	cout<<"4. Insert w/ replacement\n";
 	cout<<"5. Insert without replacement\n";
 	cout<<"6. Display\n";
 	cin>>n;
 	switch(n)
 	{
 		case '1':
 			cout<<"Enter the name you want to search: ";
 			cin>>name;
 			if(!STdirectory.bSearch(name))
 			{
 				cout<<"Record does not exist!\n";
 			}
 			break;
 		case '2':
 		 	STdirectory.vModify();
 			break;
 		case '3':
 		STdirectory.vDelete();
 			break;
  		case '4':
  		STdirectory.vInsert_REP();
 			break;
 		case '5':
 			STdirectory.vInsert_WREP();
 			break;
 		case '6':
 			STdirectory.vDisplay();
 			break;
 	}
 	cout<<"Do you want to contnue(y)? ";
 	cin>>n;
 	}while(n=='y');
    return 0;
 }
