//-----------------SE1----------------------
//------------Ashwin Vaidya-----------------
//-------------202030-----------------------
#ifndef SPARSE_MATRIX
#define SPARSE_MATRIX

class SparseMatrix
{
int iRowNo, iColNo;
int iSpMatrix[10][10];
public:
	SparseMatrix();
	SparseMatrix sAdd(SparseMatrix);
	void vTranspose();
	void vFastTranspose();
	void vDisplay();
	void vInput();
	void vCompact(SparseMatrix);
};


#endif
