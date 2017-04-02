//-------Ashwin------------
//---------202030----------
#include <iostream>
using namespace std;
class cHeap{
	int iHeap[20];
	int size;
	public:
	void vInsert()
	{	
		iHeap[0]=0;
		cout<<"Enter size of heap: ";
		cin>>size;
		for (int i = 0; i < size; ++i)
		{
			cout<<"Enter number: ";
			int data;
			cin>>data;

		int n=iHeap[0];
		iHeap[n+1]=data;
		iHeap[0]=n+1;
		vUpAdjust(n+1);
		}
		
	}
	void vUpAdjust(int index){
		while(index>1 && iHeap[index]>iHeap[index/2]){
			vSwap(&iHeap[index],&iHeap[index/2]);
			index=index/2;
		}
	}
	void vDownAdjust(int index){
		if(2*index<=iHeap[0]){
			if(iHeap[index]<iHeap[2*index]){
				vSwap(&iHeap[index],&iHeap[2*index]);
				vDownAdjust(2*index);

			}
			if((2*index) + 1 <=iHeap[0]  &&  iHeap[index]<iHeap[(2*index)+1] ){
				vSwap(&iHeap[index],&iHeap[(2*index)+1]);
				vDownAdjust((2*index) +1);
			}
			return;
		}
	}
	void vSort(){

		while(iHeap[0]>1){
			vSwap(&iHeap[1],&iHeap[iHeap[0]]);
			iHeap[0]--;
			vDownAdjust(1);

		}


	}
	void vSwap(int *a,int *b){
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	void vDisplay(){
		for(int i=1;i<=size;i++)
			cout<<iHeap[i]<<" ";
		cout<<endl;
	}
};
int main() {
	cHeap H;
	H.vInsert();
	cout<<"Before sorting\n";
	H.vDisplay();
	H.vSort();
	cout<<"After sorting\n";
	H.vDisplay();

	return 0;
}
