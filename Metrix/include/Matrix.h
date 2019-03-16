#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

template <typename T, int sizeX, int sizeY>
class Matrix
{
    public:
        Matrix(T initialValue);
        Matrix();
        ~Matrix();
        Matrix(const Matrix& other);
        Matrix& operator=(const Matrix& other);
		T avg();
		T min();

    private:
        T** matrix_;
        void deleteMat();
        int rowLength;
        int colLength;
};

#endif // MATRIX_H
