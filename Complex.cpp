#include "Complex.h"
#include <iostream>

using namespace std;

Complex::Complex()
{
	Real = 0; Imag = 0;
}

Complex::Complex(const Complex& Outer)
{
	this->Real = Outer.Real;
	this->Imag = Outer.Imag;
}

Complex::Complex(double Real, double Imag)
{
	this->Real = Real;
	this->Imag = Imag;
}

Complex::~Complex(){}

Complex Complex::operator+(const Complex& rhs)
{
	Complex Result(this->Real + rhs.Real, this->Imag + rhs.Imag);
	return Result;
}

Complex Complex::operator+(const double& rhs)
{
	Complex Result;
	Result.Real = this->Real + rhs;
	Result.Imag = this->Real;
	return Result;
}

Complex operator+(const double& lhs, const Complex& rhs)
{
	Complex Result(rhs.Real + lhs, rhs.Imag);
	return Result;
}

bool Complex::operator=(const Complex& rhs)
{
	this->Real = rhs.Real;
	this->Imag = rhs.Imag;
	return 0;
}

bool Complex::operator=(const double rhs[])
{
	this->Real = rhs[0];
	this->Imag = rhs[1];
	return 0;
}

Complex Complex::operator+=(const Complex& rhs)
{
	this->Real += rhs.Real;
	this->Imag += rhs.Imag;
	return *this;
}

Complex Complex::operator*(const Complex& rhs)
{
	Complex Result;
	Result.Real = this->Real*rhs.Real - this->Imag*rhs.Imag;
	Result.Imag = this->Imag*rhs.Real + this->Real*rhs.Imag;
	return Result;
}

Complex Complex::operator*(const double& rhs)
{
	Complex Result(this->Real * rhs, this->Imag * rhs);
	return Result;
}

Complex operator*(const double& lhs, const Complex& rhs)
{	
	Complex Result(rhs.Real * lhs, rhs.Imag * lhs);
	return Result;
}

Complex Complex::operator*=(const Complex& rhs)
{
	Complex Result;
	Result.Real = this->Real*rhs.Real - this->Imag*rhs.Imag;
	Result.Imag = this->Imag*rhs.Real + this->Real*rhs.Imag;
	return Result;
}

Complex Complex::operator*=(const double& rhs)
{
	this->Real *= rhs;
	this->Imag *= rhs;
	return *this;
}

ostream& operator <<(ostream& Out, const Complex & Content)
{
	Out << Content.Real << "+" << Content.Imag << "i";
	return Out;
}