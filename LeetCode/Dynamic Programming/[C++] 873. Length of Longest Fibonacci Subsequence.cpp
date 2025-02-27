class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size();
            unordered_map<int, int> mp;
            vector<vector<int>> dp(n, vector<int>(n, -1));
            
            for (int i = 0; i < n; i++) {
                mp[arr[i]] = i;
            }
            
            int max_length = 0;
            for (int j = 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int length = solve(j, k, arr, mp, dp);
                    if (length >= 3) {
                        max_length = max(max_length, length);
                    }
                }
            }
            return max_length >= 3 ? max_length : 0;
        }
        
    private:
        int solve(int j, int k, const vector<int>& arr, const unordered_map<int, int>& mp, vector<vector<int>>& dp) {
            if (dp[j][k] != -1) return dp[j][k];
            
            int target = arr[k] - arr[j];
            if (mp.count(target) && mp.at(target) < j) {
                int i = mp.at(target);
                dp[j][k] = solve(i, j, arr, mp, dp) + 1;
                return dp[j][k];
            }
            
            return dp[j][k] = 2;
        }
    };