/*
 * matrix.cpp
 *
 *  Created on: 08-Jul-2016
 *      Author: student
 */

#include "matrix.h"
#include <iostream>

using namespace std;

cMatrix::cMatrix() {
	iRowSize=0; iColSize=0;
for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
		  iMatrixArray[i][j] =0;
		}
	}
}

cMatrix::~cMatrix() {
}
void cMatrix::vGetMatrixData()
{
	cout<<"Enter the number of rows: ";
	cin>>iRowSize;
	cout<<"Enter the number of Columns: ";
	cin>>iColSize;
	for(int i=0; i<iRowSize; i++)
	{
		for(int j=0; j<iColSize; j++)
		{
		  cout<<"Element "<<i<<' '<<j<<" : ";
		  cin>>iMatrixArray[i][j];
		}
	}
}

void cMatrix::vShowMatrixData()
{
	for(int i=0; i<iRowSize; i++)
	{
		for(int j=0; j<iColSize; j++)
		{
		  cout<<iMatrixArray[i][j]<<' ';
		}
		cout<<endl;
	}
}

void cMatrix::vSumofDiagEle()
{
	int iSum1=0, iSum2=0;
	if(bIsSquareMatirx())
	{
	for(int i=0;i<iRowSize; i++)
		for(int j=0;j<iColSize; j++)
		{
			if(i==j)
			{
				iSum1 += iMatrixArray[i][j];
				iSum2 += iMatrixArray[(iRowSize-1)-i][(iColSize-1)-j];
			}
		}

	cout<<"Sum of diagonal 1 is: "<<iSum1<<endl;
	cout<<"Sum of diagonal 2 is: "<<iSum2<<endl;
	}
	else
	   cout<<"Error!The given matrix is not square matrix\n";
}

bool cMatrix::bIsUpperTriangular()
{
	if(!bIsSquareMatirx()){
		cout<<"Cannot be cumputed. Matrix is not a square Matrix\n";
		return false;
		}
	for(int i=0;i<iRowSize; i++)
		for(int j=0;j<iColSize; j++)
		{
			if(i>j)
				if(iMatrixArray[i][j]==0)
					return true;
		}

	return false;
}


cMatrix cMatrix::mTranspose()
{
	cMatrix mRet;
	int iRow = iColSize;
	int iCol = iRowSize;
	mRet.iRowSize = iRow;
	mRet.iColSize = iCol;
	for(int i=0; i<iRow; i++)
	{
		for(int j=0; j<iCol; j++)
		{
			mRet.iMatrixArray[i][j] =iMatrixArray[j][i] ;
		}
	}
return mRet;
}

void cMatrix::mAdd()
{
	cMatrix mRet,mB;
	mB.vGetMatrixData();
	if(iRowSize ==mB.iRowSize && iColSize == mB.iColSize)
	{
	int iRow = iRowSize;
	int iCol = iColSize;
	mRet.iColSize = iColSize;
	mRet.iRowSize = iRowSize;
	for(int i=0; i<iRow; i++)
	{
		for(int j=0; j<iCol; j++)
		{
			mRet.iMatrixArray[i][j] = iMatrixArray[i][j] +mB.iMatrixArray[i][j] ;
		}
	}
	cout<<"Sum of Matrix is:\n";
	mRet.vShowMatrixData();
	}
	else
		cout<<"Cannot add both the matrices. Their dimentions are different\n";
}

void cMatrix::mSubtract()
{
	cMatrix mRet,mB;
	mB.vGetMatrixData();
	if(iRowSize ==mB.iRowSize && iColSize == mB.iColSize)
	{
	int iRow = iRowSize;
	int iCol = iColSize;
	mRet.iColSize = iColSize;
	mRet.iRowSize = iRowSize;
	for(int i=0; i<iRow; i++)
	{
		for(int j=0; j<iCol; j++)
		{
			mRet.iMatrixArray[i][j] = iMatrixArray[i][j] -mB.iMatrixArray[i][j] ;
		}
	}
	cout<<"Difference of Matrix is:\n";
	mRet.vShowMatrixData();
	}
	else
		cout<<"Cannot subtract both the matrices. Their dimentions are different\n";
}
inline bool cMatrix::bIsSquareMatirx()
{
	if(iRowSize==iColSize)
		return true;
	return false;
}
void cMatrix::mMultiply()
{
	cMatrix mRet,mB;

	cout<<"Enter Matrix B:\n";
	mB.vGetMatrixData();
	if(iColSize == mB.iRowSize)
	{
	mRet.iColSize = mB.iColSize;
	mRet.iRowSize = iRowSize;
	for(int i=0;i<iRowSize;i++)
	{
		for(int j=0;j<mB.iColSize;j++)
	    {
	    	for(int k=0;k<iColSize;k++)
	    	{
	        	mRet.iMatrixArray[i][j] += iMatrixArray[i][k]*mB.iMatrixArray[k][j];
	        }
	    }
	}
	cout<<"Product of Matrix is:\n";
	mRet.vShowMatrixData();
	}
	else
		cout<<"Cannot Multiply both the matrices. Column of A does not match Row of Matrix B\n";
}
