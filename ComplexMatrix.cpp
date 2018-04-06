#include "ComplexMatrix.h"
#include "Complex.h"
#include <iostream>

using namespace std;

void ComplexMatrix::setUp(int row, int col)//set up the row and col number, and altogether set up a matrix of size row * col
{
	this->row = row;
	this->col = col;
	data = new Complex*[row];
	for (int rowCnt = 0; rowCnt<row; rowCnt++)
	{
		data[rowCnt] = new Complex[col];
	}
}

ComplexMatrix::ComplexMatrix()//set up the simpliest matrix with a 2*2 size and all 0's in content
{
	setUp(2, 2);
	Complex TmpComplex;
	for (int rowCnt = 0; rowCnt<row; rowCnt++)
		for (int colCnt = 0; colCnt<col; colCnt++)
			setData(rowCnt, colCnt, TmpComplex);
}

ComplexMatrix::ComplexMatrix(int row, int col)//set up a simple matrix with a row*col size and all 0's in content
{
	setUp(row, col);
	Complex TmpComplex;
	for (int rowCnt = 0; rowCnt<row; rowCnt++)
		for (int colCnt = 0; colCnt<col; colCnt++)
			setData(rowCnt, colCnt, TmpComplex);
}

ComplexMatrix::ComplexMatrix(int row, int col, Complex data[], int length)//set up a 2d matrix with a 1d array with row*col size
{
	if (length != row * col) cout << "Error:The length of the one-dimentional array is wrong.";
	else
	{
		setUp(row, col);
		for (int rowCnt = 0; rowCnt < row; rowCnt++)
			for (int colCnt = 0; colCnt < col; colCnt++)
				setData(rowCnt, colCnt, data[rowCnt*col + colCnt]);
	}
}

ComplexMatrix::ComplexMatrix(const ComplexMatrix& outer)//copy the 2d matrix from another
{
	this->row = outer.row;
	this->col = outer.col;
	setUp(this->row, this->col);
	for (int rowCnt = 0; rowCnt<row; rowCnt++)
		for (int colCnt = 0; colCnt<col; colCnt++)
			setData(rowCnt, colCnt, outer.getData(rowCnt, colCnt));
}

ComplexMatrix::~ComplexMatrix()//delete all storages that the matrix uses
{
	for (int rowCnt = 0; rowCnt<row; rowCnt++)
		delete[] data[rowCnt];
	delete[] data;
}



void ComplexMatrix::setData(int row, int col, Complex data)//set the element at (row, col) as data and check the validity first
{
	if (row < this->row&&col < this->col&&row >= 0 && col >= 0)
	{
		this->data[row][col] = data;
	}
	else if (row >= this->row || row < 0) cout << "Error:Row number out of range.";
	else if (col >= this->col || col < 0) cout << "Error:Col number out of range.";
}

int ComplexMatrix::getRow()const { return this->row; }//get the row number

int ComplexMatrix::getCol() const { return this->col; }//get the col number

Complex ComplexMatrix::getData(int row, int col) const //get the element at (row, col) and check the validity first
{
	if (row < this->row&&col < this->col&&row >= 0 && col >= 0) return data[row][col];
	else if (row >= this->row || row < 0) cout << "Row number out of range.";
	else if (col >= this->col || col < 0) cout << "Col number out of range.";
}

ComplexMatrix ComplexMatrix::operator+(const ComplexMatrix& rhs)//check if the sizes of two matrixes are the same and add all elements afterward
{
	if (this->row != rhs.getRow() || this->col != rhs.getCol())
	{
		cout << "Error:Matrices size not equal " << endl;
		ComplexMatrix Sum(1, 1);
		return Sum;
	}
	ComplexMatrix Sum(this->row, this->col);
	for (int rowCnt = 0; rowCnt<this->row; rowCnt++)
		for (int colCnt = 0; colCnt<this->col; colCnt++)
			Sum.setData(rowCnt, colCnt, this->getData(rowCnt, colCnt) + rhs.getData(rowCnt, colCnt));

	return Sum;
}


ComplexMatrix ComplexMatrix::operator*(const ComplexMatrix& Multiplier)//Do the matrix multiplication
{
	if (this->col != Multiplier.row)
	{
		cout << "Error:Matrices can't be multiplied due to size issue." << endl;
		ComplexMatrix Product(1, 1);
		return Product;
	}
	ComplexMatrix Product(this->row, Multiplier.col);
	for (int prodRowCnt = 0; prodRowCnt < Product.row; prodRowCnt++)
	{
		for (int prodColCnt = 0; prodColCnt < Product.col; prodColCnt++)
		{
			Complex TmpElem;
			for (int innerCnt = 0; innerCnt < this->col; innerCnt++)
			{
				TmpElem += this->data[prodRowCnt][innerCnt] * Multiplier.data[innerCnt][prodColCnt];
			}
			Product.setData(prodRowCnt, prodColCnt, TmpElem);
		}
	}
	return Product;
}

ComplexMatrix ComplexMatrix::operator*(const double & rhs)//multiplied by a constant number
{
	ComplexMatrix Product(this->row, this->col);
	for (int rowCnt = 0; rowCnt < this->row; rowCnt++)
	{
		for (int colCnt = 0; colCnt < this->col; colCnt++)
		{
			Product.data[rowCnt][colCnt]=this->data[rowCnt][colCnt] * rhs;
		}
	}
	return Product;
}

ComplexMatrix ComplexMatrix::operator~()//Transpose the matrix
{
	ComplexMatrix Result(this->col, this->row);
	for (int rowCnt = 0; rowCnt < this->row; rowCnt++)
	{
		for (int colCnt = 0; colCnt < this->col; colCnt++)
		{
			Result.setData(colCnt, rowCnt, this->getData(rowCnt, colCnt));
		}
	}
	return Result;
}

ostream& operator<<(ostream& Out, const ComplexMatrix rhs)//for cout<<ComplexMatrix
{
	for (int i = 0; i<rhs.row; i++) {
		for (int j = 0; j<rhs.col; j++) {
			cout << rhs.data[i][j] << "\t";
		}
		cout << "" << endl;
	}
	return Out;
}