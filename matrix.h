#ifndef MATRIX_H
#define MATRIX_H

<<<<<<< HEAD
#define SIZE 5


class matrix
{
    public:
        int arr[SIZE][SIZE];
        matrix();
        ~matrix();

    private:
};

=======
#include <iostream>
#define SIZE 5


class Matrix
{
    public:
        Matrix();
        ~Matrix();
        Matrix(const Matrix&);

        inline double& operator()(int x, int y) { return value[x][y]; }

        Matrix& operator+=(const Matrix&);
        Matrix& operator-=(const Matrix&);
        Matrix& operator*=(const Matrix&);
        Matrix& operator*=(double);
        double det (const Matrix&);

        friend std::ostream& operator<<(std::ostream&, const Matrix&);

    private:
        double **value;
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator*(double, const Matrix&);

>>>>>>> 5a6959c0c6cf9cde083e9e5090b3e5fc0b0e941e
#endif // MATRIX_H
