# ConjugateGradient
C++ code for a conjugate gradient solver

This repository contains C++ code which implements a conjugate gradient iterative linear algebra solver.  Matrix.h/Matrix.C contain code for a matrix class, while ConjugateGradient.h/ConugateGradient.C contain code for the conjugate gradient implementation.  The following example is programmed into main.C:  Ax=b where A=[5 -2 0; -2 5 1; 0 1 5], b=[20 10 -10]', and x=[6 5 -3]'.  The code in this repository can be enhanced by adding in preconditioning capability and testing the timing of the code with large, sparse, symmetric, positive-definite matrices against Gaussian elimination.
