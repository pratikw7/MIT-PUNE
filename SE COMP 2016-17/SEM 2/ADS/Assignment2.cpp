#include <iostream>
using namespace std;

class vTreeNode
{
    string sData;
    vTreeNode *left,*right;
    friend class cBST;
public:
    vTreeNode();
};

class cQueue
{
	int front,rear;
	vTreeNode *nQueue[10];
public:
	cQueue();
	void vInsert(vTreeNode*);
	vTreeNode *nPop();
};

cQueue::cQueue()
{
	front = rear = -1;
}

void cQueue::vInsert(vTreeNode *node)
{
	if(front == -1 && rear == -1)
	{
		front =0; rear = 0;
		nQueue[rear] = node;
		rear++;
	}
	else if(front == rear)
	{
		cout<<"Queue full!\n";
	}
	else
	{
		nQueue[rear] = node;
		rear++;
	}
}

vTreeNode *cQueue::nPop()
{
	vTreeNode *temp = nQueue[front];
	front++;
	return temp;
}

vTreeNode::vTreeNode()
{
	sData = ' ';
	left = right = NULL;
}

class cBST
{
    vTreeNode *root;
    cQueue qQueue;
public:
    void vInsert_nr();
    void vDepth();
    void vMinimumData();
    void vSearch(string);
    void vDisplayBFS();
    cBST();
};
cBST::cBST()
{
 root = NULL;
}
void cBST::vDisplayBFS()
{
	if(root == NULL)
		cout<<"The tree is empty\n";
	else
	{
		cout<<"The tree is:\n";
		while(true)
		{
			qQueue.vInsert(root);

		}
	}
}


void cBST::vInsert_nr()
{
	if(root == NULL)
	{
		cout<<"Enter root data: ";
		root = new vTreeNode;
		cin>>root->sData;
	}
	else
	{
		vTreeNode *temp = new vTreeNode;
		cout<<"Enter node data: ";
		cin>>temp->sData;
		vTreeNode *curr  = root;
		while(1)
		{
			if(temp !=NULL)
			{
				if(temp->sData.compare(curr->sData)<0)
					curr = curr->right;
				else
					curr = curr->left;
			}
			else{

			}
			{
				curr = temp;
				break;
			}
		}
	}
}

int main()
{
	cBST tTree;
	int inp;
	char n;
	do{
		cout<<"1. Insert new node\n";
		cout<<"2. Tree Depth\n";
		cout<<"3. Print Minimum Data\n";
		cout<<"4. Mirror tree\n";
		cout<<"5. Search element\n";
		cout<<"6. Display BFS\n";
		cin>>inp;
		switch(inp)
		{
		case 1:
			tTree.vInsert_nr();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		}
		cout<<"Do you want to continue?(y)";
		cin>>n;
	}while(n=='y');

    return 0;
}

