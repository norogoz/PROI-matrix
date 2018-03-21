#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    Matrix A(1);
    Matrix B(2);

    cout << A << endl << B << endl << A*B;

    getchar();
    return 0;
}
