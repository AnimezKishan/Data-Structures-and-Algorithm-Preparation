class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> m;

        for(int i=0;i<n;i++)
            m[nums[i]]++;
        
        for(int i=0;i<n;i++) {
            /* 
            Check if this element is the starting point of a subsequence. 
            To check this, simply look for arr[i]-1 in the hash, if not found, then this is the first element a subsequence.
            Then check for the length of the subsequence.
            */
            if(!m[nums[i]-1]){
                int tempLen = 1;
                int j = 1;
                while(m[nums[i] + j]){
                    tempLen++;
                    j++;
                }
                ans = max(ans, tempLen);
            }
        }

        return ans;
    }
};