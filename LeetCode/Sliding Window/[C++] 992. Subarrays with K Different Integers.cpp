// Count of SubArrays with K Distinct Elements = Count of SubArrays with At Most K Distinct Elements - Count of SubArrays with At Most K-1 Distinct Elements

class Solution {
public:
    int n, ans, i = 0, j = 0;
    int slidingWindow(vector<int> &nums, int k){
        unordered_map<int, int> m;
        i = 0, j = 0, ans = 0;

        while(j<n){
            m[nums[j]]++;
            while(m.size() > k){
                if(m[nums[i]] == 1)
                    m.erase(nums[i]);
                else
                    m[nums[i]]--;
                
                i++;
            }

            ans += (j-i+1);
            j++;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        n = nums.size();

        int atMostK = slidingWindow(nums, k), atMostKMinus1 = slidingWindow(nums, k-1);

        return atMostK - atMostKMinus1;
    }
};