//----Ashwin Vaidya-----
//----SE202030----------
//--------S1------------
#include <iostream>
#include <stdio.h>
#include <exception>
using namespace std;

class Age_Exception: public exception
{
public:
	const char* what() const throw()
	{
		return "Age is not in the range 18-55\n";
	}
};
class Income_Exception: public exception
{
public:
	const char* what() const throw()
	{
		return "Income is not in the range Rs.50,000-1,00,000\n";
	}
};
class City_Exception: public exception
{
public:
	const char* what() const throw()
	{
		return "City is not Pune or Mumbai or Banglore or Chennai\n";
	}
};
class Vehicle_Exception: public exception
{
public:
	const char* what() const throw()
	{
		return "Vehicle is not a four wheeler\n";
	}
};

struct User
{
	int age;
	unsigned int income;
	string city;
	string VehicleType;
};

int main()
{
	char c;
	User User1;
	Age_Exception expAge;
	Income_Exception expIncome;
	City_Exception expCity;
	Vehicle_Exception expVehicle;
	do{
	cout<<"Enter age\n";
	try{
		cin>>User1.age;
		if(User1.age<18||User1.age>55)
			throw(expAge);
	}
	catch(Age_Exception &exp)
	{
		cout<<exp.what();
	}
	cout<<"Enter Income\n";
		try{
			cin>>User1.income;
			if(User1.income<50000||User1.income>100000)
				throw(expIncome);
		}
		catch(Income_Exception &exp)
		{
			cout<<exp.what();
		}
	cout<<"Enter City\n";
		try{
			cin>>User1.city;
			if(User1.city=="Pune"||User1.city=="Mumbai"||User1.city=="Banglore"||User1.city=="Chennai");
			else
				throw(expCity);
		}
		catch(City_Exception &exp)
		{
			cout<<exp.what();
		}
	cout<<"Enter Vehicle Type\n";
		try{
			cin>>User1.VehicleType;
			if(User1.VehicleType!="4wheeler")
				throw(expVehicle);
		}
		catch(Vehicle_Exception &exp)
		{
			cout<<exp.what();
		}
	cout<<"Do you want to continue?(y)";
	cin>>c;
	}while(c=='y');
	return 0;
}
//-----------OUTPUT---------------------
/*
Enter age
34
Enter Income
60000
Enter City
Pune
Enter Vehicle Type
4wheeler
Do you want to continue?(y)y
Enter age
3
Age is not in the range 18-55
Enter Income
145000
Income is not in the range Rs.50,000-1,00,000
Enter City
Delhi
City is not Pune or Mumbai or Banglore or Chennai
Enter Vehicle Type
2wheeler
Vehicle is not a four wheeler
Do you want to continue?(y)n
 */
