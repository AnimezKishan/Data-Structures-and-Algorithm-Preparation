class Solution {
public:
    int dp[301][5001];
    int solve(vector<int>& coins, int n, int amount){
        //base cases
        //if no coins left, so no possible solution
        if(n == 0) 
            return 0;

        //a solution is found
        if(amount == 0)
            return 1;

        if(dp[n][amount] != -1)
            return dp[n][amount];
        
        //if coin is greater than the remaining amount, move to next coin
        if(coins[n-1] > amount)
            return dp[n][amount] = solve(coins, n-1, amount);
        
        //check for a solution in a coin, then move to next coin
        return dp[n][amount] = solve(coins, n, amount-coins[n-1]) + solve(coins, n-1, amount);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));
        if(amount == 0)
            return 1;
        
        if(n == 0)
            return 0;
        
        return solve(coins, n, amount);
    }
};