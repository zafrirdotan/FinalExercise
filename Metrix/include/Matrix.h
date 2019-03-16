#ifndef MATRIX_H
#define MATRIX_H
template <typename T, int length, int width>
class Matrix
{
    public:
        Matrix(T initialValue);
        Matrix();
        ~Matrix();
        Matrix(const Matrix& other);
        Matrix& operator=(const Matrix& other);
    protected:

    private:
        T** matrix_;
        void deleteMat();
        int rowLength;
        int colLength;
};

#endif // MATRIX_H
