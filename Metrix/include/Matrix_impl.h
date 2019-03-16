
#ifndef MATRIX_IMPL_H_INCLUDED
#define MATRIX_IMPL_H_INCLUDED
#include "Matrix.h"
// Main constructor
template <typename T, int length, int width>
Matrix<T, length,width>::Matrix( T initialValue):
    matrix_(new T*[length]),rowLength(length), colLength(width) {
    for(int i = 0; i< rowLength; i++){
         matrix_[i] = new T[colLength];
         for(int j = 0; i<colLength; i++){
            matrix_[i][j] = initialValue;
         }
    }
}
// Default constructor
template <typename T, int length, int width>
Matrix<T, length, width>::Matrix(): Matrix(0){

}

// Destructor
template <typename T, int length, int width>
Matrix< T, length, width>::~Matrix()
{
    deleteMat();
}
/*

template <typename T, int length, int width>
Matrix<typename T, int length, int width>::Matrix(const Matrix& other)
     :rowLength(0),colLength(0), matrix_(NULL) {
  *this = other;
}

template <typename T, int length, int width>
 Matrix<typename T, int length, int width>::Matrix& operator=(const Matrix& rhs){
    if (this == &rhs) return *this;
    deleteMat();
    rowLength = rhs.rowLength;
    colLength = rhs.colLength;
    metrix_(new T*[rowLength]);
    for(int i = 0; i< rowLength; i++){
         matrix_[i] = new T[colLength];
         for(int j = 0; i<colLength; i++){
            matrix_[i][j] = rhs. matrix_[i][j];
         }
    }
    return this*;

 };

*/
template <typename T, int length, int width>
void Matrix<T, length, width>::deleteMat(){
  for(int i = 0; i< rowLength; i++){
        delete[] matrix_[i];
    }
    delete[] matrix_;
 }
#endif // MATRIX_IMPL_H_INCLUDED


