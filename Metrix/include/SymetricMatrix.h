#ifndef SYMETRICMATRIX_H
#define SYMETRICMATRIX_H
#include "Matrix.h"

template <typename T, int size>
class SymetricMatrix : public Matrix<T, size, size>
{
public:
	SymetricMatrix(T initialValue) : Matrix<T, size, size>(initialValue) {}
	SymetricMatrix() : Matrix<T, size, size>() {}

};


#endif // SymetricMatrix