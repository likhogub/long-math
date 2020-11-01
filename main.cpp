#include <iostream>
#include "LongNumber.hpp"
using namespace std;

int main() {
    LongNumber A;
    LongNumber B;
    LongNumber C;
    A[0] = 1;
    A[1] = 1;
    B[4] = 1;
    B[2] = 1;


    int n = 65;
    int a = 0;


    cout << "A: " << A.toBinaryString(a, n) << " " << A.toInteger(a, n) << endl;
    //cout << "B: " << B.toBinaryString(a, n) << " " << B.toInteger(a, n) << endl;



    B *= A;
    cout << "A: " << A.toBinaryString(a, n) << " " << A.toInteger(a, n) << endl;
    cout << "B: " << B.toBinaryString(a, n) << " " << B.toInteger(a, n) << endl;



    return 0;
}