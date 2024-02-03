#include<iostream>
#include "matrix2.h"
using namespace std;

int main() {
    Matrix A(2, 2);
    cin >> A;
    cout << "Matrix A:" << endl;
    cout << A;

    Matrix B(2, 2);
    cin >> B;
    cout << "Matrix B:" << endl;
    cout << B;

    try {
        Matrix C = A + B;
        cout << "Matrix C (A + B):" << endl;
        cout << C;

        Matrix D = A - B;
        cout << "Matrix D (A - B):" << endl;
        cout << D;

        Matrix E = A * B;
        cout << "Matrix E (A * B):" << endl;
        cout << E;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
