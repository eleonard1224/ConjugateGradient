
#include <iostream>
#include <cassert>
#include "Matrix.h"


Matrix::Matrix(const int &n_rows,const int &n_cols )//constructor of class Matrix
{
    rows=n_rows;
    cols=n_cols;
    Mat=new double* [cols];
    assert(Mat);
    for(int i =0;i<rows;i++)
    {
       Mat[i]=new double[cols];
       assert(Mat[i]);
    }
    for(int i=0;i<rows;i++)
      for(int j=0;j<cols;j++)
        Mat[i][j]=0;
}




 Matrix::Matrix(const Matrix &other)  //copy constructor
{
    cols=other.cols;
    rows=other.rows;
    Mat=new double* [other.rows];
    assert(Mat);
    for(int i =0;i<other.rows;i++)
    {
       Mat[i]=new double[other.cols];
       assert(Mat[i]);
    }
    for(int i=0;i<other.rows;i++)
      for(int j=0;j<other.cols;j++)
            Mat[i][j]=other[i][j];
}





double* & Matrix::operator [](const int &index) const  // overloading operator []
{
  return  Mat [index];
}



void Matrix::operator=(const Matrix &other )   // overloading operator =
{
    if(Mat !=other.Mat && cols==other.cols && rows==other.rows)
     {
       for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            Mat[i][j]=other.Mat[i][j];
     }
}





 Matrix  Matrix::operator-()const   // overloading operator -
{
    Matrix temp(rows,cols);
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            temp.Mat[i][j]=Mat[i][j]*-1;
   return temp;
}


 Matrix  Matrix::operator +(const Matrix &other)const  //add 2 matrix
{
    Matrix temp(rows,cols);
    if (rows!=other.rows ||cols!=other.cols)
    {
       for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            temp.Mat[i][j]=Mat[i][j];
       return temp;
    }
    else
     {
         for(int i=0;i<rows;i++)
             for(int j=0;j<cols;j++)
                 temp.Mat[i][j]+=other.Mat[i][j]+Mat[i][j];
     }
    return temp;
}





Matrix  Matrix::operator *(const Matrix &other)const   //multiply matrix on the right
{
      Matrix temp(rows,other.cols);
      for(int i=0;i<rows;i++)
          for(int j=0;j<other.cols;j++)
            for(int k =0;k<cols;k++)
                temp[i][j]+=Mat[i][k]*other.Mat[k][j];
      return temp;

}




Matrix  Matrix::operator *(const double &num)const   //multiply with number
{
    Matrix temp(rows,cols);
    for(int i=0;i<rows;i++)
       for(int j=0;j<cols;j++)
            temp.Mat[i][j]=Mat[i][j]*num;
    return temp;
}

Matrix  Matrix::operator -(const Matrix &other)const //matrix subtraction
{
    Matrix temp(rows,cols);
    if (rows!=other.rows ||cols!=other.cols)
    {
       for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            temp.Mat[i][j]=Mat[i][j];
       return temp;
    }
    else
     {

         for(int i=0;i<rows;i++)
             for(int j=0;j<cols;j++)
                 temp.Mat[i][j]+=Mat[i][j]-other.Mat[i][j];
     }
    return temp;
}

// Prints the matrix Mat
void Matrix::print_matrix(string s) {

	int n_rows = rows;
	int n_columns = cols;

	for(int i = 0; i < n_rows; i++) {
		for(int j = 0; j < n_columns; j++) {
			cout << s << "[" << i << "][" << j << "] = " << Mat[i][j] << endl;
		}
	}

}

Matrix Matrix::transpose()const
{

	int i, j;
	int n_rows = rows;
	int n_columns = cols;

	Matrix PT(n_columns,n_rows);

	for(i = 0; i < n_columns; i++) {
		for(j = 0; j < n_rows; j++) {
			PT[i][j] = Mat[j][i];
		}
	}
	return PT;

}


// Takes the magnitude of a column or row vector
double Matrix::mag()const
{

	int i;
	double d = 0.0;

	// 3 cases - A is 1x1, A is a column vector, A is a row vector
	int n_rows = rows;
	int n_columns = cols;

	if(n_rows == 1 && n_columns == 1) {
		d = Mat[0][0]*Mat[0][0];
		return sqrt(d);
	}

	if(n_rows > n_columns) {
		for(i = 0; i < n_rows; i++) {
			d += Mat[i][0]*Mat[i][0];
			return sqrt(d);
		}
	}

	if(n_columns > n_rows) {
		for(i = 0; i < n_columns; i++) {
			d += Mat[0][i]*Mat[0][i];
			return sqrt(d);
		}
	}
}


Matrix::~Matrix ()//destructor
{
 for(int i =0;i<rows;i++)
   delete [] Mat[i];
 delete [] Mat;

}














