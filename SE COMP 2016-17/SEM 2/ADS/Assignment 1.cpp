//Ashwin Vidaya
//SE 202030
#include <iostream>
#include <string>
using namespace std;


class cTreeNode
{
private:
	cTreeNode *left, *right;
	string sData;
	friend class cTree;
};

class cStack
{
	cTreeNode *NodeList[10];
	int iTop;
	friend class cTree;
public:
	cStack();
	bool bIsEmpty();	//Returns true if stack is empty
	void vPush(cTreeNode*);
	cTreeNode *nPop();
};
bool cStack::bIsEmpty()
{
	if(iTop ==-1)
		return true;
	else return false;
}
void cStack::vPush(cTreeNode *Node)
{
	if(iTop >9)
		cout<<"Overflow!\n";
	else
	{
		iTop++;
		NodeList[iTop] = Node;
	}
}
cTreeNode* cStack::nPop()
{
	if(iTop ==-1)
	{
		cout<<"Underflow!\n";
		return NULL;
	}
	else
	{
		cTreeNode* temp = NodeList[iTop];
		iTop--;
		return temp;
	}
}
cStack::cStack()
{
	iTop = -1;
}

class cTree
{
	cStack cSt;
	cTreeNode *root;
public:
	void operator=(cTree );
	cTreeNode *nCopy(cTreeNode*);
	void vCreate_nr();
	void vCreate_r();
	void vCreate_r(cTreeNode *);
	void vInorder_r(cTreeNode *);
	void vInorder_r();
	void vInorder_nr();
	void vPreorder_r();
	void vPreorder_nr();
	void vPreorder_r(cTreeNode *);
	void vPostorder_r();
	void vPostorder_nr();
	void vPostorder_r(cTreeNode *);
	void vEraseTree();
	cTree();
	~cTree();
};
cTree::~cTree()
{
	vEraseTree();
}
void cTree::vEraseTree()
{
	cTreeNode *temp = root;
		if(root == NULL)
				cout<<"Tree is empty\n";
			else{
		while(1)
		{
			while(temp!=NULL)
				{
					cSt.vPush(temp);
					temp = temp->left;
				}
			if(cSt.NodeList[cSt.iTop]->right == NULL)
			{
				temp = cSt.nPop();
				delete temp;
			}
				while(!cSt.bIsEmpty() && cSt.NodeList[cSt.iTop]->right == temp)
			{
				temp = cSt.nPop();
				delete temp;
			}
			if(cSt.bIsEmpty())
				break;
			temp= cSt.NodeList[cSt.iTop]->right;
		}
		}
		cout<<"Tree Deleted\n";
		root = NULL;
}
void cTree::operator =(cTree t2)
{
	root = nCopy(t2.root);
}
cTreeNode *cTree::nCopy(cTreeNode *node)
{
	cTreeNode* temp = NULL;
	if(node!=NULL)
	{
		temp = new cTreeNode;
		temp->sData = node->sData;
		temp->left = nCopy(node->left);
		temp->right = nCopy(node->right);
	}
	return temp;
}
void cTree::vPreorder_nr()
{
	cTreeNode *temp = root;
	if(root == NULL)
			cout<<"Tree is empty\n";
		else{
	while(1)
	{
		while(temp!=NULL)
		{
			cout<<temp->sData <<' ';
			cSt.vPush(temp);
			temp = temp->left;
		}
		if(cSt.bIsEmpty())
			break;
		temp = cSt.nPop();
		temp= temp->right;
	}
		}
}
void cTree::vPostorder_nr()
{
	cTreeNode *temp = root;
	if(root == NULL)
			cout<<"Tree is empty\n";
		else{
	while(1)
	{
		while(temp!=NULL)
			{
				cSt.vPush(temp);
				temp = temp->left;
			}
		if(cSt.NodeList[cSt.iTop]->right == NULL)
		{
			temp = cSt.nPop();
			cout<<temp->sData <<' ';
		}
			while(!cSt.bIsEmpty() && cSt.NodeList[cSt.iTop]->right == temp)
		{
			temp = cSt.nPop();
			cout<<temp->sData <<' ';
		}
		if(cSt.bIsEmpty())
			break;
		temp= cSt.NodeList[cSt.iTop]->right;
	}
		}
}
void cTree::vInorder_nr()
{
	cTreeNode *temp = root;
	if(root == NULL)
		cout<<"Tree is empty\n";
	else{
	while(1)
	{
		while(temp!=NULL)
		{
			cSt.vPush(temp);
			temp = temp->left;
		}
		if(cSt.bIsEmpty())
			break;
		temp = cSt.nPop();
		cout<<temp->sData <<' ';
		temp= temp->right;
	}
	}
}
void cTree::vPostorder_r()
{
	cout<<"\nPostorder:\n";
	if(root==NULL)
			cout<<"Tree is empty\n";
	else
	vPostorder_r(root);
}
void cTree::vPostorder_r(cTreeNode *node)
{
	if(node!=NULL)
	{
		vPostorder_r(node->left);
		vPostorder_r(node->right);
		cout<<node->sData<<" ";
	}
}
void cTree::vPreorder_r()
{
	cout<<"\nPreorder:\n";
	if(root==NULL)
			cout<<"Tree is empty\n";
	else
	vPreorder_r(root);
}
void cTree::vPreorder_r(cTreeNode *node)
{
	if(node!=NULL)
	{
		cout<<node->sData<<" ";
		vPostorder_r(node->left);
		vPostorder_r(node->right);
	}
}
void cTree::vInorder_r()
{
	cout<<"\nInorder:\n";
	if(root==NULL)
		cout<<"Tree is empty\n";
	else
	vInorder_r(root);
}
void cTree::vInorder_r(cTreeNode *node)
{
	if(node!=NULL)
	{
		vInorder_r(node->left);
		cout<<node->sData<<" ";
		vInorder_r(node->right);
	}
}
cTree::cTree()
{
	root = NULL;
}
void cTree::vCreate_r()
{
	if(root==NULL){
	root = new cTreeNode;
	root->left = root->right = NULL;
	cout<<"Enter root data: ";
	cin>>root->sData;
	}
	vCreate_r(root);
}
void cTree::vCreate_r(cTreeNode *node)
{
	cTreeNode *curr;
	char ch;
	cout<<"l for left and r for right ";
	cin>>ch;
	if(ch=='r')
	{
		if(node->right!= NULL)
			vCreate_r(node->right);
		else{
		curr = new cTreeNode;
		node->right = curr;
		cout<<"Enter value of Node";
		cin>>curr->sData;
		}
	}
	else
	{
		if(node->left!= NULL)
					vCreate_r(node->left);
				else{
		curr = new cTreeNode;
		node->left = curr;
		cout<<"Enter value of Node";
		cin>>curr->sData;
				}
	}
}
void cTree::vCreate_nr()
{
	cTreeNode *temp, *curr;
	int flag;
	char ch;
	if(root==NULL)
	{
		root = new cTreeNode;
		root->left = root->right = NULL;
		cout<<"Enter the data for the root: ";
		cin>>root->sData;
	}
	else{
		do{
			temp = root;
			flag =0;
			curr = new cTreeNode;
			curr->left = curr->right = NULL;

			cout<<"Enter new string: ";
			cin>>curr->sData;
			while(!flag)
			{
			cout<<"l for left and r for right";
			cin>>ch;
			if(ch=='l')
			{
				if(temp->left == NULL)
				{
				temp->left = curr;
				flag = 1;
				}
				temp=temp->left;
			}

			if(ch=='r')
			{
				if(temp->right == NULL)
				{
				temp->right = curr;
				flag = 1;
				}
				temp= temp->right;
			}
			}

			cout<<"Do you want to continue adding nodes?(y) ";
			cin>>ch;
		}while(ch=='y');
	}
}

int main()
{
	cTree tTree,t2;
	char n='y';
	while(n=='y')
	{
		cout<<"0. Create tree using recursion\n";
		cout<<"1. Create tree using non-recursion\n";
		cout<<"2. Recursive Inorder\n";
		cout<<"3. Recursive Preorder\n";
		cout<<"4. Recursive Postorder\n";
		cout<<"5. Non-Recursive Inorder\n";
		cout<<"6. Non-Recursive Preorder\n";
		cout<<"7. Non-Recursive Postorder\n";
		cout<<"8. Copy current tree to another tree\n";
		cout<<"9. Delete tree\n";
		cin>>n;
		switch(n)
		{
		case '0':
			tTree.vCreate_r();
			break;
		case '1':
			tTree.vCreate_nr();
			break;
		case '2':
			tTree.vInorder_r();
			break;
		case '3':
			tTree.vPreorder_r();
			break;
		case '4':
			tTree.vPostorder_r();
			break;
		case '5':
			tTree.vInorder_nr();
			break;
		case '6':
			tTree.vPreorder_nr();
			break;
		case '7':
			tTree.vPostorder_nr();
			break;
		case '8':
			cout<<"Current tree using Inorder: ";
			tTree.vInorder_r();
			t2 = tTree;
			cout<<"\nCopied tree using Inorder: ";
			t2.vInorder_r();
			break;
		case '9':
			tTree.vEraseTree();
			break;
		default:
			break;
		}
		cout<<"\nDo you want to continue?(y)";
		cin>>n;
	}



	return 0;
}

