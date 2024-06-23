/*
For a subarray to be valid here,
Max and Min element of the subarray should have abs less than or equal to limit.
*/

class Solution {
public:
    typedef pair<int, int> P;
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        int i = 0, j = 0, ans = 0;
        priority_queue<P> maxi;
        priority_queue<P, vector<P>, greater<P>> mini;

        while(j < n) {
            maxi.push({nums[j], j});   
            mini.push({nums[j], j});   
            while(abs(maxi.top().first - mini.top().first) > limit){
                i = min(maxi.top().second, mini.top().second) + 1;

                // From Heaps, Remove all elements that occur previous to the current window i.e. elements appearing before current ith index.

                while(maxi.top().second < i)
                    maxi.pop();

                while(mini.top().second < i)
                    mini.pop();
            }

            ans = max(ans, (j-i+1));
            j++;
        }

        return ans;
    }
};