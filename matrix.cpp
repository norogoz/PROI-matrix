#include "matrix.h"
#include <math.h>

using std::ostream; using std::istream; using std::endl;

Matrix::Matrix(const int dim)
{
    std::cout << "***Uruchomiono konstruktor na rzecz obiektu: " << this << "***" << std::endl;

    N = dim;

    //alokacja pamiêci
    value = new double*[N];
    for(int i = 0; i < N; ++i)
        value[i] = new double[N];

    //inicjalizacja
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            value[i][j] = 0;
        }
    }

    //ctor
}

Matrix::Matrix()
{
    std::cout << "***Uruchomiono konstruktor na rzecz obiektu: " << this << "***" << std::endl;

    value = new double*[N];
    for(int i = 0; i < N; ++i)
        value[i] = new double[N];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            value[i][j] = 0;
        }
    }

    //ctor
}

Matrix::Matrix(const Matrix& mat)
{
    std::cout << "***Uruchomiono konstruktor na rzecz obiektu: " << this << "***" << std::endl;

    N = mat.N;

    value = new double*[N];
    for(int i = 0; i < N; ++i)
        value[i] = new double[N];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            value[i][j] = mat.value[i][j];
        }
    }

    //ctor
}

Matrix::Matrix(const double init[TEST][TEST])
{
    std::cout << "***Uruchomiono konstruktor na rzecz obiektu: " << this << "***" << std::endl;

    N = TEST;

    value = new double*[N];
    for(int i = 0; i < N; ++i)
        value[i] = new double[N];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            value[i][j] = init[i][j];
        }
    }

    //ctor
}

Matrix::~Matrix()
{
    std::cout << "***Uruchomiono destruktor na rzecz obiektu: " << this << "***" << std::endl;

    for(int i = 0; i < N; ++i) {
        delete[] value[i];
    }

    delete[] value;

    //dtor
}

int Matrix::fillValues()
{
    std::cout << "Przypisywanie wartosci elementom obiektu " << this << std::endl;

    //wczytywanie wartoœci dla ka¿dego elementu
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            if (std::cin >> value[i][j]); //walidacja wprowadzonych danych
            else {
                j--;
                std::cin.clear();
            }
            std::cin.ignore(256, '\n');
        }
        std::cout << std::endl;
    }
    return 1;
}

double Matrix::det()
{
    double d = 0;
    Matrix submat(N-1);
    if (N == 2)
        return ((value[0][0] * value[1][1]) - (value[1][0] * value[0][1]));
    else {
       for (int c = 0; c < N; c++) {
           int subi = 0; //"i" macierzy submat
           for (int i = 1; i < N; i++) { //pomijamy i-t¹ kolumnê
              int subj = 0;
              for (int j = 0; j < N; j++) {
                 if (j == c) //pomijamy c-ty wiersz
                    continue;
                 submat.value[subi][subj] = value[i][j];
                 subj++;
              }
              subi++;
           }
           if (value[0][c] != 0 ) d += (pow(-1, c) * value[0][c] * submat.det()); // rekursja
        }
     }
     return d;
}

Matrix& Matrix::operator=(const Matrix& mat)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            value[i][j] = mat.value[i][j];
        }
    }

    return *this;
}

bool Matrix::operator==(const Matrix& mat)
{
    if (N != mat.N) return false;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (value[i][j] != mat.value[i][j]) return false;
        }
    }

    return true;
}

Matrix& Matrix::operator+=(const Matrix& add)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            value[i][j] += add.value[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix& sub)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            value[i][j] -= sub.value[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator*=(const Matrix& mul)
{
    Matrix temp(mul.N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int n = 0; n < N; ++n) {
               temp.value[i][j] += (*this).value[i][n]*mul.value[n][j];
            }
        }
    }

    *this = temp;
    return *this;
}

Matrix& Matrix::operator*=(const double mul)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            value[i][j] *= mul;
        }
    }

    return *this;
}

ostream& operator<<(ostream& os, const Matrix& mat)
{
    for (int i = 0; i < mat.N; ++i) {
        os << mat.value[i][0];
        for (int j = 1; j < mat.N; ++j) {
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
