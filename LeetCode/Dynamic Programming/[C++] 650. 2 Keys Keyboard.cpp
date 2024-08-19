class Solution {
public:
    int dp[1001][1001];
    int solve(int currA, int clipBoard, int n) {
        if(currA == n)
            return 0;

        if(currA > n)
            return 100000;

        if(dp[currA][clipBoard] != -1)
            return dp[currA][clipBoard];
        
        int copyAllPaste = 2 + solve(currA + currA, currA, n);
        int paste = 1 + solve(currA + clipBoard, clipBoard, n);

        return dp[currA][clipBoard] = min(copyAllPaste, paste);
    }
    int minSteps(int n) {
        if(n == 1)
            return 0;
        
        memset(dp, -1, sizeof(dp));

        return 1 + solve(1, 1, n);
    }
};