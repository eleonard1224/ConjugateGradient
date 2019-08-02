
#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;


class Matrix
{
 private:
  int rows;
  int cols;
  double **Mat;


  public:
    Matrix (const int &rows,const int &cols);
    Matrix(const Matrix &other);
    ~Matrix ();
    double* & operator[](const int &index) const ;
    void operator=(const Matrix &other );
    Matrix  operator -()const;
    Matrix  operator -(const Matrix &other)const;
    Matrix  operator +(const Matrix &other)const ;
    Matrix  operator *(const Matrix &other)const;
    Matrix  operator *(const double &num)const;
    Matrix  transpose()const;
    double  mag()const;
    int getMatrixRows(const Matrix &other)const{return other.rows;}
    int getMatrixCols(const Matrix &other)const{return other.cols;}

    friend  Matrix operator *(const double & num,const Matrix &m)
    {
     return (m*num);
    }

    friend Matrix operator +(const double &num,const Matrix &t)
    {
     return (num+t);
    }

	// Prints the matrix Mat
	void print_matrix(string s);

	// Conversion from a matrix to double M[0][0]
	operator double() { return Mat[0][0]; } //conversion function

};

#endif /* MATRIX_H_ */
