// Intuition - https://leetcode.com/problems/bitwise-and-of-numbers-range/description/comments/2053637

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        long long shift = 0;
        
        // find longest common prefix
        while(left != right){
            left = left >> 1;
            right = right >> 1;
            shift++;
        }

        return left << shift;
    } 
};