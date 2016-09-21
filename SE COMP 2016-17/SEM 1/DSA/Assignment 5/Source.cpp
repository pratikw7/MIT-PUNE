//-----------------SE1----------------------
//------------Ashwin Vaidya-----------------
//-------------202030-----------------------
#include <iostream>
#include "SparseMatrix.h"

using namespace std;

int main()
{
	char inp;
	SparseMatrix a,b,c,d,e;
	a.vInput();
	a.vDisplay();
	b.vCompact(a);
	b.vDisplay();
	do{
		cout<<"1. Add a matrix to it.\n";
		cout<<"2. Transpose matrix.\n";
		cout<<"3. Fast transpose matrix.\n";
	cin>>inp;
	switch(inp)
	{
	case '1':
		cout<<"Enter matrix you want to add:\n";
		c.vInput();
		cout<<"Original second ";
		c.vDisplay();
		d.vCompact(c);
		cout<<"Compact second ";
		d.vDisplay();
		e = b.sAdd(d);
		cout<<"The sum is:\n";
		e.vDisplay();
		break;
	case '2':
		cout<<"Original ";
		a.vDisplay();
		cout<<"Sparse ";
		b.vDisplay();
		cout<<"Transpose ";
		b.vTranspose();
		break;
	case '3':
		cout<<"Original ";
		a.vDisplay();
		cout<<"Sparse ";
		b.vDisplay();
		cout<<"Transpose ";
		b.vFastTranspose();
		break;
	}
	cout<<"Do you want to continue?(y)";
	cin>>inp;
	}while(inp=='y');
	
	return 0;
}
//---------------Output--------------------------------
Enter number of rows of Original Matrix: 3
Enter number of coloumns of Original Matrix: 3
Enter the matrix in row major form: 
1
0
0
4
0
-3
0
0
1
Matrix is: 
1	0	0	
4	0	-3	
0	0	1	
Matrix is: 
3	3	4	
0	0	1	
1	0	4	
1	2	-3	
2	2	1	
1. Add a matrix to it.
2. Transpose matrix.
3. Fast transpose matrix.
2
Original Matrix is: 
1	0	0	
4	0	-3	
0	0	1	
Sparse Matrix is: 
3	3	4	
0	0	1	
1	0	4	
1	2	-3	
2	2	1	
Transpose Matrix is: 
3	3	4	
0	0	1	
0	1	4	
2	1	-3	
2	2	1	
Do you want to continue?(y)y
1. Add a matrix to it.
2. Transpose matrix.
3. Fast transpose matrix.
3
Original Matrix is: 
1	0	0	
4	0	-3	
0	0	1	
Sparse Matrix is: 
3	3	4	
0	0	1	
1	0	4	
1	2	-3	
2	2	1	
Transpose Matrix is: 
3	3	4	
0	0	1	
0	1	4	
2	1	-3	
2	2	1	
Do you want to continue?(y)y
1. Add a matrix to it.
2. Transpose matrix.
3. Fast transpose matrix.
1
Enter matrix you want to add:
Enter number of rows of Original Matrix: 3
Enter number of coloumns of Original Matrix: 3
Enter the matrix in row major form: 
4
-9
0
0
0
0
3
0
0
Original second Matrix is: 
4	-9	0	
0	0	0	
3	0	0	
Compact second Matrix is: 
3	3	3	
0	0	4	
0	1	-9	
2	0	3	
The sum is:
Matrix is: 
3	3	7	
0	0	5	
0	1	-9	
1	0	4	
1	2	-3	
2	0	3	
2	2	1	
Do you want to continue?(y)n

