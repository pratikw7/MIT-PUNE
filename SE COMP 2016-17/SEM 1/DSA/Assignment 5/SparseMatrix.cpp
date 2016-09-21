//-----------------SE1----------------------
//------------Ashwin Vaidya-----------------
//-------------202030-----------------------
#include "SparseMatrix.h"
#include <iostream>
using namespace std;

SparseMatrix::SparseMatrix()
{
	iRowNo = 0, iColNo=0;
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++)
			iSpMatrix[i][j]=0;
}

SparseMatrix SparseMatrix::sAdd(SparseMatrix sOther)
{
	SparseMatrix ret;
	if(iSpMatrix[0][0] != sOther.iSpMatrix[0][0] && iSpMatrix[0][1] != sOther.iSpMatrix[0][1])
	{
	cout<<"Orders of the two matrices do not match!";
	return ret;
	}
	else
	{
	ret.iSpMatrix[0][0]=iSpMatrix[0][0];
	ret.iSpMatrix[0][1]=iSpMatrix[0][1];
	int i=1, j=1, k=1;
	while(i<=iSpMatrix[0][2]&&j<=sOther.iSpMatrix[0][2])
	   {
		if(iSpMatrix[i][0]==sOther.iSpMatrix[j][0])
		{
		if(iSpMatrix[i][1]==sOther.iSpMatrix[j][1])
			{
			ret.iSpMatrix[k][0] = iSpMatrix[i][0];
			ret.iSpMatrix[k][1] = iSpMatrix[i][1];
			ret.iSpMatrix[k][2] = iSpMatrix[i][2]+sOther.iSpMatrix[j][2];
			i++;j++;k++;
			}
		else if(iSpMatrix[i][1]<sOther.iSpMatrix[j][1])
			{
			ret.iSpMatrix[k][2] = iSpMatrix[i][2];
			ret.iSpMatrix[k][0] = iSpMatrix[i][0];
			ret.iSpMatrix[k][1] = iSpMatrix[i][1];
			i++;k++;
			}
		else if(iSpMatrix[i][1]>sOther.iSpMatrix[j][1])
			{
			ret.iSpMatrix[k][2] = sOther.iSpMatrix[j][2];
			ret.iSpMatrix[k][0] = sOther.iSpMatrix[j][0];
			ret.iSpMatrix[k][1] = sOther.iSpMatrix[j][1];
			j++;k++;
			}
		}
		else if(iSpMatrix[i][0]<sOther.iSpMatrix[j][0])
		{
		ret.iSpMatrix[k][2] = iSpMatrix[i][2];
		ret.iSpMatrix[k][0] = iSpMatrix[i][0];
		ret.iSpMatrix[k][1] = iSpMatrix[i][1];
		i++;k++;
		}
		else if(iSpMatrix[i][0]>sOther.iSpMatrix[j][0])
		{
		ret.iSpMatrix[k][2] = sOther.iSpMatrix[j][2];
		ret.iSpMatrix[k][0] = sOther.iSpMatrix[j][0];
		ret.iSpMatrix[k][1] = sOther.iSpMatrix[j][1];
		j++;k++;
		}
	   }
	   while(i<=iSpMatrix[0][2])
	   {
			ret.iSpMatrix[k][2] = iSpMatrix[i][2];
			ret.iSpMatrix[k][0] = iSpMatrix[i][0];
			ret.iSpMatrix[k][1] = iSpMatrix[i][1];
			i++;k++;
	   }
	   while(j<=sOther.iSpMatrix[0][2])
	   {
			ret.iSpMatrix[k][2] = sOther.iSpMatrix[j][2];
			ret.iSpMatrix[k][0] = sOther.iSpMatrix[j][0];
			ret.iSpMatrix[k][1] = sOther.iSpMatrix[j][1];
			j++;k++;
	   }
	  ret.iSpMatrix[0][2] = k;
	  ret.iRowNo = k;
	  ret.iColNo = 3;
	  return ret;                                                                                          
	}
}
void SparseMatrix::vTranspose()
{
	SparseMatrix ret;
	ret.iSpMatrix[0][0]= iSpMatrix[0][1];
	ret.iSpMatrix[0][1]= iSpMatrix[0][0];
	ret.iSpMatrix[0][2]= iSpMatrix[0][2];
	int k=1;
	for(int j=0; j<iSpMatrix[0][1]; j++)
	{
		for(int i=0; i<iRowNo; i++)
			if(iSpMatrix[i][1]==j)
			{
				ret.iSpMatrix[k][0]= iSpMatrix[i][1];
				ret.iSpMatrix[k][1]= iSpMatrix[i][0];
				ret.iSpMatrix[k][2]= iSpMatrix[i][2];
				k++;
			}
	}
	ret.iRowNo=k;
	ret.iColNo=3;
	ret.vDisplay();
}
void SparseMatrix::vFastTranspose()
{
	SparseMatrix ret;
		int strrow[6],ntrow[15];
		int i,j;
		ret.iRowNo=iRowNo;
		ret.iColNo=iColNo;
		ret.iSpMatrix[0][0]=iSpMatrix[0][1];
		ret.iSpMatrix[0][1]=iSpMatrix[0][0];
		ret.iSpMatrix[0][2]=iSpMatrix[0][2];
		if(iSpMatrix[0][2]>0)
		{
			for(i=0;i<iSpMatrix[0][2];i++)
			{
				ntrow[i]=0;
			}

			for(i=1;i<=iSpMatrix[0][2];i++)
			{
				ntrow[iSpMatrix[i][1]]=ntrow[iSpMatrix[i][1]]+1;
			}
			strrow[0]=1;
			for(i=1;i<iColNo;i++)
			{
				strrow[i]=strrow[i-1]+ntrow[i-1];
			}

			for(i=1;i<=iSpMatrix[0][2];i++)
			{
				j=strrow[iSpMatrix[i][1]];
				ret.iSpMatrix[j][0]=iSpMatrix[i][1];
				ret.iSpMatrix[j][1]=iSpMatrix[i][0];
				ret.iSpMatrix[j][2]=iSpMatrix[i][2];
				strrow[iSpMatrix[i][1]]=strrow[iSpMatrix[i][1]]+1;
			}
			ret.vDisplay();
		}
	
}
void SparseMatrix::vDisplay()
{
	cout<<"Matrix is: \n";
	for(int i=0; i<iRowNo; i++)
	{
		for(int j=0; j<iColNo; j++)
			cout<<iSpMatrix[i][j]<<"\t";
		cout<<endl;
	}
}
void SparseMatrix::vInput()
{
	cout<<"Enter number of rows of Original Matrix: ";
	cin>>iRowNo;
	cout<<"Enter number of coloumns of Original Matrix: ";
	cin>>iColNo;
	cout<<"Enter the matrix in row major form: "<<endl;
	for(int i=0; i<iRowNo; i++)
		for(int j=0; j<iColNo; j++)
				cin>>iSpMatrix[i][j];
}
void SparseMatrix::vCompact(SparseMatrix sOther)
{
	int k=1;
	iSpMatrix[0][0] = sOther.iRowNo;
	iSpMatrix[0][1] = sOther.iColNo;
	for(int i=0; i<sOther.iRowNo; i++)
	{
		
		for(int j=0; j<sOther.iColNo; j++)
		{
			if(sOther.iSpMatrix[i][j]!=0)
			{
				iSpMatrix[k][0] = i;
				iSpMatrix[k][1] = j;
				iSpMatrix[k][2] = sOther.iSpMatrix[i][j];
				k++;
			}
		}
	}
	iSpMatrix[0][2] = k-1;
	iRowNo = k;
	iColNo = 3;
}
