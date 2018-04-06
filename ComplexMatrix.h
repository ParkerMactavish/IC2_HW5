#pragma once

#ifndef COMPLEXMATRIX_H
#define COMPLEXMATRIX_H

#include <iostream>
#include "Complex.h"
using namespace std;

/*
* ²�檺�x�}�ۥ[�M�ۭ�
*/

class ComplexMatrix {
private:
	Complex ** data;			// �@�ӤG����double�x�}
	int row;			// �x�sdata�@���X��row
	int col;			// �x�sdata�@���X��col
	void setUp(int, int);		// utility function, �]�wrow�Mcol����

public:
	ComplexMatrix();			// default constructor, ���򳣤���, �Ndata�s�J2*2���O0����
	ComplexMatrix(int, int);		// constructor, �u�]�w�j�p, ��ƹw�]��0
	ComplexMatrix(int, int, Complex[], int);// constructor, �N�ǤJ���@���}�C��s���G���}�C��Jdata��
	ComplexMatrix(const ComplexMatrix &);		// copy constructor
	~ComplexMatrix();			// destructor, �M�zdata

	void setData(int, int, Complex);	// �]�w��(r,c)��mdata����

	int getRow() const;		// �^��private member: row
	int getCol() const;		// �^��private member: col
	Complex getData(int, int) const;	// ����x�}(r,c)��m����

	ComplexMatrix operator+(const ComplexMatrix &);		// �x�}�ۥ[, �^�Ǭۥ[�᪺�x�}
	ComplexMatrix operator*(const ComplexMatrix &);	// �x�}�ۭ�, �^�Ǭۭ��ᤧ�x�}
	ComplexMatrix operator*(const double &);//�x�}���`��
	ComplexMatrix operator~();	// �x�}��m, �^����m�᪺�x�}
	friend ostream& operator<<(ostream&, const ComplexMatrix);//��X�x�}

};

#endif