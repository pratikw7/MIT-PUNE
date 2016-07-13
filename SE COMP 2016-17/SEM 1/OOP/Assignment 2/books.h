#ifndef Books_H
#define BOOKS_H

#include <string>
using namespace std;
class Books
{
private:
	char *Author, *Title, *Publisher;
	int stock;
	float price;

public:
	Books(int size);
	~Books();	
	char* GetAuthor();
	char* GetTitle();
	int GetStock();
	float GetPrice();
	void GetData();
	void ShowData();

};

#endif
