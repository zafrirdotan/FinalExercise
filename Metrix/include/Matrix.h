#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

template <typename T, int sizeX, int sizeY>
class Matrix
{
	private:
		T** _matrix;
		T _defaultValue;
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
		Matrix operator*(const int &num);
		friend  Matrix operator *(const int &number, Matrix &matrix)
		{
			return (matrix * number);
		};

	public:
		Matrix(T initialValue);
		Matrix();
		~Matrix();
		Matrix(const Matrix& other);
		Matrix& operator=(const Matrix& other);
		double avg()const;
		T min()const;
	/*	friend ostream& operator <<(ostream& os, const Matrix& other);*/
		MatrixRow operator[](int index)const {
			return MatrixRow( _matrix[index], _flags[index], _defaultValue);
		}
		T& operator()(int x, int y);



};

#endif // MATRIX_H
