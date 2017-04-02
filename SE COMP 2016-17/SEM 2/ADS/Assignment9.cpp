//------Ashwin Vaidya-----\
//-------202030------------
//------Fle Handl..--------------
//-----COPYRIGHT-------\Just kidding\ ----\CC\
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
    string sName;
    int iRNo;
    string sAddress;
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
    fstream File;
    File.open("Database.ash",ios::out|ios::binary);
    cout<<"Enter Name: ";
    cin>>S.sName;
    cout<<"Enter Roll Number: ";
    cin>>S.iRNo;
    cout<<"Enter Address: ";
    cin>>S.sAddress;
    File.write((char*)&S,sizeof(S));
    File.close();
}
void cFileHandl::vDisplay()
{
    Student S;
    fstream File;
    File.open("Database.ash",ios::in|ios::binary);
    while(File.read((char*)&S,sizeof(S)))
    {
        cout<<"Name: ";
        cout<<S.sName;
        cout<<"Roll Number: ";
        cout<<S.iRNo;
        cout<<"Address: ";
        cout<<S.sAddress;
        cout<<endl;
    }
    File.close();
}
void cFileHandl::vModify()
{
    Student S;
    int roll;
    cout<<"Enter roll number: ";
    cin>>roll;
    fstream File;
    File.open("Database.ash",ios::in|ios::binary);
    while(File.read((char*)&S,sizeof(S)))
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
     while(File.read((char*)&S,sizeof(S)))
    {
        if(S.iRNo != roll)
        {
            File1.write((char*)&S,sizeof(S));
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
    while(File.read((char*)&S,sizeof(S)))
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
                                                                        