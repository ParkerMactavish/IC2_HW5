#include "Matrix.h"

using namespace std;

Matrix::Matrix()
{
	setUp(2, 2);
	for (int rowCnt=0; rowCnt<row; rowCnt++)
		for (int colCnt=0; colCnt<col; colCnt++)
			setData(rowCnt, colCnt, 0);
}

Matrix::Matrix(int row, int col)
{
	setUp(row, col);
	for (int rowCnt=0; rowCnt<row; rowCnt++)
		for (int colCnt=0; colCnt<col; colCnt++)
			setData(rowCnt, colCnt, 0);
}

/*void Matrix::setData(int row, int col, double data, )
{
	
}*/

Matrix::Matrix(const Matrix& outer)
{
	this->row=outer.row;
	this->col=outer.col;
	setUp(this->row, this->col);
	for (int rowCnt=0; rowCnt<row; rowCnt++)
		for (int colCnt=0; colCnt<col; colCnt++)
			setData(rowCnt, colCnt, outer.getData(rowCnt, colCnt));
}

Matrix::~Matrix()
{
	for (int rowCnt=0; rowCnt<row; rowCnt++)
		delete [] data[rowCnt];
	delete [] data;
}

void Matrix::setUp(int row, int col)
{
	this->row=row;
	this->col=col;
	data = new double* [row];
	for(int rowCnt=0; rowCnt<row; rowCnt++)
	{		
		data[rowCnt]=new double [col];
	}	
}

void Matrix::setData(int row, int col, double data)
{
	this->data[row][col]=data;
}

int Matrix::getRow ()const{return this->row;}

int Matrix::getCol () const{return this->col;}

double Matrix::getData (int row, int col) const {return data[row][col];}

Matrix Matrix::add(const Matrix& adder)
{	
	if(this->row!=adder.getRow()||this->col!=adder.getCol())
	{
		cout<<"Error:Matrices size not equal "<<endl;
		Matrix sum(1, 1);
		return sum;
	}
	Matrix sum(this->row, this->col);
	for(int rowCnt=0; rowCnt<row; rowCnt++)
		for(int colCnt=0; colCnt<col; colCnt++)
			sum.setData(rowCnt, colCnt, this->getData(rowCnt, colCnt)+adder.getData(rowCnt, colCnt));
		
	return sum;
}


/*Matrix Matrix::multiply(Matrix& mutiplier)
{
	if(this->row!=adder.getRow()||this->col!=adder.getCol())
	{
		cout<<"Error:Multiplicand's row number and multiplier's col number not equal"<<endl;
		Matrix sum(1, 1);
		return sum;
	}
	Matrix product(this->);
	for(int rowCnt=0; rowCnt<row; rowCnt++)
		for(int colCnt=0; colCnt<col; colCnt++)
			sum.setData(rowCnt, colCnt, this->getData(rowCnt, colCnt)+adder.getData(rowCnt, colCnt));
		
	return sum;
}*/
