#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    Matrix A;
    double detA;

    A.fillValues();
    detA = A.det();

    cout << A << endl << detA << endl;

    getchar();
    return 0;
}
