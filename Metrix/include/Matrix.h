#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

template <typename T, int sizeX, int sizeY>
class Matrix
{
private:
	// enables to multiply number with matrix when the number os on the right to the matrix
	friend Matrix operator *(const int &number, Matrix &matrix) {
		return (matrix * number);
	};

// protected enables SymetricMatrix to approach the variables
protected:
	// _flags marks weather an index has a value\was initialied (true) or it has a garbage value in if (false)
	bool** _flags;
	// class MatrixRow is part of the implementation of operator [][]
	// _type is a variable that distingish from Matrix (1) to SymetricMatrix (2)
	class MatrixRow {
	public:
		MatrixRow(T* row, bool* flags, T defaultValue, int type, shared_ptr<T>* sharedPtrs, shared_ptr<bool>* sharedFlags) :
			_row(row), _flags(flags), _defaultValue(defaultValue), _type(type), 
			_sharedPtrs(sharedPtrs), _sharedFlags(sharedFlags) {}
		T& operator[](int colIndex) {
			if (_type == 1)
			{
				if (_flags[colIndex] == true) {
					return _row[colIndex];
				}
				else {
					_row[colIndex] = _defaultValue;
					_flags[colIndex] = true;
					return _row[colIndex];
				}
			}
			else if (_type == 2)
			{
				if (*(_sharedFlags[colIndex]) == true) {
					return *(_sharedPtrs[colIndex]);
				}
				else {
					*(_sharedPtrs[colIndex]) = _defaultValue;
					*(_sharedFlags[colIndex]) = true;
					return *(_sharedPtrs[colIndex]);
				}
			}
		}

	private:
		T* _row;
		bool* _flags;
		T _defaultValue;
		int _type;
		shared_ptr<T>* _sharedPtrs;
		shared_ptr<bool>* _sharedFlags;
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
	
	//operator [][], implemented by the class MatrixRow (in private)
	virtual MatrixRow operator[](int index)const {
		return MatrixRow(_matrix[index], _flags[index], _defaultValue, 1, NULL, NULL);
	}

	//throws exception
	class IllegalOperation : public std::exception {
		const char* msg;
	public:
		IllegalOperation(const char* msg = "") : msg(msg) {};
		const char * what() const throw () {
			return msg;
		}
	};

	// allows to implement operators that excepts two matrixes of different templates
	template<typename S, int x, int y>
	friend class Matrix;

	template<typename S, int x, int y>
	const Matrix<T, sizeX, y> operator*(const Matrix<S, x, y>& other) const {
		if (other.rowLength != colLength) {
			throw IllegalOperation("These matrixes can't be multiplied according to math laws !");
		}
		const Matrix<T, sizeX, y> temp(0);
		for (int i = 0; i < sizeX; ++i) {
			for (int j = 0; j < other.colLength; ++j) {
				for (int k = 0; k < colLength; k++) {
					temp[i][j] += ((*this)[i][k] * other[k][j]);
				}
			}
		}
		return temp;
	}
};

#endif // MATRIX_H
