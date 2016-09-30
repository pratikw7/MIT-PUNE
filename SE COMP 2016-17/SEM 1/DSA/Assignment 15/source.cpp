//-----------------Ashwin Vaidya------------------
//---------------------SE1------------------------
//--------------------202030----------------------
//Insertion sort
//Shell sort and display top 5 scores
#include <iostream>
using namespace std;

class cSort
{

public:
	int n;
	int list[20];
	void vInsertionSort();
	void vShellsort();
};
void cSort::vInsertionSort()
{
	int i,j,temp;

	for(i=1;i<n;i++)
	{
		temp=list[i];
		for( j=i-1;j>=0 &&list[j]>temp;j--)
			list[j+1]=list[j];
		list[j+1]=temp;
	}
	  cout<<"---------------Sorted list using Insertion sort-------------------\n";
	  for(unsigned int i=0; i<n; i++)
	  {
		  cout<<list[i]<< " ";
	  }
	  cout<<endl;
	  cout<<"--------------------Top 5 Percentages---------------\n";
	  	for(unsigned int i=n-5; i<n; i++)
	  			  {
	  				  cout<<list[i]<< " ";
	  			  }
	  			  cout<<endl;
}
void cSort::vShellsort()
{

	int i,j,step;
	int temp;
	for(step=n/2;step>0;step=step/2)
		for(i=step;i<n;i++)
	{
		temp=list[i];
		for(j=1;j>=step;j=j-step)
			if(temp<list[j-step])
				list[j]=list[j-step];
			else
				break;
		list[j]=temp;

	}
	cout<<"---------------Sorted list using Shell sort-------------------\n";
		  for(unsigned int i=0; i<n; i++)
		  {
			  cout<<list[i]<< " ";
		  }
		  cout<<endl;
		  cout<<"--------------------Top 5 Percentages---------------\n";
		  	for(unsigned int i=n-5; i<n; i++)
		  			  {
		  				  cout<<list[i]<< " ";
		  			  }
		  			  cout<<endl;
}
int main()
{
	cSort sSort;
	cout<<"Enter Number of elements in the list:";
	        cin>>sSort.n;
	    	cout<<"Enter the elements: ";
	    	for(int i=0;i<sSort.n;i++)
	    	{
	    		cin>>sSort.list[i];
	    	}
	sSort.vInsertionSort();
	sSort.vShellsort();
	return 0;
}
//---------------OUTPUT--------------
/*
Enter Number of elements in the list:6
Enter the elements: 99
87
91
93
75
89
---------------Sorted list using Insertion sort-------------------
75 87 89 91 93 99 
--------------------Top 5 Percentages---------------
87 89 91 93 99 
---------------Sorted list using Shell sort-------------------
75 87 89 91 93 99 
--------------------Top 5 Percentages---------------
87 89 91 93 99 
*/

