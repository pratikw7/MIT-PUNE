

#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
using namespace std;
class Complex {
private:
	float fReal;
	float fImaginary;

public:
	Complex();
	Complex(float, float);
	Complex operator+(Complex);
	Complex operator*(Complex);
	friend ostream& operator<<(ostream&, Complex &);
	friend istream& operator>>(istream&, Complex &);
	virtual ~Complex();
};

#endif /* COMPLEX_H_ */
