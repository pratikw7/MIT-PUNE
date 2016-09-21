#include "quadratic.h"
#include <math.h>
Quadratic::Quadratic()
{
	a=0, b=0, c=0;
}

Quadratic Quadratic::operator+(Quadratic x)
{
      Quadratic temp;
      temp.a = a + x.a; temp.b = b+ x.b; temp.c = c+ x.c;
      return temp;
}

istream&operator>>(istream& ins, Quadratic &x)
{
   cout<<"Enter a: ";
   ins>>x.a;
   cout<<"Enter b: ";
   ins>>x.b;
   cout<<"Enter c: ";
   ins>>x.c;
   return ins;
}

ostream&operator<<(ostream& out , Quadratic &y)
{
  
  out<<y.a;
  cout<<"x^2 + ";
  out<<y.b;
  cout<<"x + ";
  out<<y.c;
  return out;
}

void Quadratic::Eval()
{
   int xVal;
   cout<<"Enter a value of x to calculate the value of polynomial: ";
   cin>>xVal;
   cout<<"Value of polynomial is: ";
   cout<<a*xVal*xVal + b*xVal +c<<endl;
}
void Quadratic::ValueOfX()
{
  float D = b*b-4*a*c;
  if(D<0)
    cout<<"Cannot be sloved! It has imaginary roots\n";
  else if(D==0)
    cout<<"x1 = x2 = "<<-b/(2*a);
  else
    {
      cout<<"x1 = "<<(-b+sqrt(D))/(2*a)<<endl;
      cout<<"x2 = "<<(-b-sqrt(D))/(2*a)<<endl;
    }
}
