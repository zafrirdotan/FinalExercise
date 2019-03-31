#ifndef SYMETRICMATRIX_H
#define SYMETRICMATRIX_H
#include "Matrix.h"

template <typename T, int size>
class SymetricMatrix : public Matrix<T, size, size>
{

private:
	shared_ptr<T>** _symetrix_matrix;
	shared_ptr<bool>** _symetric_flags;

public:
	// constructor
	SymetricMatrix(T initialValue) : Matrix<T, size, size>(initialValue)
	{
		_symetrix_matrix = new shared_ptr<T>*[size];
		_symetric_flags = new shared_ptr<bool>*[size];
		for (int i = 0; i < size; i++)
		{
			_symetrix_matrix[i] = new shared_ptr<T>[size];
			_symetric_flags[i] = new shared_ptr<bool>[size];
			for (int j = 0; j < size; j++)
			{
				if (i > j)
				{
					_symetrix_matrix[i][j] = _symetrix_matrix[j][i];
					_symetric_flags[i][j] = _symetric_flags[j][i];
				}
				else
				{
					_symetrix_matrix[i][j] = shared_ptr<T>(new T(_defaultValue));
					_symetric_flags[i][j] = shared_ptr<bool>(new bool(false));
				}
			}
		}
	}
	~SymetricMatrix() {
		if (_symetrix_matrix == NULL) {
			return;
		}
		for (int i = 0; i < rowLength; i++) {
			delete[] _symetrix_matrix[i];
			delete[] _symetric_flags[i];
		}
		delete[] _symetrix_matrix;
		delete[] _symetric_flags;
	};
	MatrixRow operator[](int index)const {
		return MatrixRow(_matrix[index], _flags[index], _defaultValue, 2, _symetrix_matrix[index], _symetric_flags[index]);
	}

};

#endif // SymetricMatríx