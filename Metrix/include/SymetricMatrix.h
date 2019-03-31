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

	MatrixRow operator[](int index)const {
		T* row = new T[size];
		bool* flags = new bool[size];
		for (int col = 0; col < size; col++)
		{
			row[col] = *(_symetrix_matrix[index][col]);
			flags[col] = *(_symetric_flags[index][col]);
		}
		return MatrixRow(row, flags, _defaultValue);
	}
};

#endif // SymetricMatríx