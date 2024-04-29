class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        // Find XOR of all elements of array
        int xorAll = nums[0];
        for(int i=1;i<nums.size();i++)
            xorAll ^= nums[i];
        
        // Decimal to Binary + no. of distinct elements between binary of k and xorAll
        int count = 0;
        while(k || xorAll){
            if((k % 2) != (xorAll % 2))
                count++;
            
            k /= 2;
            xorAll /= 2;
        }
        
        return count;
    }
};