//------------Ashwin Vaidya-----------
//----------------S1------------------
//---------------202030---------------
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Record
{
	string sName;
	unsigned long int uiPhNO;
public:
	Record();
	void vAddRecord();
	string sReturnName();
	unsigned long int uiReturnPhNo();
	void vUpdatePhNO();
	void vDisplay();
};

Record::Record()
{
	sName = "\0";
	uiPhNO = 0;
}

void Record::vAddRecord()
{
	cout<<"Enter Name of person: ";
	cin>>sName;
	cout<<"Enter phone number of person: ";
	cin>>uiPhNO;
}

string Record::sReturnName()
{
	return sName;
}
unsigned long int Record::uiReturnPhNo()
{
	return uiPhNO;
}
void Record::vDisplay()
{
	cout<<sName<<" ";
	cout<<uiPhNO<<"\n";
}
int main()
{
	Record rObject;
	fstream myFile("Datafile.df", ios::out|ios::in|ios::binary|ios::trunc);
	char inp;
	cout<<"Initialise database\n";

	while(!myFile.fail())
	{
		rObject.vAddRecord();
		myFile.write((char*)&rObject, sizeof(rObject));
		cout<<"Do you want to continue?(y)";
		cin>>inp;
		if(myFile.fail())
			cout<<"Fail\n";
		if(inp!='y')
			break;
	}
		/*myFile.close();
	myFile.open("Datafile.df", ios::in |ios::out | ios::binary|ios::app);*/
	do{
		cout<<"1. Find name\n";
		cout<<"2. Find telephone\n";
		cout<<"3. Update record\n";
		cout<<"4. Display database\n";
		cin>>inp;
		switch(inp)
		{
		case '1':
                {
			unsigned long  int PhNo;
				cout<<"Enter a phone number\n";
				cin>> PhNo;
				myFile.seekg(0, ios::beg);
				while(myFile.read((char*)&rObject, sizeof(Record)))
				{
					if(PhNo == rObject.uiReturnPhNo())
					{
						cout<<"Record found!";
						rObject.vDisplay();
						break;
					}
				}
        }
			break;
		case '2':
		{
			string sName;
				cout<<"Enter the name\n";
				cin>> sName;
				myFile.seekg(0, ios::beg);
				while(!myFile.eof())
				{
					myFile.read((char*)&rObject, sizeof(Record));
					if(sName.compare(rObject.sReturnName())==0)
					{
						cout<<"Record found!";
						rObject.vDisplay();
						break;
					}
				}
        }
			break;
		case '3':
		{
            cout<<"Enter the name of the person whose reccord you want to update: ";
            string sName;
				cin>> sName;
				myFile.seekg(0, ios::beg);
				while(!myFile.eof())
				{
					myFile.read((char*)&rObject, sizeof(Record));
					if(sName.compare(rObject.sReturnName())==0)
					{
						cout<<"Enter new deatils:\n";
						rObject.vAddRecord();
						myFile.seekg(-1*sizeof(Record));
						myFile.write((char*)&rObject, sizeof(rObject));
						break;
					}
				}
				cout<<"The entered name does not match any records!";
				break;
		}
			break;
		case '4':

			cout<<"----------------------\n";
			if(!myFile.fail()){
				myFile.seekg(0,ios::beg);
			while(myFile.read((char*)&rObject, sizeof(rObject)))
			{
                rObject.vDisplay();
			}
			cout<<"----------------------\n";
			break;
		}
		}
		cout<<"Do you want to continue?(y)";
		cin>>inp;
	}while(inp=='y');
	myFile.close();
	return 0;
}

