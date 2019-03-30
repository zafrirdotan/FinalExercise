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
		Matrix operator*(const int &num);
		Matrix operator*(const Matrix& other);
		const Matrix operator*(const Matrix& other) const;
		Matrix operator+(const int &num);
		Matrix operator+(const Matrix& other);
		Matrix& operator+=(const Matrix& other);
        bool operator==(const Matrix& other);
		bool operator!=(const Matrix& other);
		MatrixRow operator[](int index)const {
			return MatrixRow( _matrix[index], _flags[index], _defaultValue);
		}
		T& operator()(int x, int y);

		class IllegalOperation: public std::exception{
          const char* msg;
          public:
              IllegalOperation(const char* msg = ""): msg(msg){};
            const char * what () const throw (){
                return msg ;
            }
        };

    template<typename S, int x, int y> friend class Matrix;
    template<typename S, int x, int y> Matrix(const Matrix<S, x, y>& other):
	_matrix(new S*[x]), rowLength(x), colLength(y),
	_flags(new bool*[x]), _defaultValue(other._defaultValue)
	{
		for (int i = 0; i < rowLength; i++)
		{
			_matrix[i] = new T[colLength];
			_flags[i] = new bool[colLength];
		}
        };

    template<typename S, int x, int y> Matrix< T, sizeX, sizeY>& operator=(Matrix< S, x, y>& other) {
        deleteMat();
        _matrix = new S*[other.rowLength];
        rowLength = other.rowLength;
        colLength = other.colLength;
        _flags = new bool*[other.rowLength];
        _defaultValue = other._defaultValue;
        for (int i = 0; i< rowLength; i++) {
            _matrix[i] = new S[colLength];
            _flags[i] = new bool[colLength];
            for (int j = 0; j < colLength; j++) {
                if (other._flags[i][j] == true)
                {
                    _matrix[i][j] = other._matrix[i][j];
                    _flags[i][j] = other._flags[i][j];
                }
            }
        }
        return *this;
    };

    template<typename S, int x, int y> Matrix< T, sizeX, sizeY>& operator*(Matrix< S, x, y>& other) {
        if(other.rowLength > colLength || other.colLength > colLength){
            throw IllegalOperation("A matrix can not multiply with a bigger matrix than it's self!");
        }
        Matrix<T, sizeX, sizeY> temp;
        for (int i = 0; i < rowLength; ++i) {
		 for (int j = 0; j < colLength; ++j) {
			 if(_flags[i][j] == true && other._flags[i][j] == true){
                temp[i][j]  = _matrix[i][j] * other._matrix[i][j];
            }else if(_flags[i][j] == true && other._flags[i][j] == false){
                temp[i][j] = _matrix[i][j] * other._defaultValue;
            }else if(_flags[i][j] == false && other._flags[i][j] == true){
                temp[i][j] = _defaultValue * other._matrix[i][j];
            }else{
                temp[i][j] = _defaultValue * other._defaultValue;
            }
		 }
        }
	 return temp;
    }

     template<typename S, int x, int y>
     const Matrix< T, sizeX, sizeY>& operator*(const Matrix< S, x, y>& other) const {
     /*
        return const_cast <Matrix< S, x, y>*>(this)->operator*(other);
        */
        if(other.rowLength > colLength || other.colLength > colLength){
            throw IllegalOperation("A matrix can not multiply with a bigger matrix than it's self!");
        }
        Matrix<T, sizeX, sizeY> temp;
        for (int i = 0; i < rowLength; ++i) {
		 for (int j = 0; j < colLength; ++j) {
			 if(_flags[i][j] == true && other._flags[i][j] == true){
                temp[i][j]  = _matrix[i][j] * other._matrix[i][j];
            }else if(_flags[i][j] == true && other._flags[i][j] == false){
                temp[i][j] = _matrix[i][j] * other._defaultValue;
            }else if(_flags[i][j] == false && other._flags[i][j] == true){
                temp[i][j] = _defaultValue * other._matrix[i][j];
            }else{
                temp[i][j] = _defaultValue * other._defaultValue;
            }
		 }
        }
	 return temp;
    }





};

#endif // MATRIX_H
