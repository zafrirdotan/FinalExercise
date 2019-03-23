
#ifndef MATRIX_IMPL_H_INCLUDED
#define MATRIX_IMPL_H_INCLUDED
#include "Matrix.h"
#include <iostream>
using namespace std;
// Main constructor
template <typename T, int sizeX, int sizeY>
Matrix<T, sizeX, sizeY>::Matrix(T initialValue) :
	_matrix(new T*[sizeX]), _defultValue(initialValue)
	, rowLength(sizeX), colLength(sizeY), _flags(new bool*[sizeX]){
		for (int i = 0; i < rowLength; i++)
		{
			_matrix[i] = new T[colLength];
			_flags[i] = new bool[colLength];
		}
}

// Default constructor
template <typename T, int sizeX, int sizeY>
Matrix<T, sizeX,sizeY>::Matrix(): Matrix(0){}

// Destructor
template <typename T, int sizeX, int sizeY>
Matrix<T, sizeX,sizeY>::~Matrix()
{
    deleteMat();
}

template <typename T, int sizeX, int sizeY>
Matrix<T, sizeX,sizeY>::Matrix(const Matrix& other)
     : _matrix(NULL),rowLength(0),colLength(0) {
  *this = other;
}

template <typename T, int sizeX, int sizeY>
 Matrix<T, sizeX,sizeY>& Matrix<T, sizeX,sizeY>::operator=(const Matrix& other){
    if (this == &other) return *this;
    deleteMat();
    rowLength = other.rowLength;
    colLength = other.colLength;
    _defultValue = other._defultValue;
    _matrix=new T*[rowLength];
    _flags =new bool*[rowLength];
    for(int i = 0; i< rowLength; i++){
         _matrix[i] = new T[colLength];
         _flags[i] = new bool[colLength];
         for(int j = 0; j<colLength; j++){
            if(other._flags[i][j] == true){
                _matrix[i][j] = other._matrix[i][j];
            }else{
                _matrix[i][j] = _defultValue;
            }
            _flags[i][j] = true;
         }
    }
    return *this;

 };
 /*
 template <typename T, int sizeX, int sizeY>
  const Matrix<T, sizeX,sizeY>& Matrix<T, sizeX,sizeY>::operator=(const Matrix& other) const {
    if (this == &other) return *this;
    deleteMat();
    cout << "bubu2"<< endl;
    rowLength = other.rowLength;
    colLength = other.colLength;
    _matrix=new T*[rowLength];
    for(int i = 0; i< rowLength; i++){
         _matrix[i] = new T[colLength];
         for(int j = 0; j<colLength; j++){
            _matrix[i][j] = other. _matrix[i][j];
         }
    }
    return *this;

 };
 */

/*
template <typename T, int sizeX, int sizeY>
     T& Matrix<T, sizeX,sizeY>::operator()(int x,int y) {
        return Matrix[x][y];
    }

template <typename T, int sizeX, int sizeY>
    const T& Matrix<T, sizeX,sizeY>::operator()(int x,int y) const {
        return const_cast<Matrix<T, sizeX,sizeY>*>(this)->operator()(x, y);
    }
*/

 template <typename T, int sizeX, int sizeY>
 T Matrix<T, sizeX, sizeY>::avg()
 {
	 T sum = 0;
	 for (int i = 0; i< rowLength; i++) {
		 for (int j = 0; j< colLength; j++) {
			 if (_flags[i][j] == true)
			 {
				 sum += _matrix[i][j];
			 }
			 else
			 {
				 sum += _defultValue;
			 }

		 }
	 }
	 return sum / (rowLength * colLength);
 }


template <typename T, int sizeX, int sizeY>
T Matrix<T, sizeX, sizeY>::min()
{
	 T minElement = _matrix[0][0];
	 for (int i = 0; i < _matrix.rowLength; i++)
	 {
		 for (int j = 0; j < _matrix.colLength; j++)
		 {
			 if (_flags[i][j] == true)
			 {
				 if (_matrix[i][j] < minElement)
				 {
					 minElement = _matrix[i][j];
				 }
			 }
			 else
			 {
				 if (_defultValue < minElement)
				 {
					 minElement = _defultValue;
				 }
			 }
		 }
	 }
	 return minElement;
 }


 template <typename T, int sizeX, int sizeY>
 Matrix<T, sizeX,sizeY> Matrix<T, sizeX,sizeY>::operator*(const int &number){

    Matrix<T, sizeX,sizeY> temp;
        //cout << "number "<<number<< endl;
    for (int i = 0; i < rowLength; ++i) {
         for (int j = 0; j < colLength; ++j) {
            if(_flags[i][j]){
                temp[i][j] = _matrix[i][j] * number;
            }else{
                 temp[i][j] = number * _defultValue;
            }
        //  cout << temp[i][j]<< endl;
        }
    }
  return temp;
 }

template <typename T, int sizeX, int sizeY>
void Matrix<T, sizeX,sizeY>::deleteMat(){
  for(int i = 0; i< rowLength; i++){
        delete[] _matrix[i];
    }
    delete[] _matrix;
 }
#endif // _matrixIMPL_H_INCLUDED


