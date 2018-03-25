#include "test.h"
#include "matrix.h"

using namespace std;

int test ()
{
    cout << "Uruchomiono testy." << endl << endl;

    double emptyInit[TEST][TEST] =
    {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    double AInit[TEST][TEST] =
    {
        {78, -66, 40, -3},
        {-31, 71, -9, 81},
        {13, 32, -34, 11},
        {-93, 67, -52, -90}
    };

    double BInit[TEST][TEST] =
    {
        {71, 28, -37, 93},
        {-99, -27, 61, -74},
        {-89, -42, 74, 63},
        {-99, -68, 33, 29}
    };

    double ABInit[TEST][TEST] = // =A*B
    {
        {8809, 2490, -4051, 14571},
        {-16448, -7915, 7485, -6355},
        {-308, 180, -682, -2982},
        {302, 3891, 710, -19493}
    };

    double detA = 11441159;

    Matrix A(AInit); //Inicjalizacja macierzy A, B, AB tablicami AInit, BInit, ABInit
    Matrix B(BInit);
    Matrix AB(ABInit);

    cout << "Operacja dodawania: " << endl;
    if (sum(A,B,emptyInit)) cout << "OK" << endl << endl;
    else cout << "BLAD" << endl << endl;

    cout << "Operacja odejmowania: " << endl;
    if (diff(A,B,emptyInit)) cout << "OK" << endl << endl;
    else cout << "BLAD" << endl << endl;

    cout << "Operacja mnozenia: " << endl;
    if (AB == A*B) cout << "OK" << endl << endl;
    else cout << "BLAD" << endl << endl;

    cout << "Obliczanie wyznacznika: " << endl;
    if (detA == A.det()) cout << "OK" << endl << endl;
    else cout << "BLAD" << endl << endl;

    return 1;
}

int sum (Matrix A, Matrix B, double emptyInit[TEST][TEST])
{
    Matrix C(emptyInit);
    C = A + B;

    for (int i = 0; i < TEST; ++i) {
        for (int j = 0; j < TEST; ++j) {
            if ( C(i,j) != A(i,j) + B(i,j) ) return 0;
        }
    }

    return 1;
}

int diff (Matrix A, Matrix B, double emptyInit[TEST][TEST])
{
    Matrix C(emptyInit);
    C = A - B;

    for (int i = 0; i < TEST; ++i) {
        for (int j = 0; j < TEST; ++j) {
            if ( C(i,j) != A(i,j) - B(i,j) ) return 0;
        }
    }

    return 1;
}
