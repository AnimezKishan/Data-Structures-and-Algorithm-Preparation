class Solution {
public:
    int dp[1001][1001];
    int solve(int idx, vector<vector<int>>& books, int &W, int maxH, int currW){
        if(idx >= books.size())
            return maxH;

        if(dp[idx][currW] != -1)
            return dp[idx][currW];
        
        int bookW = books[idx][0];        
        int bookH = books[idx][1];        
        int keep = INT_MAX, skip = INT_MAX;

        // keep the book if remaining width is sufficient (include the curr book in shelf and calculate max height from books in shelf)
        if(bookW <= currW){
            keep = solve(idx+1, books, W, max(maxH, bookH), currW-bookW);
        }
        // skip to next shelf (add the max height of curr shelf and add the curr book into the next shelf)
        skip = maxH + solve(idx+1, books, W, bookH, W-bookW);

        return dp[idx][currW] = min(keep, skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, -1, sizeof(dp));
        return solve(0, books, shelfWidth, 0, shelfWidth);
    }
};