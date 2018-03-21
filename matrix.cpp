#include "matrix.h"

using std::ostream; using std::istream; using std::endl;

Matrix::Matrix()
{
    std::cout << "Uruchomiono konstruktor na rzecz obiektu: " << this << std::endl;

    value = new double*[SIZE];
    for(int i = 0; i < SIZE; ++i)
        value[i] = new double[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }

    //ctor
}

Matrix::Matrix(const Matrix& mat)
{
    std::cout << "Uruchomiono konstruktor na rzecz obiektu: " << this << std::endl;

    value = new double*[SIZE];
    for(int i = 0; i < SIZE; ++i)
        value[i] = new double[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = mat.value[i][j];
        }
    }

    //ctor
}

Matrix::Matrix(const double init)
{
    std::cout << "Uruchomiono konstruktor na rzecz obiektu: " << this << std::endl;

    value = new double*[SIZE];
    for(int i = 0; i < SIZE; ++i)
        value[i] = new double[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = init;
        }
    }

    //ctor
}

Matrix::~Matrix()
{
    std::cout << "Uruchomiono destruktor na rzecz obiektu: " << this << std::endl;

    for(int i = 0; i < SIZE; ++i) {
        delete[] value[i];
    }

    delete[] value;

    //dtor
}

Matrix& Matrix::operator=(const Matrix& mat)
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = mat.value[i][j];
        }
    }

    return *this;
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

Matrix& Matrix::operator*=(const Matrix& mul)
{
    Matrix temp(0);

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int n = 0; n < SIZE; ++n) {
               temp.value[i][j] += (*this).value[i][n]*mul.value[n][j];
            }
        }
    }

    *this = temp;
    return *this;
}

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
double det(const Matrix& mat)
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


Matrix operator*(const Matrix& A, const Matrix& B)
{
    Matrix temp(A);
    temp *= B;
    return (temp);
}

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
