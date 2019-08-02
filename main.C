#include <iostream>
using namespace std;

#include "Matrix.h"
#include "ConjugateGradient.h"

int main() {

	// Testing conjugateGradient

	Matrix A(3,3);
	A[0][0] = 5; A[0][1] = -2; A[0][2] = 0;
	A[1][0] = -2; A[1][1] = 5; A[1][2] = 1;
	A[2][0] = 0; A[2][1] = 1; A[2][2] = 5;

	Matrix b(3,1);
	b[0][0] = 20; b[1][0] = 10; b[2][0] = -10;

	Matrix x(3,1);
	x[0][0] = 0; x[1][0] = 0; x[2][0] = 0;

	double tol = 0.0;

	conjugateGradient(A, x, b, tol);

	A.print_matrix("A");
	b.print_matrix("b");
	x.print_matrix("x");

	return 0;
}





