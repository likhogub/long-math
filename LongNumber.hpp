#define LNLength 2048
#include <iostream>
using namespace std;

class LongNumber {
    private:
        bool bitArray[LNLength + 1] = {0};

        void copyArrayFrom(const LongNumber &LN) {
            for (int i = 0; i < LNLength + 1; i++)
                bitArray[i] = LN.bitArray[i];
        }

        //Add B to this
        void add(LongNumber &B);

        //Add B to A 
        void add(LongNumber &A, LongNumber &B);

        //Add B with indexB to this
        void add(LongNumber &B, int startIndexB);

        //Add B (from indexB) to A (from indexA)
        void add(LongNumber &A, LongNumber &B, int startIndexA, int startIndexB);

        //Shift number to N positions
        void rightShift(int n);

        //Shift number to N positions
        void leftShift(int n);


        void sub(LongNumber &B);
        void sub(LongNumber &A, LongNumber &B);
        void sub(LongNumber &B, int startIndexB);
        void sub(LongNumber &A, LongNumber &B, int startIndexA, int startIndexB);

        void multiply(LongNumber &A, LongNumber &B);
        
        void AND(LongNumber &A, LongNumber &B);
        void OR(LongNumber &A, LongNumber &B);
        void XOR(LongNumber &A, LongNumber &B);

        void copyFromUsualNumber(long long number) {
            for (int i = 0; i < LNLength + 1; i++) {
                bitArray[i] = number%2;
                number /= 2;
            }
        }

    public:

        LongNumber(){};

        LongNumber(long long number) {
            copyFromUsualNumber(number);
        }

        LongNumber(const LongNumber &LN) {
            copyArrayFrom(LN);
        }

        bool& operator [] (int i) {
            return bitArray[i];
        }

        LongNumber operator = (LongNumber LN) {
            copyArrayFrom(LN);
            return *this;
        }
        
        char* toBinary(int startIndex=0, int n=LNLength) {
            char* str = new char[n+1];
            for (int i = startIndex; i < n; i++) {
                str[i] = bitArray[i] + 48;
            }
            str[n] = 0;
            return str;
        }

        char* toHex(int startIndex=0, int n=LNLength/4) {
            char* str = new char[n+1];
            char ABC[] = "0123456789ABCDEF";
            for (int i = startIndex; i < n; i++) {
                int index = 0;
                index += bitArray[4*i];
                index += bitArray[4*i+1]*2;
                index += bitArray[4*i+2]*4;
                index += bitArray[4*i+3]*8;
                str[i] = ABC[index];
            }
            str[n] = 0;
            return str;
        }

        long long toInteger(int startIndex=0, int n=LNLength) {
            long long s;
            long long m;
            if (bitArray[LNLength]) {
                m = -1;
                s = -1;
            } else { 
                m = 1;
                s = 0;
            } 
            for (int i = startIndex; i < n; i++) {
                s += m*(bitArray[LNLength] != bitArray[i]);
                m *= 2;
            }
            return s;
        }

        LongNumber operator += (LongNumber LN) {
            add(LN);
            return *this;
        }

        LongNumber operator + (LongNumber LN) {
            LongNumber C(*this);
            C += LN;
            return C;
        }

        LongNumber operator -= (LongNumber LN) {
            sub(LN);
            return *this;
        }

        LongNumber operator - (LongNumber LN) {
            LongNumber C(*this);
            C -= LN;
            return C;
        }

        LongNumber operator >>= (int n) {
            if (n > 0)
                rightShift(n);
            else 
                leftShift(-n);
            return *this;
        }

        LongNumber operator >> (int n) {
            LongNumber C(*this);
            C >>= n;
            return C;
        }

        LongNumber operator <<= (int n) {
            if (n < 0)
                rightShift(-n);
            else 
                leftShift(n);
            return *this;
        }

        LongNumber operator << (int n) {
            LongNumber C(*this);
            C <<= n;
            return C;
        }

        LongNumber operator *= (LongNumber B) {
            multiply(*this, B);
            return *this;
        }
        
        LongNumber operator * (LongNumber B) {
            LongNumber C(*this);
            multiply(C, B);
            return C;
        }

        LongNumber operator &= (LongNumber B) {
            AND(*this, B);
            return *this;
        }

        LongNumber operator & (LongNumber B) {
            LongNumber C(*this);
            AND(C, B);
            return C;
        }

        LongNumber operator |= (LongNumber B) {
            OR(*this, B);
            return *this;
        }

        LongNumber operator | (LongNumber B) {
            LongNumber C(*this);
            OR(C, B);
            return C;
        }

        LongNumber operator ^= (LongNumber B) {
            XOR(*this, B);
            return *this;
        }

        LongNumber operator ^ (LongNumber B) {
            LongNumber C(*this);
            XOR(C, B);
            return C;
        }

        int highestBitWith(bool valueToFind=true) {
            for (int i = LNLength; i > -1; i--) 
                if (bitArray[i] == valueToFind)
                    return i;
            return 0;
        }

        int leastBitWith(bool valueToFind=false) {
            for (int i = 0; i < LNLength + 1; i++) 
                if (bitArray[i] == valueToFind)
                    return i;
            return 0;
        }

        int countBitsWith(bool valueToCount=true) {
            int counter = 0;
            for (int i = 0; i < LNLength + 1; i++) 
                if (bitArray[i] == valueToCount) 
                    counter++;
            return counter;
        }

};

void LongNumber::rightShift(int n) {
    for (int i = 0; i + n < LNLength + 1; i++) 
        bitArray[i] = bitArray[i+n];
    for (int i = LNLength - n + 2; i < LNLength + 1; i++) 
        bitArray[i] = 0;
}

void LongNumber::leftShift(int n) {
    for (int i = LNLength; i - n > -1; i--) 
        bitArray[i] = bitArray[i-n];
    for (int i = 0; i < n; i++) 
        bitArray[i] = 0;
}


void LongNumber::add(LongNumber &B) {
    this->add(*this, B);
}

void LongNumber::add(LongNumber &B, int startIndexB) {
    this->add(*this, B, 0, startIndexB);
}

void LongNumber::add(LongNumber &A, LongNumber &B) {
    this->add(A, B, 0, 0);
}

void LongNumber::add(LongNumber &A, LongNumber &B, int startIndexA, int startIndexB) {
    bool tmp = false;
    for (int i = 0; i + max(startIndexA, startIndexB) < LNLength + 1; i++) {
        if (A.bitArray[i + startIndexB] & B.bitArray[i + startIndexB]) {
            if (tmp) {
                A.bitArray[i] = true;
            } else {
                A.bitArray[i] = false;
                tmp = true;
            }
        } else if (A.bitArray[i] | B.bitArray[i]) {
            if (tmp) {
                A.bitArray[i] = false;
            } else {
                A.bitArray[i] = true;
                tmp = false;
            }
        } else {
            if (tmp) {
                A.bitArray[i] = true;
                tmp = false;
            } else {
                A.bitArray[i] = false;
            }
        }
    }
}


void LongNumber::sub(LongNumber &B) {
    this->sub(*this, B);
}

void LongNumber::sub(LongNumber &B, int startIndexB) {
    this->sub(*this, B, 0, startIndexB);
}

void LongNumber::sub(LongNumber &A, LongNumber &B) {
    this->sub(A, B, 0, 0);
}

void LongNumber::sub(LongNumber &A, LongNumber &B, int startIndexA, int startIndexB) {
    bool tmp = false;
    for (int i = 0; i < LNLength+1; i++) {
        if (A.bitArray[i+startIndexA] & B.bitArray[i+startIndexB]) {
            if (tmp) {
                A.bitArray[i] = true;
            } else {
                A.bitArray[i] = false;
            }
        } else if (A.bitArray[i] & !B.bitArray[i]) {
            if (tmp) {
                A.bitArray[i] = false;
                tmp = false;
            } else {
                A.bitArray[i] = true;
            }
        } else if (!A.bitArray[i] & B.bitArray[i]) {
            if (tmp) {
                A.bitArray[i] = false;
            } else {
                A.bitArray[i] = true;
                tmp = true;
            }
        } else {
            if (tmp) {
                A.bitArray[i] = true;
            } else {
                A.bitArray[i] = false;
            }
        }
    }
}

void LongNumber::multiply(LongNumber &A, LongNumber &B) {
    LongNumber _A(A);
    LongNumber _B(B);
    LongNumber C;

    for (int i = 0; i < LNLength + 1; i++) {
        if (_B.bitArray[0]) 
            C.add(_A);
        _A <<=1;
        _B >>= 1;
    }
    A = C;
}

void LongNumber::AND(LongNumber &A, LongNumber &B) {
    for (int i = 0; i < LNLength + 1; i++) {
        A.bitArray[i] &= B.bitArray[i];
    }
}

void LongNumber::OR(LongNumber &A, LongNumber &B) {
    for (int i = 0; i < LNLength + 1; i++) {
        A.bitArray[i] |= B.bitArray[i];
    }
}

void LongNumber::XOR(LongNumber &A, LongNumber &B) {
    for (int i = 0; i < LNLength + 1; i++) {
        A.bitArray[i] ^= B.bitArray[i];
    }
}

