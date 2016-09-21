//------------------S1-----------------
//----------------Ashwin Vaidya--------
//-----------------202030--------------
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class CLL
{
private:
	Node *head;
public:
	CLL();
	~CLL();
	void vDisplayList();
	void vMergeList(CLL, CLL);
	void vInsertElement();
	void vDeleteNegNos();
	void vSortList();
	void vSplitList(CLL, CLL);


};
CLL::CLL()
{
	head = new Node;
	head->next=head;
}
CLL::~CLL()
{
	delete head;
}
void CLL::vInsertElement()
{
	Node *temp = new Node;

		Node *curr = head;
		while(curr->next!=head)
			curr= curr->next;
		curr->next = temp;
		temp->next = head;
		cout<<"Enter value:\n";
		cin>>temp->data;
}
void CLL::vMergeList(CLL l1, CLL l2)
{

	
	Node *curr = new Node;
	head = curr;
	curr->next= head;
	Node *temp1 = l1.head->next, *temp2 = l2.head->next;
	while(temp1!=l1.head && temp2!=l2.head)
    {
        if(temp2->data>temp1->data)
        {
 	curr->next = new Node;
            curr = curr->next;
            curr->data=temp1->data;
            temp1=temp1->next;
        }
        else
        {
	curr->next = new Node;
            curr = curr->next;
            curr->data=temp2->data;
            temp2=temp2->next;
        }
    }
    
    while(temp1!=l1.head)
    {
curr->next = new Node;
        curr= curr->next;
        curr->data=temp1->data;
        temp1 = temp1->next;
	
    }
    while(temp2!=l2.head)
    {
curr->next = new Node;
        curr= curr->next;
        curr->data=temp2->data;
        temp2 = temp2->next;
	
    }
	curr->next = head;
	

}

void CLL::vSortList()
{
	if(head->next==head)
		return;
	Node *temp;
	temp= head->next;
	bool flag = true;
	if(flag)
	{
		flag = false;
		temp = head->next;
		while(temp->next!= head)
		{
			if(temp->data >temp->next->data)
			{
				int tempdata = temp->next->data;
				temp->next->data = temp->data;
				temp->data = tempdata;
				flag = true;
			}
			temp = temp->next;
		}
	}
	cout<<"Sorted list is: \n";
	vDisplayList();

}
void CLL::vDisplayList()
{
cout<<"---------------------\n";
	if(head->next == head)
	{
		cout<<"Empty list\n";
		return ;
	}
	Node *curr = head->next;
	while(curr!= head){
		cout<<curr->data<<endl;
		curr = curr->next;
	}
cout<<"---------------------\n";
}
void CLL::vDeleteNegNos()
{
	Node *curr = head;
	Node *temp;
	while(curr->next!= head)
	{
		if(curr->next->data<0)
		{
			temp=curr->next;
			curr->next= curr->next->next;
			delete temp;
			continue;
		}
		curr = curr->next;
	}
	vDisplayList();
}

void CLL::vSplitList(CLL Cl1, CLL Cl2)
{
	Node *n1, *n2, *curr = head;
	n1 = Cl1.head; n2 = Cl2.head;
	while(curr->next!= head)
	{
		curr = curr->next;
		if(curr->data<0)
		{
			n2->next = new Node;
			n2->next->data = curr->data;
			n2 = n2->next;
		}
		else{
			n1->next = new Node;
			n1->next->data = curr->data;
			n1 = n1->next;
		}
	}
	n1->next = Cl1.head;
	n2->next = Cl2.head;
}

int main()
{
	CLL cL1,cPl, cNl,cRandomList1, cRandomList2, cResultant;
	char inp;
	int n;
	do{
		cout<<"1. Add element to list\n";
		cout<<"2. Display the list\n";
		cout<<"3. Delete negative numbers from list\n";
		cout<<"4. Split into -ve and +ve number's lists\n";
		cout<<"5. Sort and merge two lists\n";
		cin>>inp;
		switch(inp)
		{
		case '1':
			cL1.vInsertElement();
			break;
		case '2':

			cL1.vDisplayList();
			break;
		case '3':
			cL1.vDeleteNegNos();
			break;
		case '4':
			cL1.vSplitList(cPl, cNl);
			cout<<"Positive list is:\n";
			cPl.vDisplayList();
			cout<<"Negative list is:\n";
			cNl.vDisplayList();
			break;
		case '5':
			cout<<"Enter the number of elements in the first list: ";
			cin>>n;
			while(n--)
			{
				cRandomList1.vInsertElement();
			}
			cout<<"Enter the number of elements in the second list: ";
			cin>>n;
			while(n--)
			{
				cRandomList2.vInsertElement();
			}
			cRandomList1.vSortList();
			cRandomList2.vSortList();
			cResultant.vMergeList(cRandomList1, cRandomList2);
			cout<<"Merged list is:\n";
			cResultant.vDisplayList();
			break;
		}
		cout<<"Do you want to continue?(y)";
		cin>>inp;
	}while(inp=='y');
	return 0;
}
//------------OUTPUT--------------
/*
1. Add element to list
2. Display the list
3. Delete negative numbers from list
4. Split into -ve and +ve number's lists
5. Sort and merge two lists
2
---------------------
Empty list
Do you want to continue?(y)y
1. Add element to list
2. Display the list
3. Delete negative numbers from list
4. Split into -ve and +ve number's lists
5. Sort and merge two lists
1
Enter value:
3
Do you want to continue?(y)y
1. Add element to list
2. Display the list
3. Delete negative numbers from list
4. Split into -ve and +ve number's lists
5. Sort and merge two lists
1
Enter value:
-2
Do you want to continue?(y)y
1. Add element to list
2. Display the list
3. Delete negative numbers from list
4. Split into -ve and +ve number's lists
5. Sort and merge two lists
1
Enter value:
1
Do you want to continue?(y)y
1. Add element to list
2. Display the list
3. Delete negative numbers from list
4. Split into -ve and +ve number's lists
5. Sort and merge two lists
1
Enter value:
-5
Do you want to continue?(y)y
1. Add element to list
2. Display the list
3. Delete negative numbers from list
4. Split into -ve and +ve number's lists
5. Sort and merge two lists
2
---------------------
3
-2
1
-5
---------------------
Do you want to continue?(y)y
1. Add element to list
2. Display the list
3. Delete negative numbers from list
4. Split into -ve and +ve number's lists
5. Sort and merge two lists
3
---------------------
3
1
---------------------
Do you want to continue?(y)y
1. Add element to list
2. Display the list
3. Delete negative numbers from list
4. Split into -ve and +ve number's lists
5. Sort and merge two lists
1
Enter value:
-4
Do you want to continue?(y)y
1. Add element to list
2. Display the list
3. Delete negative numbers from list
4. Split into -ve and +ve number's lists
5. Sort and merge two lists
1
Enter value:
-7
Do you want to continue?(y)y
1. Add element to list
2. Display the list
3. Delete negative numbers from list
4. Split into -ve and +ve number's lists
5. Sort and merge two lists
2
---------------------
3
1
-4
-7
---------------------
Do you want to continue?(y)y
1. Add element to list
2. Display the list
3. Delete negative numbers from list
4. Split into -ve and +ve number's lists
5. Sort and merge two lists
4
Positive list is:
---------------------
3
1
---------------------
Negative list is:
---------------------
-4
-7
---------------------
Do you want to continue?(y)y
1. Add element to list
2. Display the list
3. Delete negative numbers from list
4. Split into -ve and +ve number's lists
5. Sort and merge two lists
5
Enter the number of elements in the first list: 3
Enter value:
1
Enter value:
-3
Enter value:
2
Enter the number of elements in the second list: 2
Enter value:
-4
Enter value:
5
Sorted list is: 
---------------------
-3
1
2
---------------------
Sorted list is: 
---------------------
-4
5
---------------------
Merged list is:
---------------------
-4
-3
1
2
5
---------------------
Do you want to continue?(y)n


/*
