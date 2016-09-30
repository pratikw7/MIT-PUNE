#include <iostream>
#include <vector>
using namespace std;

class cSearch
{
public:
  void vLinearSearch(vector<int>,int);
  void vSentinalSearch(vector<int>, int);
  void vBinarySearch(vector<int>, int);
  void vFibonnaciSearch(vector<int>, int);
  int  iFibonacciReturn(int);
private:
  void vSort(vector <int>&);
};
int cSearch::iFibonacciReturn(int k)            // calculate the values related to fibonacci  function
{ int f1,f2,f3;
      f1=0;
      f2=1;
      if(k==0)
      return 0;
      else if (k==1)
    	  return 1;
      else
      {
    	  for(int i=2;i<=k;i++)
    	  {
    	     f3=f1+f2;
    	     f1=f2;
    	     f2=f3;
    	  }
      }
	return f3;
}
void cSearch::vFibonnaciSearch(vector<int> s, int ele)	//Fibonnaci Search
{
vSort(s);
int k=0;
    while(iFibonacciReturn(k)<s.size())
    	k++;

    int f1=iFibonacciReturn(k-2);
    int f2=iFibonacciReturn(k-3);
    int mid=s.size()-f1+1;
    while(ele!=s[mid])
    {if(mid<0|| ele>s[mid])
    {if(f1==1){
    	cout<<"The student did not attended the training program\n";
	return;
	}
      mid=mid+f2;
      f1=f1-f2;
      f2=f2-f1;
    }
    else
    {if(f2==0){
    	cout<<"The student did not attended the training program\n";
	return;
	}
    mid=mid-f2;
    int t=f1-f2;
    f1=f2;
    f2=t;}
    }
      cout<<"The student attended the training program\n";
      return;
}
void cSearch::vLinearSearch(vector<int> s, int ele) //Linear search
{
  for(int i=0; i<s.size();i++)
  {
    if(s[i]==ele)
    {
      cout<<"The student attended the training program\n";
      return;
    }
  }
  cout<<"The student did not attended the training program\n";
}
void cSearch::vSentinalSearch(vector<int> s, int ele)	//sentinal search
{
  int i=0;
  s.push_back(ele);
  while(s[i]!=ele)
  {
    i++;
  }
  if(i==s.size()-1)
    cout<<"The student did not attended the training program\n";
  else
    cout<<"The student attended the training program\n";
}
void cSearch::vBinarySearch(vector<int> s, int ele)	//Binary search
{
  vSort(s);
	int low=0;
	int high=s.size()-1;
	int mid=0;
    while(low<=high)
    { mid=(low+high)/2;
      if(s[mid]==ele){
      cout<<"The student attended the training program\n";
      return;
	}
   else if(ele>s[mid])
      {low=mid+1;}
      else
      high=mid-1;
}
 cout<<"The student did not attended the training program\n";
 }
void cSearch::vSort(vector<int> &s)	//sorting required for binary and fibonnaci search
{
  int flag =1;
  while(flag)
  {
  flag =0;
  for(int i=0; i<s.size()-1;i++)
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
  cout<<"Sorted list is: ";
  for(int i=0; i<s.size();i++)
  {
    cout<<s[i]<< " ";
  }
  cout<<endl;
}
int main() {
  vector<int> students;
  cSearch search;
  int a;
  char c;
  while(true)
  {
    cout<<"Enter the roll number of student"
    <<" who attended the session: ";
    cin>>a;
    students.push_back(a);
    cout<<"Do you want to continue adding?(y) ";
    cin>>c;
    if(c!='y')
      break;
  }
  while(true)
  {
    cout<<"Enter an element to search: ";
    cin>>a;
    cout<<"\tLinear search\n";
    search.vLinearSearch(students, a);
    cout<<"\tSentinal search\n";
    search.vSentinalSearch(students, a);
    cout<<"\tBinary search\n";
    search.vBinarySearch(students, a);
    cout<<"\tFibonnaci search\n";
    search.vFibonnaciSearch(students, a);
    cout<<"Do you want to continue searching?(y) ";
    cin>>c;
    if(c!='y')
      break;
  }
  return 0;
}
//------------OUTPUT---------------
/*
Enter an element to search: 14
	Linear search
The student did not attended the training program
	Sentinal search
The student did not attended the training program
	Binary search
Sorted list is: 2 13 45 66 
The student did not attended the training program
	Fibonnaci search
Sorted list is: 2 13 45 66 
The student did not attended the training program
Do you want to continue searching?(y) y
Enter an element to search: 13
	Linear search
The student attended the training program
	Sentinal search
The student attended the training program
	Binary search
Sorted list is: 2 13 45 66 
The student attended the training program
	Fibonnaci search
Sorted list is: 2 13 45 66 
The student attended the training program
*/
