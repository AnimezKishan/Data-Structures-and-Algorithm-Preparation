// If XOR is done with flipped version of itself, it gives the maximum value possible. 
// E.x. : Suppose, 0 ^ 1 ^ 1 ^ 3 = 3. 3 = 111, flip of 3 = 000. So, 111 ^ 000 => 111 

// ** IMP: Flipped version = current number ^ set bits with same bits as of current number/maximumBit.
// ** IMP: Set bits of n bits = 2^n -1 = (1<<n) - 1

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int prefixXor = nums[0];
        for(int i=1; i<n; i++)
            prefixXor = nums[i] ^ prefixXor;
        
        vector<int> ans(n);
        int setBit = (1 << maximumBit) - 1;
        for(int i=0; i<n; i++){
            int k = prefixXor ^ setBit;
            ans[i] = k;

            // remove last element
            prefixXor ^= nums[n-i-1];
        }

        return ans;
    }
};