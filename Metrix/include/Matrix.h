#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

template <typename T, int sizeX, int sizeY>
class Matrix
{
	private:
		T** _matrix;
		T _defultValue = 0;
		void deleteMat();
		int rowLength;
		int colLength;
		bool** _flags;
		class MatrixRow {
			public:
				MatrixRow(int rowIndex, T* row, bool* flags, T defaultValue) :
					_rowIndex(rowIndex), _row(row), _flags(flags), _defaultValue(defaultValue) {}
				T& operator[](int colIndex) {
					if (_flags[_rowIndex][colIndex]) {
						return _row[_rowIndex][colIndex];
					}
					else {
						_row[colIndex] = _defaultValue;
						_flags[colIndex] = 1;
						return _row[colIndex];
					}
				}
			private:
				int _rowIndex;
				T* _row;
				T* _flags;
				T _defaultValue;
		};

	public:
		Matrix(T initialValue);
		Matrix();
		~Matrix();
		Matrix(const Matrix& other);
		Matrix& operator=(const Matrix& other);
		T avg();
		T min();
		MatrixRow operator[](int index) {
			return MatrixRow(index, _matrix[index], _flags, _defultValue);
		}
		/*
        MatrixRow operator()(int x, int y) {
			return MatrixRow(index, _matrix[index], _flags, _defultValue);
		}
		*/

};

#endif // MATRIX_H
