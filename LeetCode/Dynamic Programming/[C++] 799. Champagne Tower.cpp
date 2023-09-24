class Solution {
public:
    vector<vector<double>> dp{101, vector<double>(101, -1)};

    double solve(int i, int j, int poured){
        //edge cases
        if(i<0 || j<0 || i<j)
            return 0.0;
        
        //base case
        if(i == 0 && j == 0)
            return poured;
        
        //memoization
        if(dp[i][j] != -1)
            return dp[i][j];
        
        //how much it gets champagne from it's upper left glass
        double prev_left = (solve(i-1, j-1, poured)-1)/2.0;

        //how much it gets champagne from it's upper right glass
        double prev_right = (solve(i-1, j, poured)-1)/2.0;

        if(prev_left < 0)
            prev_left = 0.0;
        
        if(prev_right < 0)
            prev_right = 0.0;
        
        return dp[i][j] = prev_left + prev_right;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        // min() used as it's mentioned "A glass at the bottom row has its excess champagne fall on the floor."
        return min(1.0, solve(query_row, query_glass, poured));
    }
};