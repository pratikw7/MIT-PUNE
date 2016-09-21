#include <iostream>
#include "quadratic.h"

using namespace std;

int main()
{
   char inp;
   Quadratic Qno1, Qno2;
   cout<<"Enter a quadratic nomber: \n";
   cin>>Qno1;
   cout<<"Input equation is: "<<Qno1<<endl;
   do
   {
    cout<<"1. Add another quadratic number to it\n";
    cout<<"2. Compute for a value of x\n";
    cout<<"3. Find the value of x\n";
    cin>>inp;
    switch(inp)
    {
     case '1':
        cin>>Qno2;
        Qno1= Qno1 + Qno2;
        cout<<"New equation is"<<Qno1;
        break;
     case '2':
        Qno1.Eval();
        break;
     case '3':
        Qno1.ValueOfX();
        break;
     default:
        cout<<"Enter a valid option";
        break;    
    }
    cout<<"Do you want to continue?(y) ";
    cin>>inp;
   }while(inp=='y');

   return 0;
}
