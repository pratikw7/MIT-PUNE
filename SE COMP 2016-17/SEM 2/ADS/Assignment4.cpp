//------------ASHWIN VAIDYA-----------
//---------------202030---------------
//++++++++++++++++++++++++++++++++++++
#include <iostream>
using namespace std;

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
public:
    ListGraph();
    void vGetList();
    void vDisplayList();
};
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
        }
        cout<<"Enter y to continue";
        cin>>inp;
    }while(inp == 'y');
    return 0;
}

