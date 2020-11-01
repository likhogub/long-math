#include <iostream>
#include "LongNumber.hpp"
using namespace std;

int main() {
    LongNumber A;
    LongNumber B;

    
    B[5] = 1;

    int n = 32;
    int a = 0;



    cout << A.toBinaryString(a, n) << " " << A.toInteger(a, n) << endl;
    cout << B.toBinaryString(a, n) << " " << B.toInteger(a, n) << endl;

    A -= B;
    cout << A.toBinaryString(a, n) << " " << A.toInteger(a, n) << endl;

    A <<= -32;
    cout << A.toBinaryString(a, 65) << " " << A.toInteger(a, n) << endl;

    return 0;
}