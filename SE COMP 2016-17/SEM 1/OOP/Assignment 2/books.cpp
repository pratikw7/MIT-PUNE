#include "books.h"
#include <iostream>
#include <stdio.h>
using namespace std;
Books::Books(int size)
{
	Author= new char[size];
	Title =new char[size];
	Publisher =new char[size];
	stock =0;
	price =0;
}
Books::~Books()
{
	delete [] Author;
	delete [] Title;
	delete []Publisher;

}

void Books::GetData()
{
	cin.ignore();
	cout<<"Enter the name of Author: \n";
	gets(Author);
	cout<<"Enter the Title: \n";
	gets(Title);
	cout<<"Enter the name of Publisher: \n";
	gets(Publisher);
	cout<<"Enter the price of each copy: \n";
	cin>>price;
	cout<<"Enter the stock of copies: \n";
	cin>>stock;
}

void Books::ShowData()
{
	cout<<Author<<"\t"<<Title<<"\t\t"<<price<<"\t"<<Publisher<<"\t\t"<<stock<<endl;
}

char* Books::GetAuthor()
{return Author;}

char* Books::GetTitle()
{return Title;}

int Books::GetStock()
{return stock;}

float Books::GetPrice()
{return price;}
