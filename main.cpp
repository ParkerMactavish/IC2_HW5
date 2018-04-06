#include <iostream>
#include <cstdlib>
#include "Matrix.h"
#include "Complex.h"
#include "ComplexMatrix.h"

using namespace std;

int main()
{
	//Complex Matrix Test
	Complex tmp3[6] = { {1, 1}, {1, 2}, {2, 1}, {2, 2}, {2, 3}, {3, 2} };//Complex Array
	Complex tmp4[6] = { {0, 1}, {0, 2}, {0, 3}, {0, 4} , {0, 5}, {0, 6} };//Complex Array
	ComplexMatrix e(3, 2, tmp3, 6);//ComplexMatrix Declaration
	ComplexMatrix f(2, 3, tmp4, 6);//ComplexMatrix Declaration
	cout << e << endl << f << endl;
	cout << e + e << endl;
	cout << e * f << endl;
	cout << e * 2 << endl;
	cout << ~(e*f) << endl;

	system("PAUSE");
	return 0;
}