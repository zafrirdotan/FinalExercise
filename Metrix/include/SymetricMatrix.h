#ifndef SYMETRICMATRIX_H
#define SYMETRICMATRIX_H
#include "Matrix.h"

template <typename T, int size>
class SymetricMatrix : Matrix
{
public:
	SymetricMatrix(T initialValue) : Matrix<T, size, size>(initialValue) {}
	SymetricMatrix() : Matrix<T, size, size>() {}
};


#endif // SymetricMatrix