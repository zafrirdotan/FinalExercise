#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

template <typename T, int sizeX, int sizeY>
class Matrix
{
	private:
		T** _matrix;
		T defultValue;
		void deleteMat();
		bool** _flags;
		class MatrixRow {
			public:
				MatrixRow(int rowIndex, T* row, bool* flags, T defaultValue) :
					_rowIndex(rowIndex), _row(row), _flags(flags), _defaultValue(defaultValue) {}
				T& operator[](int colIndex) {
					if (_flags[rowIndex][colIndex]) {
						return _row[rowIndex][colIndex];
					}
					else {
						row[colIndex] = _defaultValue;
						flags[colIndex] = 1;
						return row[colIndex];
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
		int rowLength;
		int colLength;
		MatrixRow operator[](int index) {
			return MatrixRow(index, _matrix[index], _flags, defaultValue);
		}

};

#endif // MATRIX_H
