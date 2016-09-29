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
private:
  void vSort(vector <int>&);
};
void cSearch::vLinearSearch(vector<int> s, int ele)
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
void cSearch::vSentinalSearch(vector<int> s, int ele)
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
void cSearch::vBinarySearch(vector<int> s, int ele)
{
  vSort(s);
}
void cSearch::vSort(vector<int> &s)
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
        s[i] = temp;
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
    search.vBinarySearch(students, a);
    cout<<"Do you want to continue searching?(y) ";
    cin>>c;
    if(c!='y')
      break;
  }
  return 0;
}
