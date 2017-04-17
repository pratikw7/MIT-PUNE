//------Ashwin Vaidya-----\
//-------202030------------
//------Fle Handl..--------------
//-----COPYRIGHT-------\Just kidding\ ----\CC\/
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Student
{
    char sName[20];
    int iRNo;
    char sAddress[25];
    friend class cFileHandl;
};
class cFileHandl
{
public:
    void vWrite();
    void vDisplay();
    void vModify();
    void vDeleteRecord();
    void vSearch();
};
void cFileHandl::vWrite()
{
    Student S;
    fstream file;
    file.open("Database.ash",ios::out|ios::binary|ios::app);
    cout<<"Enter Name: ";
    cin>>S.sName;
    cout<<"Enter Roll Number: ";
    cin>>S.iRNo;
    cout<<"Enter Address: ";
    cin>>S.sAddress;
    file.write((char*)&S,sizeof(S));
    file.close();
}
void cFileHandl::vDisplay()
{
    Student S;
    fstream file;
    file.open("Database.ash",ios::in|ios::binary);
     while(file.read((char*)&S,sizeof(S)))
    {
	
        cout<<"Name: ";
        cout<<S.sName<<'\t';
        cout<<"Roll Number: ";
        cout<<S.iRNo<<'\t';
        cout<<"Address: ";
        cout<<S.sAddress<<'\t';
        cout<<endl;
	
    }
    file.close();
}
void cFileHandl::vModify()
{
    Student S;
    int roll;
    cout<<"Enter roll number: ";
    cin>>roll;
    fstream File;
    File.open("Database.ash",ios::out|ios::in|ios::binary);
    while(!File.eof())
    {
	if(File.read((char*)&S,sizeof(S)))
	{
        if(S.iRNo == roll)
        {
            cout<<"Enter Name: ";
            cin>>S.sName;
            cout<<"Enter Roll Number: ";
            cin>>S.iRNo;
            cout<<"Enter Address: ";
            cin>>S.sAddress;
            File.seekp(-sizeof(S),ios::cur);
            File.write((char*)&S,sizeof(S));
            File.close();
            return;
        }
	}
    }
    cout<<"Roll No. not found!\n";
    File.close();
}
void cFileHandl::vDeleteRecord()
{
    Student S;
    int roll;
    cout<<"Enter roll number: ";
    cin>>roll;
    fstream File,File1;
    File.open("Database.ash",ios::in|ios::binary);
    File1.open("~Database.ash",ios::out|ios::binary);
      while(!File.eof())
    {
	if(File.read((char*)&S,sizeof(S)))
	{
        if(S.iRNo != roll)
        {
            File1.write((char*)&S,sizeof(S));
        }
	}
    }
    File1.close();
    File.close();
    remove("Database.ash");
    rename("~Database.ash","Database.ash");

    cout<<"Record deleted!\n";
}
void cFileHandl::vSearch()
{
    Student S;
    int roll,pos=0;
    cout<<"Enter roll number: ";
    cin>>roll;
    fstream File;
    File.open("Database.ash",ios::in|ios::binary);
  while(!File.eof())
    {
	if(File.read((char*)&S,sizeof(S)))
	{
        pos++;
        if(S.iRNo == roll)
        {
            cout<<"Record found at position: ";
            File.close();
            cout<<pos<<endl;
            return;
        }
	}
    }
    cout<<"Record not found!\n";
}
int main()
{
    cFileHandl Database;
    char inp;
    do
       {
           cout<<"1. Insert\n";
           cout<<"2. Display\n";
           cout<<"3. Modify\n";
           cout<<"4. Delete\n";
           cout<<"5. Search\n";
           cin>>inp;
           switch(inp)
           {
            case '1':
            Database.vWrite();
                break;
            case '2':
            Database.vDisplay();
                break;
            case '3':
            Database.vModify();
                break;
            case '4':
            Database.vDeleteRecord();
                break;
            case '5':
            Database.vSearch();
                break;
           }
           cout<<"Enter y to continue ";
           cin>>inp;
       } while (inp=='y');   
    return 0;
}
/*
1. Insert
2. Display
3. Modify
4. Delete
5. Search
2
Enter y to continue y
1. Insert
2. Display
3. Modify
4. Delete
5. Search
1
Enter Name: ashwin
Enter Roll Number: 30
Enter Address: sdf
Enter y to continue y
1. Insert
2. Display
3. Modify
4. Delete
5. Search
1
Enter Name: aditya
Enter Roll Number: 37
Enter Address: dfg
Enter y to continue y
1. Insert
2. Display
3. Modify
4. Delete
5. Search
2
Name: ashwin	Roll Number: 30	Address: sdf	
Name: aditya	Roll Number: 37	Address: dfg	
Enter y to continue y
1. Insert
2. Display
3. Modify
4. Delete
5. Search
3
Enter roll number: 37
Enter Name: aniket
Enter Roll Number: 29
Enter Address: sfg
Enter y to continue y
1. Insert
2. Display
3. Modify
4. Delete
5. Search
2
Name: ashwin	Roll Number: 30	Address: sdf	
Name: aniket	Roll Number: 29	Address: sfg	
Enter y to continue y
1. Insert
2. Display
3. Modify
4. Delete
5. Search
4
Enter roll number: 29
Record deleted!
Enter y to continue y
1. Insert
2. Display
3. Modify
4. Delete
5. Search
2
Name: ashwin	Roll Number: 30	Address: sdf	
Enter y to continue y
1. Insert
2. Display
3. Modify
4. Delete
5. Search
5
Enter roll number: 30
Record found at position: 1
Enter y to continue 
*/                                                                        
