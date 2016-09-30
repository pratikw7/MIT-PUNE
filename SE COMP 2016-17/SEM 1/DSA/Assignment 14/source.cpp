//-----------------Ashwin Vaidya------------------
//---------------------SE1------------------------
//--------------------202030----------------------
//Selection Sort
//Bubble sort and top five
#include <iostream>
#include <vector>
using namespace std;

class cSort
{
public:
	void vBubbleSort(vector<float>);
	void vSectionSort(vector<float>);
};
void cSort::vBubbleSort(vector<float> s)
{
	int flag =1;
	  while(flag)
	  {
	  flag =0;
	  for(unsigned int i=0; i<s.size()-1;i++)
	  {
	    if(s[i]>s[i+1])
	      {
	        int temp = s[i];
	        s[i] = s[i+1];
	        s[i+1] = temp;
	        flag = 1;
	      }
	  }
	  }
	  cout<<"---------------Sorted list using bubble sort-------------------\n";
	  for(unsigned int i=0; i<s.size(); i++)
	  {
		  cout<<s[i]<< " ";
	  }
	  cout<<endl;
	  cout<<"--------------------Top 5 Percentages---------------\n";
	  	for(unsigned int i=s.size()-5; i<s.size(); i++)
	  			  {
	  				  cout<<s[i]<< " ";
	  			  }
	  			  cout<<endl;
}
void cSort::vSectionSort(vector<float> s)
{
	unsigned int i,j,k;
	float temp;
	for(i=0;i<s.size()-1;i++)
	{
		k=i;
		for (j=i+1;j<s.size();j++)
			if(s[j]<s[k])
				k=j;
		if(k!=i)
		{
			temp=s[i];
			s[i]=s[k];
			s[k]=temp;
		}
	}
	cout<<"---------------Sorted list using selection sort-------------------\n";
		  for(unsigned int i=0; i<s.size(); i++)
		  {
			  cout<<s[i]<< " ";
		  }
		  cout<<endl;
		  cout<<"--------------------Top 5 Percentages---------------\n";
		  	for(unsigned int i=s.size()-5; i<s.size(); i++)
		  			  {
		  				  cout<<s[i]<< " ";
		  			  }
		  			  cout<<endl;
}
int main()
{
	vector<float> vfPer;
	char c;
	float input;
	cSort sSort;
	while(true)
	{
		cout<<"Enter percentage: ";
		cin>>input;
		vfPer.push_back(input);
		cout<<"Do you want to continue?(y) ";
		cin>>c;
		if(c!='y')
			break;
	}
	sSort.vBubbleSort(vfPer);
	sSort.vSectionSort(vfPer);
	return 0;
}
//---------------OUTPUT--------------------
/*
Enter percentage: 90
Do you want to continue?(y) y
Enter percentage: 93.4
Do you want to continue?(y) y
Enter percentage: 78
Do you want to continue?(y) y
Enter percentage: 77.6
Do you want to continue?(y) y
Enter percentage: 88.9
Do you want to continue?(y) y
Enter percentage: 91.4
Do you want to continue?(y) n
---------------Sorted list using bubble sort-------------------
77.6 78 88.9 90 91.4 93 
--------------------Top 5 Percentages---------------
78 88.9 90 91.4 93 
---------------Sorted list using selection sort-------------------
77.6 78 88.9 90 91.4 93.4 
--------------------Top 5 Percentages---------------
78 88.9 90 91.4 93.4 
*/

