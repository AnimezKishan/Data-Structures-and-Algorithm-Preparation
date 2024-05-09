class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(begin(happiness), end(happiness), greater<int>());

        long long ans = 0;
        for(int i=0;i<k;i++)
            ans += (happiness[i] - i < 0) ? 0 : happiness[i] - i;
        
        return ans;
    }
};