#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	cMatrix mA,mRet;
	mA.vGetMatrixData();
	char inp;
	do
	{
		cout<<"1. Check whether given matrix is upper triangular or not\n";
		cout<<"2. Compute summation of diagonal elements\n";
		cout<<"3. Compute transpose of matrix\n";
		cout<<"4. Add a Matrix to it\n";
		cout<<"5. Subtract a Matrix to it\n";
		cout<<"6. Multiply a Matrix to it\n";
		cout<<"Matrix A\n";
		mA.vShowMatrixData();
		cin>>inp;
		switch (inp)
		{
			case '1':
			if(mA.bIsUpperTriangular())
				cout<<"The given Matrix is upper triangular.\n";
			else
				cout<<"The given Matrix is not upper triangular.\n";
			break;
			case '2':
			cout<<"Sum of diagonal elements is: "<<endl;
			mA.vSumofDiagEle();
			break;
			case '3':
			cout<<"Transpose is: \n";
			mRet = mA.mTranspose();
			mRet.vShowMatrixData();
			break;
			case '4':
			cout<<"Enter Matrix B: "<<endl;
			mA.mAdd();
			break;
			case '5':
			cout<<"Enter Matrix B: "<<endl;
			mA.mSubtract();
			break;
			case '6':
			mA.mMultiply();
			break;
			default :
			cout<<"Enter a valid option\n";

		}
		cout<<"Do you want to continue? (y)";	
		cin>>inp;
	}while(inp=='y');
	return 0;
}
