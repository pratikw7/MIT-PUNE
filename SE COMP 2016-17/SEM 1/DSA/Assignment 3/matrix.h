/*
 * matrix.h
 *
 *  Created on: 08-Jul-2016
 *      Author: student
 */

#ifndef MATRIX_H_
#define MATRIX_H_

class cMatrix {

	int iColSize, iRowSize;
	int iMatrixArray[10][10];

public:
	void vGetMatrixData();
	void vShowMatrixData();
	void vSumofDiagEle();
	inline bool bIsSquareMatirx();
	bool bIsUpperTriangular();
	cMatrix mTranspose();
	void mAdd();
	void mSubtract();
	void mMultiply();
	cMatrix();
	virtual ~cMatrix();
};

#endif /* MATRIX_H_ */
