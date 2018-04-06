#pragma once

#ifndef COMPLEXMATRIX_H
#define COMPLEXMATRIX_H

#include <iostream>
#include "Complex.h"
using namespace std;

/*
* 簡單的矩陣相加和相乘
*/

class ComplexMatrix {
private:
	Complex ** data;			// 一個二維的double矩陣
	int row;			// 儲存data共有幾個row
	int col;			// 儲存data共有幾個col
	void setUp(int, int);		// utility function, 設定row和col的值

public:
	ComplexMatrix();			// default constructor, 什麼都不傳, 將data存入2*2都是0的值
	ComplexMatrix(int, int);		// constructor, 只設定大小, 資料預設為0
	ComplexMatrix(int, int, Complex[], int);// constructor, 將傳入的一維陣列轉存為二維陣列放入data中
	ComplexMatrix(const ComplexMatrix &);		// copy constructor
	~ComplexMatrix();			// destructor, 清理data

	void setData(int, int, Complex);	// 設定第(r,c)位置data的值

	int getRow() const;		// 回傳private member: row
	int getCol() const;		// 回傳private member: col
	Complex getData(int, int) const;	// 拿到矩陣(r,c)位置的值

	ComplexMatrix operator+(const ComplexMatrix &);		// 矩陣相加, 回傳相加後的矩陣
	ComplexMatrix operator*(const ComplexMatrix &);	// 矩陣相乘, 回傳相乘後之矩陣
	ComplexMatrix operator*(const double &);//矩陣乘常數
	ComplexMatrix operator~();	// 矩陣轉置, 回傳轉置後的矩陣
	friend ostream& operator<<(ostream&, const ComplexMatrix);//輸出矩陣

};

#endif