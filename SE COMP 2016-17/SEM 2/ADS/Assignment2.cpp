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
class cStack
{
	vTreeNode *curr[10];
	int top;
	friend class cBST;
public:
	cStack();
	void vPush(vTreeNode *);
	vTreeNode* nPop();
	bool bEmpty();
};
cStack::cStack()
{
	top=-1;
}

void cStack::vPush(vTreeNode *node)
{
	top++;
	curr[top]=node;
}

vTreeNode* cStack::nPop()
{
	top--;
	return curr[top+1];
}

bool cStack::bEmpty()
{
	if(top==-1)
		return true;
	else
		return false;
}

class cQueue
{
	int front,rear;
	vTreeNode *nQueue[20];
public:
	cQueue();
	void vInsert(vTreeNode*);
	bool bEmpty();
	vTreeNode *nPop();
};
bool cQueue::bEmpty()
	{
		if(rear==front)
			return true;
		return false;
	}
cQueue::cQueue()
{
	front = rear = -1;
}

void cQueue::vInsert(vTreeNode *node)
{
	rear=rear+1;
	nQueue[rear]=node;
}

vTreeNode *cQueue::nPop()
{
	vTreeNode *temp=NULL;
  if(rear==front)
    cout<<"Queue is empty";
    else{
      front++;
      temp = nQueue[front];
    }
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
    void vSearch_rec();
    vTreeNode* vSearch_rec(vTreeNode*,string,int&);
    void vDisplayBFS();
    void vSwap();
    void vSwap(vTreeNode*);
    void vMirror();
    cBST();
};
void cBST::vMirror()
{
	vTreeNode *temp,*curr;
		cQueue q;
		temp=root;
		q.vInsert(temp);
		while(!q.bEmpty())
		{
			temp=q.nPop();
			curr=temp->left;
			temp->left=temp->right;
			temp->right=curr;
			if(temp->left!=NULL)
				q.vInsert(temp->left);
			if(temp->right!=NULL)
				q.vInsert(temp->right);
		}
}
void cBST::vSearch_rec()
{
		int ht=1;
		vTreeNode *temp;
		string Query;
		cout<<"\nEnter the string to be searched : ";
		cin>>Query;
		temp=vSearch_rec(root,Query,ht);
		if(temp!=NULL)
			cout<<"\nData found at level "<<ht-1<<endl;
		else
			cout<<"\nNot found";
}
vTreeNode* cBST::vSearch_rec(vTreeNode *temp,string Query,int &ht)
{
	if(temp==NULL)
	return NULL;
	if(temp->sData.compare(Query)==0)
	return temp;
	if(temp->sData.compare(Query)>0)
	{
		ht++;
		return(vSearch_rec(temp->left,Query,ht));
	}
	else
	{
		ht++;
		return(vSearch_rec(temp->right,Query,ht));
	}
}
void cBST::vSearch(string Query)
{
		vTreeNode *temp;
		temp=root;
		int h=0,flag=0;
		while(1)
		{
			while(temp!=NULL)
			{
				if(temp->sData.compare(Query)==0)
				{
					flag=1;
					break;
				}
			  if(temp->sData.compare(Query)>0)
        {
          h++;
            temp = temp->left;
        }
        else
          {
          h++;
          temp = temp->right;
          }
			  }
        break;
		}
		if(flag==0)
		{
			cout<<"Element does not exit\n";
		}else
		{
			cout<<"Element found at level: "<<h<<endl;
		}
}
void cBST::vSwap()
{
	vSwap(root);
}
void cBST::vSwap(vTreeNode* r)
	{
		vTreeNode* temp;
		if(r->left!=NULL&&r->right!=NULL)
		{
			temp=r->left;
			r->left=r->right;
			r->right=temp;
			vSwap(r->left);
			vSwap(r->right);
		}else if(r->left==NULL&&r->right!=NULL)
		{
			r->left=r->right;
			r->right=NULL;
			vSwap(r->left);
		}else if(r->right==NULL&&r->left!=NULL)
		{
			r->right=r->left;
			r->left=NULL;
			vSwap(r->right);
		}
	}
void cBST::vMinimumData()
{
	vTreeNode *temp;
	cStack st;
	temp=root;
	while(temp->left!=NULL)
		{
			st.vPush(temp);
			temp=temp->left;
		}
		cout<<"Minimum data is:\t"<<temp->sData<<endl;
}
void cBST::vDepth()
{
	vTreeNode *temp;
		cStack st;
		temp=root;
		int d=0;
		while(1)
		{
			while(temp!=NULL)
			{
				st.vPush(temp);
				temp=temp->left;
				if(d<st.top)
					d=st.top;
			}
			if(st.curr[st.top]->right==NULL)
			{
				temp=st.nPop();
			}
			while(st.top!=-1&&st.curr[st.top]->right==temp)
			{
				temp=st.nPop();
			}
			if(st.bEmpty())
				break;
			temp=st.curr[st.top]->right;
		}
		cout<<"Max length"<<d+1<<endl;
}

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
		int p=1,r=0;
		vTreeNode *temp;
		cQueue q;
		temp=root;
		q.vInsert(temp);
		while(!q.bEmpty())
		{
			for(int i=0;i<p;i++)
			{
				temp=q.nPop();
				cout<<temp->sData<<" ";
				if(temp->left!=NULL)
				{
					q.vInsert(temp->left);
					r++;
				}
				if(temp->right!=NULL)
				{
					q.vInsert(temp->right);
					r++;
				}
			}
			cout<<"\n";
			p=r;
			r=0;
		}
	}
}


void cBST::vInsert_nr()
{
  vTreeNode *curr,*temp;
	if(root == NULL)
	{
		cout<<"Enter root data: ";
		root = new vTreeNode;
		cin>>root->sData;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
    temp = root;
		 curr = new vTreeNode;
		cout<<"Enter node data: ";
		cin>>curr->sData;
		curr->left = NULL;
		curr->right = NULL;
		int flag =0;
		while(flag==0)
				{
					if(curr->sData.compare(temp->sData)<0)
					{
						if(temp->left==NULL)
						{
							temp->left=curr;
							flag=1;
						}else
							temp=temp->left;
					}
					else
					{
						if(temp->right==NULL)
						{
							temp->right=curr;
							flag=1;
						}else
							temp=temp->right;
					}
				}
	}
}

int main()
{
	cBST tTree;
	int inp;
	char n;
	string Query;
	do{
		cout<<"1. Insert new node\n";
		cout<<"2. Tree Depth\n";
		cout<<"3. Print Minimum Data\n";
		cout<<"4. Mirror tree recursive\n";
		cout<<"5. Mirror tree non-recursive\n";
		cout<<"6. Search element recursive\n";
		cout<<"7. Search element non-recursive\n";
		cout<<"8. Display BFS\n";
		cin>>inp;
		switch(inp)
		{
		case 1:
			tTree.vInsert_nr();
			break;
		case 2:
			tTree.vDepth();
			break;
		case 3:
			tTree.vMinimumData();
			break;
		case 4:
			cout<<"\nOriginal tree : \n";
			tTree.vDisplayBFS();
			tTree.vSwap();
			cout<<"\nMirror Image : \n";
			tTree.vDisplayBFS();
			break;
		case 5:
			cout<<"\nOriginal tree : \n";
			tTree.vDisplayBFS();
			tTree.vMirror();
			cout<<"\nMirror Image : \n";
			tTree.vDisplayBFS();
			break;
		case 7:
			cout<<"Enter query you want to search: ";
			cin>>Query;
			tTree.vSearch(Query);
			break;
		case 6:
			tTree.vSearch_rec();
			break;
		case 8:
			tTree.vDisplayBFS();
		}
		cout<<"Do you want to continue?(y)";
		cin>>n;
	}while(n=='y');

    return 0;
}
/*
1. Insert new node
2. Tree Depth
3. Print Minimum Data
4. Mirror tree recursive
5. Mirror tree non-recursive
6. Search element recursive
7. Search element non-recursive
8. Display BFS
2
Max length6
Do you want to continue?(y)y
1. Insert new node
2. Tree Depth
3. Print Minimum Data
4. Mirror tree recursive
5. Mirror tree non-recursive
6. Search element recursive
7. Search element non-recursive
8. Display BFS
3
Minimum data is:	25
Do you want to continue?(y)y
1. Insert new node
2. Tree Depth
3. Print Minimum Data
4. Mirror tree recursive
5. Mirror tree non-recursive
6. Search element recursive
7. Search element non-recursive
8. Display BFS
4

Original tree :
The tree is:
40
30 60
25 35 52 65
32 43 55
41 45 53 57
56 58

Mirror Image :
The tree is:
40
60 30
65 52 35 25
55 43 32
57 53 45 41
58 56
Do you want to continue?(y)y
1. Insert new node
2. Tree Depth
3. Print Minimum Data
4. Mirror tree recursive
5. Mirror tree non-recursive
6. Search element recursive
7. Search element non-recursive
8. Display BFS
5

Original tree :
The tree is:
40
60 30
65 52 35 25
55 43 32
57 53 45 41
58 56

Mirror Image :
The tree is:
40
30 60
25 35 52 65
32 43 55
41 45 53 57
56 58
Do you want to continue?(y)y
1. Insert new node
2. Tree Depth
3. Print Minimum Data
4. Mirror tree recursive
5. Mirror tree non-recursive
6. Search element recursive
7. Search element non-recursive
8. Display BFS
6

Enter the string to be searched : 32

Data found at level 3
Do you want to continue?(y)y
1. Insert new node
2. Tree Depth
3. Print Minimum Data
4. Mirror tree recursive
5. Mirror tree non-recursive
6. Search element recursive
7. Search element non-recursive
8. Display BFS
7
Enter query you want to search: 32
Element found at level: 3
Do you want to continue?(y)y
1. Insert new node
2. Tree Depth
3. Print Minimum Data
4. Mirror tree recursive
5. Mirror tree non-recursive
6. Search element recursive
7. Search element non-recursive
8. Display BFS
8
The tree is:
40
30 60
25 35 52 65
32 43 55
41 45 53 57
56 58
Do you want to continue?(y)n
*/
