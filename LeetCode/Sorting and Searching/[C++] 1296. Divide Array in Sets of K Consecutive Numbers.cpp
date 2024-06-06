// Similar to 846. Hand of Straights

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k || n % k != 0)
            return 0;
        
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;

        for(int &num : nums)
            m[num]++;
        
        for(int &num : nums){
            int tempSize = k;

            if(!m[num])
                continue;
            
            while(tempSize && m[num]){
                tempSize--;
                m[num]--;
                num++;
            }

            if(tempSize)
                return 0;
        }

        return 1;
    }
};