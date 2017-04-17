//-------Ashwin------------
//---------202030----------
#include <iostream>
using namespace std;
class cHeap{
	int arr1[20],arr2[20];
	int size,n;
	public:
	void vInsert()
	{	
		cout<<"Enter size of heap: ";
		cin>>size;
		arr1[0]=arr2[0] = size;
		for (int i = 1; i < size+1; ++i)
		{
			cout<<"Enter number: ";
			int data;
			cin>>data;
			n=i;
			arr1[i]=arr2[i]=data;
			UpAdjustment();
			DownAdjustment();
		}
		
	}

void UpAdjustment()
	{
		int temp;
		int n1=n;
		while(n1>1&&arr1[n1]>arr1[n1/2])
		{
			temp=arr1[n1];
			arr1[n1]=arr1[n1/2];
			arr1[n1/2]=temp;
			n1=n1/2;
		}
	}

	void DownAdjustment()
	{
		int temp;
		int n2=n;
		while(n2>1&&arr2[n2]<arr2[n2/2])
		{
			temp=arr2[n2];
			arr2[n2]=arr2[n2/2];
			arr2[n2/2]=temp;
			n2=n2/2;
		}
	}

	void DisplayMax()
	{
		cout<<"Heap is:\n";
		for(int i=1;i<size+1;i++)
		{
			cout<<arr1[i]<<"   ";
		}
		cout<<"\nMaximum : "<<arr1[1]<<endl;
	}

	void DisplayMin()
	{
		cout<<"Heap is:\n";
		for(int i=1;i<size+1;i++)
		{
			cout<<arr2[i]<<"   ";
		}
		cout<<"\nMinimum : "<<arr2[1]<<endl;
	}
};

int main() {
	cHeap H;
	char inp;
	do{
	cout<<"1. Enter\n";
	cout<<"2. Max Heap\n";
	cout<<"3. Min Heap\n";
	cin>>inp;
	switch(inp)
	{
	case '1':
	H.vInsert();
	break;
	case '2':
	H.DisplayMax();
	break;
	case '3':
	H.DisplayMin();
	break;
	}
	cout<<"Enter y to continue";
	cin>>inp;

	}while(inp=='y');
	return 0;
}
/*--OUTPUT-----
1. Enter
2. Max Heap
3. Min Heap
1
Enter size of heap: 5
Enter number: 6
Enter number: 1
Enter number: 4
Enter number: 2
Enter number: 3
Enter y to continuey
1. Enter
2. Max Heap
3. Min Heap
2
Max Heap is:
6   4   3   2   1   
Maximum number is: 4
Enter y to continuey
1. Enter
2. Max Heap
3. Min Heap
3
Min Heap is:
6   1   3   2   4   
Minimum number is: 1
Enter y to continue
*/
