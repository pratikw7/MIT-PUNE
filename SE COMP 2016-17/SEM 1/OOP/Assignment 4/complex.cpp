

#include "complex.h"



Complex::Complex() {
	fReal =0;
	fImaginary =0;

}

Complex::Complex(float fA, float fB)
{
	fReal = fA;
	fImaginary = fB;
}

Complex Complex::operator+(Complex cNo2)
{	
	Complex temp;
	temp.fReal = fReal + cNo2.fReal;
	temp.fImaginary = fImaginary + cNo2.fImaginary;
	return temp;
}

Complex Complex::operator*(Complex cNo2)
{
	Complex ret;
	ret.fReal = fReal*cNo2.fReal - fImaginary*cNo2.fImaginary;
	ret.fImaginary = fReal*cNo2.fImaginary + 		   fImaginary*cNo2.fReal;
	return ret;
}

ostream& operator<<(ostream& out, Complex &ret)
{
	out<< ret.fReal;
	cout<<" + ";
	out<< ret.fImaginary;
	cout<<'i';
	return out;
}
istream& operator>>(istream& instr, Complex &ret)
{
	cout<<"Enter real part: ";
	instr>> ret.fReal;
	cout<<"Enter imaginary part: ";	
	instr>> ret.fImaginary;
	cout<<ret<<endl;
	return instr;
}

Complex::~Complex() {
	// TODO Auto-generated destructor stub
}

