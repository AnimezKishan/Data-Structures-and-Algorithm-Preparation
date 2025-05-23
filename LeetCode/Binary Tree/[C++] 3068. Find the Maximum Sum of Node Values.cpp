// Greedy 

class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0;
        // count of changes made should be of even no. of times
        int count = 0;
        // If, count comes odd, which node should be taken such that ans would be maximum. 
        ll mini = INT_MAX;
        for(ll num : nums){
            if((num ^ k) > num){
                sum += (num ^ k);
                count++; 
            }
            else 
                sum += num;

            // take among nodes such that difference between a node's value and value XOR k is minimum.
            mini = min(mini, abs(num - (num ^ k)));
        }

        if(count % 2 == 0)
            return sum;
        else
            return (sum - mini);
    }
};
