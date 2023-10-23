/*
To be a power of 4,
    -> should be a power of 2
    -> (n-1) is divisible by 3
        e.x. -> 4-1 = 3, 16-1 = 15, 64-1 = 63....

*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;
        
        else if((n&(n-1)) == 0 && (n-1)%3 == 0)
            return true;
        
        else
            return false;
    }
};