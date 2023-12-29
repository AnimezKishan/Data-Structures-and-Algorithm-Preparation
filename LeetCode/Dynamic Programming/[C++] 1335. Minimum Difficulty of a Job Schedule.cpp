class Solution {
public:
    int n;
    int dp[301][11];
    int solve(vector<int>& j, int idx, int d){
        if(d == 1){
            return *max_element(begin(j) + idx, end(j));
        }
        if(dp[idx][d] != -1)
            return dp[idx][d];

        int maxD = INT_MIN;
        int finalResult = INT_MAX;

        for(int i=idx;i<=n-d;i++){
            maxD = max(maxD, j[i]);
            int result = maxD + solve(j, i+1, d-1);
            finalResult = min(finalResult, result);
        }

        return dp[idx][d] = finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        memset(dp, -1, sizeof(dp));

        if(n < d)
            return -1;
        
        return solve(jobDifficulty, 0, d);
    }
};