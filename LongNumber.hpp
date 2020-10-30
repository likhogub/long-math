#define LNLength 2048
#include <iostream>
using namespace std;

class LongNumber {
    private:
        bool bitArray[LNLength] = {0};

        void copyArrayFrom(LongNumber &LN) {
            for (int i = 0; i < LNLength; i++)
                bitArray[i] = LN.bitArray[i];
        }

        void addToArray(LongNumber &LN) {
            bool tmp = false;
            for (int i = 0; i < LNLength; i++) {
                if (bitArray[i] & LN.bitArray[i]) {
                    if (tmp) {
                        bitArray[i] = true;
                    } else {
                        bitArray[i] = false;
                        tmp = true;
                    }
                } else if (bitArray[i] | LN.bitArray[i]) {
                    if (tmp) {
                        bitArray[i] = false;
                    } else {
                        bitArray[i] = true;
                        tmp = false;
                    }
                } else {
                    if (tmp) {
                        bitArray[i] = true;
                        tmp = false;
                    } else {
                        bitArray[i] = false;
                    }
                }
            }
        }

        void subFromArray(LongNumber &LN) {
            bool tmp = false;
            for (int i = 0; i < LNLength; i++) {
                if (bitArray[i] & LN.bitArray[i]) {
                    if (tmp) {
                        bitArray[i] = true;
                    } else {
                        bitArray[i] = false;
                    }
                } else if (bitArray[i] & !LN.bitArray[i]) {
                    if (tmp) {
                        bitArray[i] = false;
                        tmp = false;
                    } else {
                        bitArray[i] = true;
                    }
                } else if (!bitArray[i] & LN.bitArray[i]) {
                    if (tmp) {
                        bitArray[i] = false;
                    } else {
                        bitArray[i] = true;
                        tmp = true;
                    }
                } else {
                    if (tmp) {
                        bitArray[i] = true;
                    } else {
                        bitArray[i] = false;
                    }
                }
            }
        }

        void multiplyToArray(LongNumber &LN) {
            
        }

    public:

        LongNumber(){};

        LongNumber(LongNumber &LN) {
            copyArrayFrom(LN);
        }

        bool& operator [] (int i) {
            return bitArray[i];
        }

        LongNumber operator = (LongNumber &LN) {
            copyArrayFrom(LN);
            return *this;
        }
        
        LongNumber operator = (LongNumber LN) {
            copyArrayFrom(LN);
            return *this;
        }

        char* toBinaryString(int startIndex=0, int n=LNLength) {
            char* str = new char[n+1];
            for (int i = startIndex; i < n; i++) {
                str[i] = bitArray[i] + 48;
            }
            str[n] = 0;
            return str;
        }

        unsigned long long toInteger(int startIndex=0, int n=LNLength) {
            unsigned long long s = 0;
            int m = 1;
            for (int i = startIndex; i < n; i++) {
                s += m*bitArray[i];
                m *= 2;
            }
            return s;
        }

        LongNumber operator += (LongNumber &LN) {
            addToArray(LN);
            return *this;
        }

        LongNumber operator -= (LongNumber &LN) {
            subFromArray(LN);
            return *this;
        }

        LongNumber operator *= (LongNumber &LN) {
            multiplyToArray(LN);
            return *this;
        }


};

