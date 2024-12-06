class Solution {
public:
    unordered_map<int, bool> mp;
    int maxCount(vector<int>& banned, int n, int maxSum) {
        for(int &i : banned) {
            if(i <= n)
                mp[i] = true;
        }

        int currSum = 0;
        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(mp.find(i) == mp.end() && currSum + i <= maxSum) {
                ans++;
                currSum += i;
            }
        }

        return ans;
    }
};