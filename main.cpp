#include <iostream>
#include "LongNumber.hpp"
using namespace std;

int main() {
    LongNumber A;
    LongNumber B;
    A[8] = 1;


    B[0] = 1;

    int n = 32;
    int a = 0;
    cout << A.toBinaryString(a, n) << " " << A.toInteger(a, n) << endl;
    cout << B.toBinaryString(a, n) << " " << B.toInteger(a, n) << endl;
    
    A -= B;


    cout << A.toBinaryString() << " " << A.toInteger(a, n) << endl;


    return 0;
}