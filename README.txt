About Matrix.h & Matrix.cpp:
	Matrix.h is not modified sinced downloaded from moodle, and Matrix.cpp is following the Matrix.h.

About Complex.h & Complex.cpp:
	To make the feature of complex matrix, I use these two files to make the object called Complex. We'll later see it in main.cpp.
	By the way, in main.cpp you may see a usage:
		
		Complex tmp4[6] = { {0, 1}, {0, 2}, {0, 3}, {0, 4} , {0, 5}, {0, 6} };//Complex Array

	That is a way to decalre a complex array by using a two dimensional array with the size of 2*m, as you want to declare a complex array with m complexes.
	For another example, you can declare a complex array like:

		Complex tmp[4]={{1, 0}, {2, 0}, {3, 0}, {4, 0}};
	
	*Please DO NOT try:

		Complex tmp={1, 2, 3};

	or:

		Complex tmp={1};

	Due to the fact that I haven't write any kind of error detection with the size of array passed in, this kind of declaration may cause the error of subscript out of range.

About ComplexMatrix.h & ComplexMatrix.cpp:
	Though I want to combine the RealMatrix(the original Matrix.h & Matrix.cpp) and the ComplexMatrix together by overloading, yet it might be way too "complex".
	Besides, the original Matrix.h doesn't support operator overloading; thus, I make the file to accomplish the feature of matrix containing complex.
	
	Except for the last constuctor:
		
		ComplexMatrix(int, int, Complex[], int);// constructor, 將傳入的一維陣列轉存為二維陣列放入data中

	The user need to feed a complex array in the third argument.
	Everything else is just like the way in Matrix.h.


About main.cpp:
	I tested the +/*/~(transpose)/<<(streaming output) operator with two complex matrix e and f.
	Please add matrix and test the operation at will.