#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

template <typename T, int sizeX, int sizeY>
class Matrix
{
	private:
		T** _matrix;
		T _defultValue;
		void deleteMat();
		int rowLength;
		int colLength;
		bool** _flags;
		class MatrixRow {
			public:
				MatrixRow( T* row, bool* flags, T defaultValue) :
                    _row(row), _flags(flags), _defaultValue(defaultValue) {}
				T& operator[](int colIndex) {
					if (_flags[colIndex]==true) {
						return _row[colIndex];
					}
					else {
						_row[colIndex] = _defaultValue;
						_flags[colIndex] = true;
						return _row[colIndex];
					}
				}
			private:
				T* _row;
				bool* _flags;
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
			return MatrixRow( _matrix[index], _flags[index], _defultValue);
		}

        T& operator()(int x, int y) {
			if (_flags[x][y] == true) {
				return _matrix[x][y];
			}
			else {
				_matrix[x][y] = _defultValue;
				_flags[x][y] = true;
				return _matrix[x][y];
			}
		}


};

#endif // MATRIX_H
