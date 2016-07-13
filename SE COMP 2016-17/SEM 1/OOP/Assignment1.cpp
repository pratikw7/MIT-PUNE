#include<iostream>
using namespace std;
class Calculator
{
	private:
	float operator1, operator2, result;
	char operand;
	public:
	

	void GetData();
	void DisplayData();
	void calculate();
	void AnotherNumber();
	
	Calculator();

};

Calculator::Calculator()
{
	operator1 =0; operator2 = 0; result =0;
	operand ='+';
}

void Calculator::GetData()
{
	cout<<"Enter two numbers: ";
	cin>>operator1>>operator2;
	cout<<"Enter the operand: ";
	cin>>operand;
}

void Calculator::calculate()
{
	switch(operand)
	{
		case '+':
			result = operator1 + operator2;
			break;
		case '-':
			result = operator1 - operator2;
			break;
		case '/':
			result = operator1 / operator2;
			break;
		case '*':
			result = operator1 * operator2;
			break;
		default :
			cout<<"Incorrect operator!"<<endl;
			break;
	}

}
void Calculator::DisplayData()
{
	cout<<operator1 <<' '<<operand<<' '<<operator2<<" is: "<<result<<endl;
}

void Calculator::AnotherNumber()
{
	operator1 = result;
	cout<<"Enter another number: "; cin>>operator2;
	result = operator1+ operator2;
	DisplayData();
}

int main()
{
	Calculator calc;
	char inp='y';
	while(inp =='y')
	{
		calc.GetData();
		calc.calculate();
		calc.DisplayData();
		cout<<"Do you want to add another number to the result? (y)";
		cin>>inp;
		if(inp=='y')
			calc.AnotherNumber();
		cout<<"Do You Want To Continue? (y)"<<endl;
		cin>>inp;
	}
	return 0;
}
