class Solution {
public:
    bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit) {
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit) {
        return x &= ~(1 << bit);
    }

    int minimizeXor(int num1, int num2) {
        int x = num1;

        int setBitCount = __builtin_popcount(num2);
        int currBitCount = __builtin_popcount(x);

        int bit = 0;
        if(currBitCount < setBitCount) {
            while(currBitCount < setBitCount) {
                if(!isSet(x, bit)){
                    setBit(x, bit);
                    currBitCount++;
                }
                bit++;
            }
        }
        else if(currBitCount > setBitCount) {
            while(currBitCount > setBitCount) {
                if(isSet(x, bit)){
                    unsetBit(x, bit);
                    currBitCount--;
                }
                bit++;
            }
        }
        
        return x;
    }
};