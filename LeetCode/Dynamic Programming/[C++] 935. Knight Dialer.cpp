class Solution {
public:
    int MOD = 1e9 + 7;
    //keeps track of which cell can visit how many cells.
    vector<vector<int>> adjList = {
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {3,9,0},
        {},
        {7,1,0},
        {2,6},
        {1,3},
        {2,4}
    };

    int dp[5001][10];

    int solve(int n, int cell){
        if(n == 0)
            return 1;

        if(dp[n][cell] != -1)
            return dp[n][cell];

        
        int ans = 0;
        for(auto &nextCell: adjList[cell])
            ans = (ans + solve(n-1, nextCell)) % MOD;
        
        return dp[n][cell] = ans;
    }

    int knightDialer(int n) {
        int ans = 0;
        memset(dp, -1, sizeof(dp));

        for(int cell = 0; cell<=9;cell++)
            ans = (ans + solve(n-1, cell)) % MOD;
        
        return ans;
    }
};