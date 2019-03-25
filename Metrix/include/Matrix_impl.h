
#ifndef MATRIX_IMPL_H_INCLUDED
#define MATRIX_IMPL_H_INCLUDED
#define BASE_DEFAULT_VALUE 0 // value used as default value in case no default value was specified
#include "Matrix.h"
#include <iostream>
// Main constructor
template <typename T, int sizeX, int sizeY>
Matrix<T, sizeX, sizeY>::Matrix(T initialValue) :
	_matrix(new T*[sizeX]), rowLength(sizeX), colLength(sizeY),
	_flags(new bool*[sizeX]), _defaultValue(initialValue)
	{
		for (int i = 0; i < rowLength; i++)
		{
			_matrix[i] = new T[colLength]; 
			_flags[i] = new bool[colLength]; 
		}
	}

// Default constructor
template <typename T, int sizeX, int sizeY>
Matrix<T, sizeX,sizeY>::Matrix(): Matrix(BASE_DEFAULT_VALUE){}

// Destructor
template <typename T, int sizeX, int sizeY>
Matrix<T, sizeX,sizeY>::~Matrix()
{
    deleteMat();
}

template <typename T, int sizeX, int sizeY>
Matrix<T, sizeX,sizeY>::Matrix(const Matrix& other) {
	_matrix = NULL;
	_flags = NULL;
	*this = other;
}

template <typename T, int sizeX, int sizeY>
 Matrix<T, sizeX,sizeY>& Matrix<T, sizeX,sizeY>::operator=(const Matrix& other){
	if (this == &other) return *this;
	deleteMat();
	_matrix = new T*[other.rowLength];
	rowLength = other.rowLength;
	colLength = other.colLength;
	_flags = new bool*[other.rowLength];
	_defaultValue = other._defaultValue;
	for (int i = 0; i< rowLength; i++) {
		_matrix[i] = new T[colLength];
		_flags[i] = new bool[colLength];
		for (int j = 0; j < colLength; j++) {
			if (other._flags[i][j] == true)
			{
				_matrix[i][j] = other._matrix[i][j];
				_flags[i][j] = other._flags[i][j];
			}
		}
	}
	return *this;
 };

 template <typename T, int sizeX, int sizeY>
 Matrix<T, sizeX, sizeY> Matrix<T, sizeX, sizeY>::operator*(const int &number) {

	 Matrix<T, sizeX, sizeY> temp;
	 for (int i = 0; i < rowLength; ++i) {
		 for (int j = 0; j < colLength; ++j) {
			 if (_flags[i][j]) {
				 temp[i][j] = _matrix[i][j] * number;
			 }
			 else {
				 temp[i][j] = number * _defaultValue;
			 }
		 }
	 }
	 return temp;
 }

template <typename T, int sizeX, int sizeY>
     T& Matrix<T, sizeX,sizeY>::operator()(int x,int y) {
        return (*this)[x][y];
    }

template <typename T, int sizeX, int sizeY>
double Matrix<T, sizeX, sizeY>::avg()const
 {
	 double sum = 0;
	 for (int i = 0; i< rowLength; i++) {
		 for (int j = 0; j<colLength; j++) {
			 if (_flags[i][j] == true)
			 {
				 sum += _matrix[i][j];
			 }
			 else
			 {
				 sum += _defaultValue;
			 }
		 }
	 }
	 return sum / (rowLength * colLength);
 }


template <typename T, int sizeX, int sizeY>
T Matrix<T, sizeX, sizeY>::min()const
{
	 T minElement = _defaultValue;
	 for (int i = 0; i < rowLength; i++)
	 {
		 for (int j = 0; j < colLength; j++)
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
				 if (_defaultValue < minElement)
				 {
					 minElement = _defaultValue;
				 }
			 }
		 }
	 }
	 return minElement;
 }

template <typename T, int sizeX, int sizeY>
void Matrix<T, sizeX, sizeY>::deleteMat() {
	if (_matrix == NULL)
	{
		return;
	}
	for (int i = 0; i < rowLength; i++) {
		delete[] _matrix[i];
		delete[] _flags[i];
	}
	delete[] _matrix;
	delete[] _flags;
};

//template <typename T, int sizeX, int sizeY>
//ostream& operator <<(ostream& os, const Matrix& matrix) {
//	for (int i = 0; i < rowLength; i++)
//	{
//		cout << "\n";
//		for (int j = 0; j < colLength; j++)
//		{
//			if (_flags[i][j] == true)
//			{
//				cout << _matrix[i][j] << endl;
//			}
//			else
//			{
//				cout << _defaultValue << endl;
//			}
//		}
//	}
//	return os;
//};

#endif // _matrixIMPL_H_INCLUDED


