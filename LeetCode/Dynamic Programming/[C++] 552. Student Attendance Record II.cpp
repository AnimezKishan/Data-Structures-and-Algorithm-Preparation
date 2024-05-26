class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[100001][3][4];

    int solve(int n, int absentCount, int consecutiveLate) {
        if(absentCount > 1 || consecutiveLate >= 3)
            return 0;
        
        if(n == 0)
            return 1;

        if(dp[n][absentCount][consecutiveLate] != -1)
            return dp[n][absentCount][consecutiveLate];
        
        // Present
        int option1 = solve(n-1, absentCount, 0);
        // Absent
        int option2 = solve(n-1, absentCount+1, 0);
        // Late
        int option3 = solve(n-1, absentCount, consecutiveLate+1);

        return dp[n][absentCount][consecutiveLate] = (((option1 + option2)%MOD)+option3)%MOD;

    }
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0, 0);
    }
};