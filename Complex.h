#pragma once
#include <cstdlib>
#include <iostream>
#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;

class Complex
{
public:
	Complex();//normal constructor with 0+0i
	Complex(const Complex&);//copy constructor
	Complex(double, double);//construc with a+bi
	~Complex();//destructor(no use)
	
	Complex operator+(const Complex&);//operator Complex+Complex
	Complex operator+(const double&);//operator Complex+double
	friend Complex operator+(const double&, const Complex&);//operator double+Complex
	bool operator=(const Complex&);//operator= with rhs is a Complex
	bool operator=(const double[]);//operator= with rhs is a {a, b} array
	Complex operator+=(const Complex&);//operator+=
	Complex operator*(const Complex&);//operator Matrix*Matrix
	Complex operator*(const double&);//operato Matrix*double
	friend Complex operator*(const double&, const Complex&);//operator double*Matrix
	Complex operator*=(const Complex&);//operator*= Matrix
	Complex operator*=(const double&);//operator*=double

	friend ostream& operator<<(ostream&, const Complex&);//operator <<

private:
	double Real;
	double Imag;
};

#endif 
