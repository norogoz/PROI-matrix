#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#define SIZE 3
#define TEST 4


class Matrix
{
    private:
        Matrix(const int); // fixed size matrix
        int N = SIZE;
        double **value;

    public:
        Matrix(); // default ctor
        Matrix(const Matrix&); // copy ctor
        Matrix(const double[TEST][TEST]); // test ctor
        ~Matrix(); // dtor

        int fillValues();
        double det(); //determinant

        inline double& operator()(int x, int y) { return value[x][y]; }

        Matrix& operator=(const Matrix&);
        bool operator==(const Matrix&);
        Matrix& operator+=(const Matrix&);
        Matrix& operator-=(const Matrix&);
        Matrix& operator*=(const Matrix&);
        Matrix& operator*=(double);

        friend std::ostream& operator<<(std::ostream&, const Matrix&);
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator*(double, const Matrix&);

#endif // MATRIX_H
