/*
 * ADS_3.cpp
 *
 *  Created on: 06-Feb-2017
 *      Author: student
 */

#include<iostream>
using namespace std;
class tbtnode
{
	char data[10];
	int lbit;
	int rbit;
	tbtnode* left;
	tbtnode* right;
	friend class tbt;
public:
	tbtnode()
	{
		lbit=1;
		rbit=1;
	}

};
class tbt
{
	tbtnode* head;
public:
	tbt()
	{
		head=new tbtnode;
		head->rbit=0;
		head->left=head;
		head->right=head;
	}
	void create();
	void preorder();

	void inorder();
	tbtnode* insucc(tbtnode*);
};

void tbt::create()
{
	tbtnode *curr,*root,*temp;
	char ch;
	int ch1;
	root=new tbtnode;
	cout<<"\nEnter data for root:";
	cin>>root->data;
	head->lbit=0;
	root->left=head;
	root->right=head;
	head->left=root;

	do
	{
		int flag=0;
		temp=root;
		curr=new tbtnode;
		curr->left=head;
		curr->right=head;
		while(flag==0)
		{
			cout<<"\nWhere would you like to add the child node of  "<<temp->data;;
			cin>>ch;
			if(ch=='l')
			{
				if(temp->lbit==1)
				{
					cout<<"\nEnter data for new node:";
					cin>>curr->data;
					curr->right=temp;
					curr->left=temp->left;
					temp->left=curr;
					temp->lbit=0;
					flag=1;
				}
				else
				{
					temp=temp->left;
				}
			}
			else if(ch=='r')
			{
				if(temp->rbit==1)
				{
					cout<<"\nEnter data for new node:";
					cin>>curr->data;
					curr->left=temp;
					curr->right=temp->right;
					temp->right=curr;
					temp->rbit=0;
					flag=1;
				}
				else
					temp=temp->right;
			}
			else
				cout<<"\nINVALID CHOICE.";

		}
		cout<<"Enter 1 to continue adding nodes.";
		cin>>ch1;
	}while(ch1==1);
}
void tbt::inorder()
{
	tbtnode* temp;
	temp=head;
	while(1)
	{
		temp=insucc(temp);
		if(temp==head)
			break;
		cout<<"\t"<<temp->data;
	}
}
tbtnode* tbt::insucc(tbtnode* temp)
{
	tbtnode* x;
	x=temp->right;
	if(temp->rbit==0)
	{
		while(x->lbit==0)
			x=x->left;
	}
	return x;
}
void tbt::preorder()
{
	tbtnode* temp;
	temp=head->left;
	while(temp!=head)
	{
		cout<<"\t"<<temp->data;
		while(temp->lbit!=1)
		{
			temp=temp->left;
			cout<<"\t"<<temp->data;
		}
		while(temp->rbit==1)
			temp=temp->right;
		temp=temp->right;
	}
	cout<<"\n";
}
int main()
{
	tbt t1;
	t1.create();
	cout<<"Inorder traversal:";
	t1.inorder();
	cout<<"\nPreorder traversal:";
	t1.preorder();
	return 0;
}

/*OUTPUT:
 *
Enter data for root:1

Where would you like to add the child node of  1l

Enter data for new node:2
Enter 1 to continue adding nodes.1

Where would you like to add the child node of  1r

Enter data for new node:3
Enter 1 to continue adding nodes.1

Where would you like to add the child node of  1l

Where would you like to add the child node of  2l

Enter data for new node:4
Enter 1 to continue adding nodes.1

Where would you like to add the child node of  1r

Where would you like to add the child node of  3l

Enter data for new node:6
Enter 1 to continue adding nodes.1

Where would you like to add the child node of  1r

Where would you like to add the child node of  3r

Enter data for new node:7
Enter 1 to continue adding nodes.0
Inorder traversal:	4	2	1	6	3	7
Preorder traversal:	1	2	4	3	6	7
 */



