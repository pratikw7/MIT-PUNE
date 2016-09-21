#include <iostream>
#include <string.h>
using namespace std;

struct sNode
{
	char cJobName[20];
	sNode *nNext;
};

class cQueue
{
	sNode *nFront, *nRear;
public:
	cQueue();
	void vAdd();
	void vDelete();
	void vDispalyQ();
};

cQueue::cQueue()
{
	nFront = NULL;
	nRear =  NULL;
}
void cQueue::vAdd()
{
	cout<<"Enter name of job\n";
	char cJobName[20];
	cin>>cJobName;
	if(nRear==NULL && nFront==NULL)
	{
		sNode *temp= new sNode;
		strcpy(temp->cJobName, cJobName);
		temp->nNext = NULL;
		nRear = nFront  = temp;
	}
	else
	{
		sNode *temp= new sNode;
		strcpy(temp->cJobName, cJobName);
		temp->nNext = NULL;
		nRear->nNext = temp;
		nRear = nRear->nNext;
	}
}
void cQueue::vDelete()
{
	if(nRear==NULL && nFront==NULL)
	{
		cout<<"The queue is empty! UNDERFLOW !\n";
	}
	else if(nRear==nFront)
		{
			sNode *temp = nFront;
			nFront= nRear = NULL;
			delete temp;
		}
	else
	{
		sNode *temp = nFront;
		nFront = nFront->nNext;
		delete temp;
	}
}
void cQueue::vDispalyQ()
{
	sNode *curr = nFront;
	cout<<"-----------------------\n";
	while(curr!= NULL)
	{
		cout<<curr->cJobName<<endl;
		curr = curr->nNext;
	}
	cout<<"-----------------------\n";
}
int main()
{
	cQueue QJobs;
	char inp;
	do{
		cout<<"1. Add job\n";
		cout<<"2. Delete job\n";
		cout<<"3. Display queue\n";
		cin>>inp;
		switch(inp)
		{
		case '1':
			QJobs.vAdd();
			break;
		case '2':
			QJobs.vDelete();
			break;
		case '3':
			QJobs.vDispalyQ();
			break;
		}
		cout<<"Do you want to continue?(y)";
		cin>>inp;
	}while(inp =='y');
	return 0;
}
/*------------OUTPUT----------------------
1. Add job
2. Delete job
3. Display queue
1
Enter name of job
VLC
Do you want to continue?(y)y
1. Add job
2. Delete job
3. Display queue
1
Enter name of job
Chrome
Do you want to continue?(y)y
1. Add job
2. Delete job
3. Display queue
3
-----------------------
VLC
Chrome
-----------------------
Do you want to continue?(y)y
1. Add job
2. Delete job
3. Display queue
2
Do you want to continue?(y)y
1. Add job
2. Delete job
3. Display queue
3
-----------------------
Chrome
-----------------------
Do you want to continue?(y)n
 *
 */
