//Approach 1
// To unset the right-most set bit of an integer -> n = (n & (n-1))
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            n &= n-1;
            count++;
        }
        return count;
    }
};


//Approach 2
/*
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count += n&1;
            n = n>>1;
        }
        return count;
    }
};
*/