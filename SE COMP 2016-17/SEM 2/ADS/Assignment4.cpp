//------------ASHWIN VAIDYA-----------
//---------------202030---------------
//++++++++++++++++++++++++++++++++++++
#include <iostream>
using namespace std;
class cQueue
{
    int iData[20];
    int rear, front;
public:
    cQueue();
    bool bIsEmpty();
    void vInsert(int);
    int iRemove();
};
cQueue::cQueue()
{
    rear=-1;
    front=-1;
}
bool cQueue::bIsEmpty()
{
    if(rear==front)
        return true;
    return false;
}
void cQueue::vInsert(int temp)
{
    rear++;
    iData[rear]=temp;
}
int cQueue::iRemove()
{
    int temp;
    if(rear==front)
        cout<<"\nQueue is empty";
    else
    {
        front=front+1;
        temp=iData[front];
    }
    return temp;
}
class cStack
{
    int iStack[20];
    int top;
public:
    cStack();
    void vPush(int);
    int iPop();
    bool bIsEmpty();
    bool bIsFull();
    int iTop();
};
class Node
{
private:
    Node *next;
    char cCityName;
    float fDistance;
public:
    Node();
    friend class ListGraph;
};
cStack::cStack()
{
    top=-1;
}
int cStack::iTop()
{
    return iStack[top];
}
bool cStack::bIsFull()
{
    if(top==19)
        return true;
    return false;
}
bool cStack::bIsEmpty()
{
    if(top==-1)
        return true;
    return false;
}
void cStack::vPush(int temp)
{
    
    if(bIsFull())
        cout<<"\nStack is full";
    else
    {
        top=top+1;
        iStack[top]=temp;
    }
}
int cStack::iPop()
{
    int temp =-1;
    if(bIsEmpty())
        cout<<"\nStack is empty";
    else
    {
        temp=iStack[top];
        top--;
    }
    return temp;
}
Node::Node()
{
    next = NULL;
    fDistance = 0;
}

class MatGraph
{
    private:
        int iGraph[10][10];//maximum 10 cities
        int m;
    public:
        MatGraph();
        void vGetMatrix();
        void vDisplayGraph();
};
void MatGraph::vDisplayGraph()
{
    if(m==-1)
        return;
    cout<<"Flight details of AI143:\n";
    for(int i=0; i<m; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<iGraph[i][j]<<'\t';
            }
            cout<<endl;
        }
}
MatGraph::MatGraph()
{
    m=-1;
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            iGraph[i][j]=0;//Flight does not travel between the cities
}

void MatGraph::vGetMatrix()
{
    cout<<"Enter flight details of AI143:\n";
    char inp;
    cout<<"Enter number of cities:\n";
    cin>>m;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<"Is there a route between cities "<<(char)(i+97)<<" and "<<(char)(j+97)<<" y/n: ";
            cin>>inp;
            if(inp=='y')
            {
                if(i==j)
                {
                    cout<<"Flight cannot take-off and land in the same city!\n";
                    continue;
                }
                cout<<"Enter distance between the cities: ";
                cin>>iGraph[i][j];
            }
        }
    }
}

class ListGraph
{
private:
    int noOfCities;
    Node *iArrList[10];//Maximum 10 cities
    int iVisited[10];
public:
    ListGraph();
    void vGetList();
    void vDisplayList();
    void vDFS_NonRec(char );
    void vDFS_Rec();
    void vDFS_Rec(int,int[]);
    void vBFS();
};
void ListGraph::vBFS()
{
    cQueue queue;
    Node *temp;
    for (int i = 0; i < noOfCities; ++i)
    {
        iVisited[i]=0;
    }
    cout<<"\nEnter starting vertex: ";
    char c;
    cin>>c;
    iVisited[(int)c-97]=1;
    queue.vInsert((int)c-97);
    cout<<' '<<c;
    while(!queue.bIsEmpty())
    {
        int m=queue.iRemove();
        temp=iArrList[m];
        while(temp!=NULL)
        {
            if(!iVisited[(int)temp->cCityName-97])
            {
                iVisited[(int)temp->cCityName-97]=1;
                cout<<' '<<temp->cCityName;
                queue.vInsert((int)temp->cCityName-97);
            }
            temp=temp->next;
        }
    }
}
void ListGraph::vDFS_Rec()
{
    char vertex;
    for (int i = 0; i < noOfCities; i++)
    {
        iVisited[i]=0;
    }
    cout<<"\nEnter starting vertex: ";
    cin>>vertex;
    vDFS_Rec((int)vertex-97,iVisited);
}
void ListGraph::vDFS_Rec(int vertex, int iVisited[])
{
    Node *temp;
    iVisited[vertex]=1;
    cout<<' '<<(char)(vertex+97);
    temp = iArrList[vertex];
    for (int i = 0; i < noOfCities; i++)
    {
        while(temp!=NULL)
        {
            if(!iVisited[(int)temp->cCityName-97])
                vDFS_Rec((int)temp->cCityName-97,iVisited);
            temp = temp->next;
        }   
    }
}
void ListGraph::vDFS_NonRec(char start)
{
    cStack stack;
    int s = (int)start-97;
    Node *temp;
    for (int i = 0; i < noOfCities; ++i)
    {
        iVisited[i]=0;
    }
    stack.vPush(s);
    while(!stack.bIsEmpty())
    {
        s = stack.iTop();
        if(iVisited[s]==0)
        {
            iVisited[s]=1;
            cout<<(char)(s+97)<<' ';
        }
        temp=iArrList[s];
        if(temp==NULL)
            s=stack.iPop();
        while(temp!=NULL)
        {
            if (iVisited[(int)(temp->cCityName)-97]==0)
            {
                stack.vPush((int)(temp->cCityName)-97);
                break;
            }
            if(temp->next==NULL)
                s=stack.iPop();
            temp = temp->next;
        }
    }
}
void ListGraph::vDisplayList()
{
   for(int i=0;i<noOfCities; i++)
	{
	   cout<<(char)(i+97);
	   Node *temp = iArrList[i];
	 while(temp!=NULL)
	  {
	    cout<<"->"<<temp->cCityName<<" ("<<temp->fDistance<<") ";
	    temp = temp->next;
	  }
		cout<<endl;
	}
}
ListGraph::ListGraph()
{
    noOfCities = -1;
    for(int i= 0; i<10;i++)
        iArrList[i]=NULL;
}
void ListGraph::vGetList()
{
   cout<<"Enter number of cities: ";
   cin>>noOfCities;
   char inp;
   for(int i=0; i<noOfCities;i++)
	{
	   for(int j=0; j<noOfCities; j++)
	    {
             cout<<"Is there a route between cities "<<(char)(i+97)<<" and "<<(char)(j+97)<<" y/n: ";
             cin>>inp;
             if(inp=='y')
              {
                if(i==j)
                {
                    cout<<"Flight cannot take-off and land in the same city!\n";
                    continue;
                }
		if(iArrList[i] == NULL)
		{
                	iArrList[i] = new Node;
			iArrList[i]->cCityName = (char)(j+97);
			cout<<"Enter Distance between cities: ";
			cin>>iArrList[i]->fDistance;
			iArrList[i]->next = NULL; 
		}
		else
		   {
			Node *temp = iArrList[i];
			while(temp->next != NULL)
				temp = temp->next;
			temp-> next = new Node;
			temp= temp->next;
			temp->cCityName = (char)(j+97);
			cout<<"Enter Distance between cities: ";
			cin>>temp->fDistance; 
			temp->next = NULL;
		   }
              }
            }
	}
}
int main()
{
    char inp;
    MatGraph graph1;
    ListGraph graph2;
    do{
        cout<<"1. Enter graph in Matrix form\n";
        cout<<"2. Enter graph in List form\n";
        cout<<"3. Show Matrix graph\n";
        cout<<"4. Show List graph\n";
        cout<<"5. Display BFS\n";
        cout<<"6. Display DFS Non-Rec\n";
        cout<<"7. Display DFS Rec\n";
        cin>>inp;
        switch(inp)
        {
        case '1':
            graph1.vGetMatrix();
            break;
        case '2':
	    graph2.vGetList();
            break;
        case '3':
            graph1.vDisplayGraph();
            break;
        case '4':
	    graph2.vDisplayList();
            break;
        case '5':
	    graph2.vBFS();
            break;
        case '6':
        cout<<"Enter starting vertex: ";
        cin>>inp;
	    graph2.vDFS_NonRec(inp);
        break;
        case '7':
	    graph2.vDFS_Rec();
            break;
        }
        cout<<"Enter y to continue";
        cin>>inp;
    }while(inp == 'y');
    return 0;
}
/*-------OUTPUT-------------
1. Enter graph in Matrix form
2. Enter graph in List form
3. Show Matrix graph
4. Show List graph
5. Display BFS
6. Display DFS Non-Rec
7. Display DFS Rec
1
Enter flight details of AI143:
Enter number of cities:
6
Is there a route between cities a and a y/n: n
Is there a route between cities a and b y/n: y
Enter distance between the cities: 34
Is there a route between cities a and c y/n: y
Enter distance between the cities: 34
Is there a route between cities a and d y/n: y
Enter distance between the cities: 67
Is there a route between cities a and e y/n: y
Enter distance between the cities: 1
Is there a route between cities a and f y/n: n
Is there a route between cities b and a y/n: n
Is there a route between cities b and b y/n: n
Is there a route between cities b and c y/n: n
Is there a route between cities b and d y/n: n
Is there a route between cities b and e y/n: n
Is there a route between cities b and f y/n: y
Enter distance between the cities: 67
Is there a route between cities c and a y/n: n
Is there a route between cities c and b y/n: n
Is there a route between cities c and c y/n: n
Is there a route between cities c and d y/n: n
Is there a route between cities c and e y/n: n
Is there a route between cities c and f y/n: y
Enter distance between the cities: 5
Is there a route between cities d and a y/n: n
Is there a route between cities d and b y/n: n
Is there a route between cities d and c y/n: n
Is there a route between cities d and d y/n: n
Is there a route between cities d and e y/n: n
Is there a route between cities d and f y/n: y
Enter distance between the cities: 45
Is there a route between cities e and a y/n: n
Is there a route between cities e and b y/n: n
Is there a route between cities e and c y/n: n
Is there a route between cities e and d y/n: n
Is there a route between cities e and e y/n: n
Is there a route between cities e and f y/n: y
Enter distance between the cities: 3
Is there a route between cities f and a y/n: n
Is there a route between cities f and b y/n: n
Is there a route between cities f and c y/n: n
Is there a route between cities f and d y/n: n
Is there a route between cities f and e y/n: n
Is there a route between cities f and f y/n: n
Enter y to continuey
1. Enter graph in Matrix form
2. Enter graph in List form
3. Show Matrix graph
4. Show List graph
5. Display BFS
6. Display DFS Non-Rec
7. Display DFS Rec
3
Flight details of AI143:
0	34	34	67	1	0	
0	0	0	0	0	67	
0	0	0	0	0	5	
0	0	0	0	0	45	
0	0	0	0	0	3	
0	0	0	0	0	0	
Enter y to continue
1. Enter graph in Matrix form
2. Enter graph in List form
3. Show Matrix graph
4. Show List graph
5. Display BFS
6. Display DFS Non-Rec
7. Display DFS Rec
2
Enter number of cities: 6
Is there a route between cities a and a y/n: n
Is there a route between cities a and b y/n: y
Enter Distance between cities: 3
Is there a route between cities a and c y/n: y
Enter Distance between cities: 7
Is there a route between cities a and d y/n: y
Enter Distance between cities: 8
Is there a route between cities a and e y/n: y
Enter Distance between cities: 3
Is there a route between cities a and f y/n: n
Is there a route between cities b and a y/n: n
Is there a route between cities b and b y/n: n
Is there a route between cities b and c y/n: n
Is there a route between cities b and d y/n: n
Is there a route between cities b and e y/n: n
Is there a route between cities b and f y/n: y
Enter Distance between cities: 8
Is there a route between cities c and a y/n: n
Is there a route between cities c and b y/n: n
Is there a route between cities c and c y/n: n
Is there a route between cities c and d y/n: n
Is there a route between cities c and e y/n: n
Is there a route between cities c and f y/n: y
Enter Distance between cities: 2
Is there a route between cities d and a y/n: n
Is there a route between cities d and b y/n: n
Is there a route between cities d and c y/n: n
Is there a route between cities d and d y/n: n
Is there a route between cities d and e y/n: n
Is there a route between cities d and f y/n: y
Enter Distance between cities: 8
Is there a route between cities e and a y/n: n
Is there a route between cities e and b y/n: n
Is there a route between cities e and c y/n: n
Is there a route between cities e and d y/n: n
Is there a route between cities e and e y/n: n
Is there a route between cities e and f y/n: y
Enter Distance between cities: 9
Is there a route between cities f and a y/n: n
Is there a route between cities f and b y/n: n
Is there a route between cities f and c y/n: n
Is there a route between cities f and d y/n: n
Is there a route between cities f and e y/n: n
Is there a route between cities f and f y/n: n
Enter y to continuey
1. Enter graph in Matrix form
2. Enter graph in List form
3. Show Matrix graph
4. Show List graph
5. Display BFS
6. Display DFS Non-Rec
7. Display DFS Rec
4
a->b (3) ->c (7) ->d (8) ->e (3) 
b->f (8) 
c->f (2) 
d->f (8) 
e->f (9) 
f
Enter y to continuey
1. Enter graph in Matrix form
2. Enter graph in List form
3. Show Matrix graph
4. Show List graph
5. Display BFS
6. Display DFS Non-Rec
7. Display DFS Rec
5

Enter starting vertex: a
 a b c d e fEnter y to continuey
1. Enter graph in Matrix form
2. Enter graph in List form
3. Show Matrix graph
4. Show List graph
5. Display BFS
6. Display DFS Non-Rec
7. Display DFS Rec
6
Enter starting vertex: a
a b f c d e Enter y to continuey
1. Enter graph in Matrix form
2. Enter graph in List form
3. Show Matrix graph
4. Show List graph
5. Display BFS
6. Display DFS Non-Rec
7. Display DFS Rec
7

Enter starting vertex: a
 a b f c d eEnter y to continuen
*/

