/*
Example n = 8
8 -> 1000
7 -> 0111

1000 & 0111 => 0
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        if((n&(n-1)) == 0)
            return true;
        return false;
    }
};


// One-Liner
/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && !(n & (n-1)));
    }
};
*/