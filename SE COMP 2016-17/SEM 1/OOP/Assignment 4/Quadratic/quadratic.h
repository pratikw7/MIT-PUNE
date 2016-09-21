#ifndef QUADRATIC_H
#define QUADRATIC_H
#include <iostream>
using namespace std;

class Quadratic
{
  private:
    int a,b,c;
  public:
    Quadratic();
    Quadratic operator+(Quadratic);
    friend istream&operator>>(istream&, Quadratic &);
    friend ostream&operator<<(ostream& , Quadratic &);
    void Eval();
    void ValueOfX();
};


#endif
