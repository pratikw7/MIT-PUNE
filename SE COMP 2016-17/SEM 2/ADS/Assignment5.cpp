//------Ashwin Vaidya-----\
//-------202030------------
//------Prims--------------
//-----COPYRIGHT-------\Just kidding\ ----\CC\

#include <iostream>
using namespace std;
#define infinity 9999;	//random large value

class cGraph
{
	int iGraph[10][10];//Fully connected graph
	int visited[10],distance[10];
	int vertices;
public:
	cGraph();
	void vGetData();
	void vDisplay();
	void vPrims();
};
cGraph::cGraph()
{
	cout<<"Enter number of vertices: ";
	cin>>vertices;
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			if(i==j)
			iGraph[i][j]=0;

			else
			iGraph[i][j]=infinity;
		}
	}
	for(int i=0;i<vertices;i++)
		{
            visited[i]=0;
			distance[i]=infinity;
		}
}
void cGraph::vGetData()
{
	int cost;
	cout<<"Enter 0 if vertices are not adjacent\n";
	for (int i = 0; i < vertices; ++i)
	{
		for (int j = 0; j < vertices; ++j)
		{
			if (i!=j && j>i)
			{
				cout<<"Enter cost of edge between "<<i<<" and "<<j<<" : ";
				cin>>cost;
				if(cost!=0)
				{
					iGraph[i][j]=cost;
					iGraph[j][i]=cost;
				}
			}
		}
	}
}
void cGraph::vDisplay()
{
	cout<<"The graph is: \n";
	for (int i = 0; i < vertices; ++i)
	{
		for (int j = 0; j < vertices; ++j)
		{
			cout<<iGraph[i][j]<<'\t';
		}
		cout<<"\n";
	}
}
void cGraph::vPrims()
{
	int start,vertVisited,cost;
	cout<<"Enter starting vertex: ";
	cin>>start;
	distance[start] = 0;
	vertVisited =0;
	//visited[start]=1;
	while(vertVisited!=vertices)
	{
		for (int i = 0; i < vertices; ++i)
		{
			if(iGraph[start][i]!=0)
				if (visited[i]==0)
					if(distance[i]>iGraph[start][i])
						distance[i]=iGraph[start][i];
		}
		cost=infinity;
		for (int i = 0; i < vertices; ++i)
		{
			if (visited[i]==0)
				if(distance[i]<cost)
				{
					cost=distance[i];
					start=i;
				}
		}
		visited[start]=1;
		cout<<start<<"->";
		vertVisited++;
	}
	cost = 0;
	for (int i = 0; i < vertices; ++i)
		cost+=distance[i];
	cout<<"Minumum cost is: "<<cost;
}
int main()
{
	cGraph G;
	char inp;
	do
	{
		cout<<"1. Enter graph\n";
		cout<<"2. Display graph\n";
		cout<<"3. Find shortest path\n";
		cin>>inp;
		switch(inp)
		{
			case '1':
				G.vGetData();
				break;
			case '2':
				G.vDisplay();
				break;
			case '3':
				G.vPrims();
				break;
		}
		cout<<"Do you want to continue?(y) ";
		cin>>inp;
	} while (inp=='y');
	return 0;
}
