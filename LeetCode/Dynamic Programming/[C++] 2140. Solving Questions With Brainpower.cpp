class Solution {
    public:
        int n;
        long long dp[100000];
        long long solve(int idx, vector<vector<int>>& questions) {
            if(idx >= n) {
                return 0;
            }
    
            if (dp[idx] != -1)
                return dp[idx];
    
            int currPoints = questions[idx][0];
            int currSkip = questions[idx][1];
    
            long long take = 0, not_take = 0;
            take = currPoints + solve(idx + currSkip + 1, questions);
            not_take = solve(idx+1, questions);
    
            return dp[idx] = max(take, not_take);
        }
        long long mostPoints(vector<vector<int>>& questions) {
            n = questions.size();
            memset(dp, -1, sizeof(dp));
            return solve(0, questions);
        }
    };