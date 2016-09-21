#include  <iostream>
#include "book.h"
#include "tape.h"
using namespace std;


int main()
{
	int maxB, maxT, countB=0, countT=0;
	cout<<"Enter total number of books:\n";
	cin>>maxB;
	Book b[maxB];
	cout<<"Enter total number of audiocasets:\n";
	cin>>maxT;
	Tape t[maxT];
	char inp;
	do{
		cout<<"1. Add book to store:\n";
		cout<<"2. Add audiocasset to store:\n";
		cout<<"3. Display the items in store:\n";
		cin>>inp;
		switch(inp)
		{
		case '1':
			if(countB<maxB)
			{
			b[countB].getData();
			countB++;
			}
			else
				cout<<"Overflow!\n";
			break;
		case '2':
			if(countT<maxT)
						{
			t[countT].getData();
			countT++;
						}
			else
				cout<<"Overflow!\n";
			break;
		case '3':
			cout<<"\tTitle\t\tPrice\t\tPage Numbers\n";
			if(countB==0)
				cout<<"-------Empty------\n";
			else{
			for(int i=0; i<countB; i++)
				b[i].showData();
			}
			cout<<"\tTitle\t\tPrice\t\tPlayback time(mins)\n";
			if(countT==0)
							cout<<"-------Empty------\n";
						else{
			for(int i=0; i<countT; i++)
					t[i].showData();
						}
			break;
		default:
			break;
		}
		cout<<"Do you want to continue?(y)";
		cin>>inp;
	}while(inp == 'y');
	return 0;
}
/*------------OUTPUT-----------------------
 Enter total number of books:
3
Enter total number of audiocasets:
3
1. Add book to store:
2. Add audiocasset to store:
3. Display the items in store:
3
	Title		Price		Page Numbers
-------Empty------
	Title		Price		Playback time(mins)
-------Empty------
Do you want to continue?(y)y
1. Add book to store:
2. Add audiocasset to store:
3. Display the items in store:
1
Enter the number of pages:
300
Enter title of book:
sdfg
Enter the price of book:
345
Do you want to continue?(y)y
1. Add book to store:
2. Add audiocasset to store:
3. Display the items in store:
1
Enter the number of pages:
1000
Enter title of book:
asdf
Enter the price of book:
0
Error occurred
Error handled
Do you want to continue?(y)y
1. Add book to store:
2. Add audiocasset to store:
3. Display the items in store:
1
Enter the number of pages:
1002
Error occurred
Error handled
Do you want to continue?(y)y
1. Add book to store:
2. Add audiocasset to store:
3. Display the items in store:
 3
	Title		Price		Page Numbers
	sdfg		345		300	Type: Book
			0		0	Type: Book
			0		0	Type: Book
	Title		Price		Playback time(mins)
-------Empty------
Do you want to continue?(y)y
1. Add book to store:
2. Add audiocasset to store:
3. Display the items in store:
2
Enter the play time (mm.ss):
34.9
Error occured
Error handled
Do you want to continue?(y)y
1. Add book to store:
2. Add audiocasset to store:
3. Display the items in store:
2
Enter the play time (mm.ss):
32.55
Enter title of tape:
asdfg
Enter the price of tape:
0
Error occurred
Error handled
Do you want to continue?(y)y
1. Add book to store:
2. Add audiocasset to store:
3. Display the items in store:
3
	Title		Price		Page Numbers
	sdfg		345		300	Type: Book
			0		0	Type: Book
			0		0	Type: Book
	Title		Price		Playback time(mins)
			0		0	Type: Tape
			0		0	Type: Tape
Do you want to continue?(y)y
1. Add book to store:
2. Add audiocasset to store:
3. Display the items in store:
2
Enter the play time (mm.ss):
34.6
Enter title of tape:
asdf
Enter the price of tape:
234
Do you want to continue?(y)y
1. Add book to store:
2. Add audiocasset to store:
3. Display the items in store:
3
	Title		Price		Page Numbers
	sdfg		345		300	Type: Book
			0		0	Type: Book
			0		0	Type: Book
	Title		Price		Playback time(mins)
			0		0	Type: Tape
			0		0	Type: Tape
	asdf		234		34.6	Type: Tape
Do you want to continue?(y)y
1. Add book to store:
2. Add audiocasset to store:
3. Display the items in store:
1
Overflow!
Do you want to continue?(y)y
1. Add book to store:
2. Add audiocasset to store:
3. Display the items in store:
1
Overflow!
Do you want to continue?(y)


 */
