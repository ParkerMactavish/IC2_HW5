#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
	double tmp[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	Matrix a;
	Matrix b(10, 10);
	//Matrix c(10, 10, a);
	Matrix d(b);
	a.displayData();
	b.displayData();
	d.displayData();
	return 0;
}