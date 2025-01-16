class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        int XORs = 0;
        if(n2 % 2 != 0) {
            for(int i=0; i<n1; i++)
                XORs ^= nums1[i];
        }
        if(n1 % 2 != 0) {
            for(int i=0; i<n2; i++)
                XORs ^= nums2[i];
        }
        
        return XORs;
    }
};