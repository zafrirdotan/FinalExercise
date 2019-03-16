
#ifndef MATRIX_IMPL_H_INCLUDED
#define MATRIX_IMPL_H_INCLUDED
#include "Matrix.h"
#include <iostream>
// Main constructor
template <typename T, int sizeX, int sizeY>
Matrix<T, sizeX,sizeY>::Matrix( T initialValue):
    matrix_(new T*[sizeX]),rowLength(sizeX), colLength(sizeY) {
    for(int i = 0; i< rowLength; i++){
         matrix_[i] = new T[colLength];
         for(int j = 0; j<colLength; j++){
            matrix_[i][j] = initialValue;
         }
    }
}
// Default constructor
template <typename T, int sizeX, int sizeY>
Matrix<T, sizeX,sizeY>::Matrix(): Matrix(0){

}

// Destructor
template <typename T, int sizeX, int sizeY>
Matrix<T, sizeX,sizeY>::~Matrix()
{
    deleteMat();
}

template <typename T, int sizeX, int sizeY>
Matrix<T, sizeX,sizeY>::Matrix(const Matrix& other)
     :rowLength(0),colLength(0), matrix_(NULL) {
  *this = other;
}

template <typename T, int sizeX, int sizeY>
 Matrix<T, sizeX,sizeY>& Matrix<T, sizeX,sizeY>::operator=(const Matrix& rhs){
    if (this == &rhs) return *this;
    deleteMat();
    rowLength = rhs.rowLength;
    colLength = rhs.colLength;
    matrix_=new T*[rowLength];
    for(int i = 0; i< rowLength; i++){
         matrix_[i] = new T[colLength];
         for(int j = 0; j<colLength; j++){
            matrix_[i][j] = rhs. matrix_[i][j];
         }
    }
    return *this;

 };

 template <typename T, int sizeX, int sizeY>
 T Matrix<T, sizeX, sizeY>::avg()
 {
	 T sum = 0;
	 for (int i = 0; i< rowLength; i++) {
		 matrix_[i] = new T[colLength];
		 for (int j = 0; j<colLength; j++) {
			 sum += matrix_[i][j];
		 }
	 }
	 return sum / (rowLength + colLength);
 }

template <typename T, int sizeX, int sizeY>
T Matrix<T, sizeX, sizeY>::min()
 {
	 T minNumber = matrix[0][0];
	 for (int i = 0; i < matrix.rowLength; i++)
	 {
		 for (int j = 0; j < matrix.colLength; j++)
		 {
			 if (matrix[i][j] < minNumber)
			 {
				 minNumber = matrix[i][j];
			 }
		 }
	 }
	 return minNumber;
 }

template <typename T, int sizeX, int sizeY>
void Matrix<T, sizeX,sizeY>::deleteMat(){
  for(int i = 0; i< rowLength; i++){
        delete[] matrix_[i];
    }
    delete[] matrix_;
 }
#endif // MATRIX_IMPL_H_INCLUDED


