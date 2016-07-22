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
			result =0;
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
**************************************************************************************************
Enter two numbers: 3 4
Enter the operand: -
3 - 4 is: -1
Do you want to add another number to the result? (y)n
Do You Want To Continue? (y)
y
Enter two numbers: 5 7
Enter the operand: +
5 + 7 is: 12
Do you want to add another number to the result? (y)n
Do You Want To Continue? (y)
y
Enter two numbers: 4 1
Enter the operand: /
4 / 1 is: 4
Do you want to add another number to the result? (y)n
Do You Want To Continue? (y)
y
Enter two numbers: 4 6
Enter the operand: *
4 * 6 is: 24
Do you want to add another number to the result? (y)n
Do You Want To Continue? (y)


