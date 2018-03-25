#include <iostream>
#include "matrix.h"
#include "test.h"

using namespace std;

int read()
{
    int C;

    while (1) {
        if (cin >> C) {
            cin.ignore(256, '\n');
            return C;
        }
        else {
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
}

void showChoices()
{
    cout << "A, B - macierze " << SIZE << "x" << SIZE << endl << endl;
    cout << "1. Wypelnij A" << endl;
    cout << "2. Wypelnij B" << endl;
    cout << "3. Wyswietl A, B" << endl;
    cout << "4. A+B" << endl;
    cout << "5. A-B" << endl;
    cout << "6. A*B" << endl;
    cout << "7. det(A)" << endl;
    cout << "8. det(B)" << endl;
    cout << "9. Testy automatyczne" << endl;
    cout << "0. Koniec" << endl << endl;
}


int main()
{
    Matrix A;
    Matrix B;
    int choice = 1;

    while (choice) {
        showChoices();
        choice = read();

        switch(choice)
        {
        case 1: A.fillValues(); break;
        case 2: B.fillValues(); break;
        case 3: cout << "A: " << &A << endl << A << endl;
                cout << "B: " << &B << endl << B << endl;
                break;
        case 4: cout << A << '+' << endl << B << '=' << endl;
                cout << (A + B) << endl;
                break;
        case 5: cout << A << '-' << endl << B << '=' << endl;
                cout << (A - B) << endl;
                break;
        case 6: cout << A << '*' << endl << B << '=' << endl;
                cout << (A * B) << endl;
                break;
        case 7: cout << "A: " << &A << endl << A << endl;
                cout << "det(A) = " << A.det() << endl;
                break;
        case 8: cout << "B: " << &B << endl << B << endl;
                cout << "det(B) = " << B.det() << endl;
                break;
        case 9: test(); break;
        case 0: break;
        default: cout << "Opcja nie istnieje" << endl;
        }

        cout << "Kontynuuj..." << endl;
        getchar();
    }

    return 0;
}
