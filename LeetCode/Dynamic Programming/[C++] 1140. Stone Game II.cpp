class Solution {
public:
    int n; 
    int dp[2][101][101];
    int solveForAlice(vector<int> &piles, int person, int idx, int M) {
        if(idx >= n)
            return 0;

        if(dp[person][idx][M] != -1)
            return dp[person][idx][M];

        int result = (person == 1) ? -1 : INT_MAX;
        int stones = 0;
        for(int i=1; i<=min(2*M, n-idx); i++){
            stones += piles[i+idx-1];
            if(person == 1) {
                result = max(result, stones + solveForAlice(piles, 0, idx+i, max(M, i)));
            }
            else
                result = min(result, solveForAlice(piles, 1, idx+i, max(M, i)));
        }

        return dp[person][idx][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));

        return solveForAlice(piles, 1, 0, 1);
    }
};