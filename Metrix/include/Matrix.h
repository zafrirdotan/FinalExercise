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

        const T& operator()(int x,int y) const;
        T& operator()(int x,int y);

        const T*& operator[](int &index) const;
        T*& operator[](int &index);
    private:
        T** matrix_;
        void deleteMat();
        int rowLength;
        int colLength;
};

#endif // MATRIX_H
