#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

template <typename T, int sizeX, int sizeY>
class Matrix
{
protected:
	bool** _flags;
	class MatrixRow {
	public:
		MatrixRow(T* row, bool* flags, T defaultValue) :
			_row(row), _flags(flags), _defaultValue(defaultValue) {}
		T& operator[](int colIndex) {
			if (_flags[colIndex] == true) {
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
	friend Matrix operator *(const int &number, Matrix &matrix)
	{
		return (matrix * number);
	};

public:
	T** _matrix;
	int rowLength;
	int colLength;
	T _defaultValue;
	void deleteMat();
	Matrix(T initialValue);
	Matrix();
	~Matrix();
	Matrix(const Matrix& other);
	double avg()const;
	T min()const;
	Matrix& operator=(const Matrix& other);
	Matrix operator*(const int &num);
	Matrix operator+(const Matrix& other);
	Matrix& operator+=(const Matrix& other);
	bool operator==(const Matrix& other);
	bool operator!=(const Matrix& other);
	T& operator()(int x, int y);

	template <typename T, int sizeX, int sizeY>
	friend ostream& operator <<(ostream& os, const Matrix<T, sizeX, sizeY>& matrix);
	virtual MatrixRow operator[](int index)const {
		return MatrixRow(_matrix[index], _flags[index], _defaultValue);
	}

	class IllegalOperation : public std::exception {
		const char* msg;
	public:
		IllegalOperation(const char* msg = "") : msg(msg) {};
		const char * what() const throw () {
			return msg;
		}
	};

	template<typename S, int x, int y>
	friend class Matrix;

	template<typename S, int x, int y>
	const Matrix<T, sizeX, y> operator*(const Matrix<S, x, y>& other) const {
		if (other.rowLength != colLength) {
			throw IllegalOperation("These matrix can't be multiplied according to math laws !");
		}
		const Matrix<T, sizeX, y> temp(0);
		for (int i = 0; i < sizeX; ++i) {
			for (int j = 0; j < other.colLength; ++j) {
				for (int k = 0; k < colLength; k++)
				{
					temp[i][j] += ((*this)[i][k] * other[k][j]);
				}
			}
		}
		return temp;
	}
};

#endif // MATRIX_H
