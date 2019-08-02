// Definition of the conjugate gradient method

#include "ConjugateGradient.h"


// Implements the conjugate gradient algorithm for solving A*x = b
void conjugateGradient(const Matrix& A, Matrix& x, const Matrix& b, double tol) {

	int k;
	int n = A.getMatrixRows(A);

	Matrix r(n,1);
	Matrix r0(n,1);
	Matrix d(n,1);
	double s;
	double c;

	r0 = b - A*x;
	d = r0;
	k = 1;

	while(k <= n) {

		s = (r0.transpose()*r0)/(d.transpose()*A*d);
		x = x + d*s;
		r = r0 - A*d*s;

		if(r.mag() <= tol) {
			return;
		}

		c = (r.transpose()*r)/(r0.transpose()*r0);
		d = r + d*c;
		r0 = r;

		k += 1;
	}
}




