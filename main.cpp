#include <iostream>
#include "LongNumber.hpp"
using namespace std;

int main() {
    LongNumber A;
    LongNumber B(10);
    LongNumber C;
    A[0] = 1;
    A[1] = 1;
    



    int n = 65;
    int a = 0;


    cout << "A: " << A.toBinary(a, n) << " " << A.toInteger(a, n) << endl;
    cout << "B: " << B.toBinary(a, n) << " " << B.toInteger(a, n) << endl;

    /*
    cout << "A: " << A.toBinary(a, n) << " " << A.toInteger(a, n) << endl;
    cout << "B: " << B.toBinary(a, n) << " " << B.toInteger(a, n) << endl;
    //cout << "C: " << C.toBinary(a, n) << " " << C.toInteger(a, n) << endl;
    */

    return 0;
}