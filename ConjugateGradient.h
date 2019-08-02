// Declaration of the conjugate gradient method

#ifndef CONJUGATEGRADIENT_H_
#define CONJUGATEGRADIENT_H_

#include "Matrix.h"


// Implements the conjugate gradient algorithm for solving Ax = b
void conjugateGradient(const Matrix& A, Matrix& x, const Matrix& b, double tol);




#endif /* CONJUGATEGRADIENT_H_ */
