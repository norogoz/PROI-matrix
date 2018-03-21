#include "matrix.h"

<<<<<<< HEAD
matrix::matrix()
{
    //ctor
}

matrix::~matrix()
{
    //dtor
}
=======
using std::ostream; using std::istream; using std::endl;

Matrix::Matrix()
{
    value = new double*[SIZE];
    for(int i = 0; i < SIZE; ++i)
        value[i] = new double[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 1;
        }
    }

    std::cout << "Matrix created" << std::endl;

    //ctor
}

Matrix::Matrix(const Matrix& mat)
{
    value = new double*[SIZE];
    for(int i = 0; i < SIZE; ++i)
        value[i] = new double[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = mat.value[i][j];
        }
    }

    std::cout << "Matrix created" << std::endl;

    //ctor
}

Matrix::~Matrix()
{
    for(int i = 0; i < SIZE; ++i) {
        delete[] value[i];
    }

    delete[] value;

    std::cout << "Matrix destroyed" << std::endl;
    //dtor
}

Matrix& Matrix::operator+=(const Matrix& add)
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] += add.value[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix& sub)
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] -= sub.value[i][j];
        }
    }

    return *this;
}

/*
Matrix& Matrix::operator*=(const Matrix& mul)
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] *= mul;
        }
    }

    return *this;
}
*/

Matrix& Matrix::operator*=(const double mul)
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] *= mul;
        }
    }

    return *this;
}

/*
double det (const Matrix& mat)
{

}
*/

ostream& operator<<(ostream& os, const Matrix& mat)
{
    for (int i = 0; i < SIZE; ++i) {
        os << mat.value[i][0];
        for (int j = 1; j < SIZE; ++j) {
            os << " " << mat.value[i][j];
        }

        os << endl;
    }

    return os;
}

Matrix operator+(const Matrix& A, const Matrix& B)
{
    Matrix temp(A);
    temp += B;
    return (temp);
}

Matrix operator-(const Matrix& A, const Matrix& B)
{
    Matrix temp(A);
    temp -= B;
    return (temp);
}

/*
Matrix operator*(const Matrix& A, const Matrix& B)
{
    Matrix temp(A);
    temp *= B;
    return (temp);
}
*/

Matrix operator*(const Matrix& A, double mul)
{
    Matrix temp(A);
    temp *= mul;
    return (temp);
}

Matrix operator*(double mul, const Matrix& A)
{
    Matrix temp(A);
    temp *= mul;
    return (temp);
}
>>>>>>> 5a6959c0c6cf9cde083e9e5090b3e5fc0b0e941e
