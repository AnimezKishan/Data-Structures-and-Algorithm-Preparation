class Solution {
public:
    int n;
    int dp[101][101];
    int countSteps(int rIndex, int i){
        int clockwise = abs(i - rIndex);
        int antiClockwise = n - clockwise;

        return min(clockwise, antiClockwise);
    }

    int solve(int rIndex, int kIndex, string &ring, string &key){
        if(kIndex >= key.length())
            return 0;
        
        if(dp[rIndex][kIndex] != -1)
            return dp[rIndex][kIndex];

        int ans = INT_MAX;
        for(int i=0;i<ring.length();i++){
            if(ring[i] == key[kIndex]){
                int steps = 1 + countSteps(rIndex, i);
                int totalSteps = steps + solve(i, kIndex+1, ring, key);
                ans = min(ans, totalSteps);
            }
        }

        return dp[rIndex][kIndex] = ans;
    }

    int findRotateSteps(string ring, string key) {
        n = ring.length();    
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, ring, key);
    }
};