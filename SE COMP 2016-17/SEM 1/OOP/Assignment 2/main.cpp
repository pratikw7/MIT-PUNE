#include "books.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <cstring>


using namespace std;



void DisplayList(Books *b[], int n)
{
	cout<<"Author"<<"\t\t"<<"Title"<<"\t\t"<<"Price"<<"\t"<<"Publisher"<<"\t\t"<<"Stock"<<endl;
	for(int i=0; i<n; i++)
	{
		b[i]->ShowData();
	}
}

int main()
{
	int n=0, flag=1, copies=0, maxChar =0;
	cout<<"Enter the max number of characters in title: ";
	cin>>maxChar;
	char * title = new char[maxChar], *author = new char[maxChar];
	cout<<"Enter the number of different titles in the library: ";
	cin>>n;
	cout<<"Enter the details of each book: \n";
	Books *b[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Title "<<i+1<<endl;
		b[i] = new Books(maxChar);
		b[i]->GetData();
	}
	char inp;
	do
	{
	  cout<<"1. List details of each book\n";
	  cout<<"2. Buy a book \n";
	  cin>>inp;
	  switch (inp)
	  {
	    case '1':
		DisplayList(b, n);
		break;
	    case '2':
		cin.ignore();
		cout<<"Enter the Title of the book: ";
		gets(title);
		cout<<"Enter the Author of the book: ";
		gets(author);

		for(int i=0; i<n; i++)
		{
		  if((strcmp(b[i]->GetAuthor() , author)==0  && strcmp(b[i]->GetTitle() , title)==0))
			{
				flag=0;
				cout<<"Author"<<"\t\t"<<"Title"<<"\t\t"<<"Price"<<"\t"<<"Publisher"<<"\t\t"<<"Stock"<<endl;
				b[i]->ShowData();
		                cout<<"How many copies do you want?";
		   		cin>>copies;
		   		if(copies<b[i]->GetStock())
					cout<<"Total Price is: "<<copies*b[i]->GetPrice()<<endl;
				else
					cout<<"Requested copies not in stock\n";

			}	
		}
		if(flag)
		 cout<<"We are sorry but we don't have the book you requested\n";
		flag =1;
		break;
  	    default :
		cout<<"Please Enter a valid input\n";
		break;
	  }
	  cout<<"Do you want to continue? (y)";
	  cin>>inp;

	}while(inp=='y');
//delete all pointers
	for(int i=0; i<n;i++)
		delete b[i];
	delete [] title;
	delete [] author;
	return 0;
}
