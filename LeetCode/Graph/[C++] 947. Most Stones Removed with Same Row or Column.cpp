/*
Each group leaves one element and others get canceled out
So, no. of stones getting removed = total no. of stones - no. of groups(as only a element remains)
*/

class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& stones, int idx, vector<bool> &visited){
        visited[idx] = true;
        int row = stones[idx][0];
        int col = stones[idx][1];

        for(int i=0; i<n; i++){
            if(!visited[i] && (stones[i][0] == row || stones[i][1] == col))
                dfs(stones, i, visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<bool> visited(n, false);

        int groups = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(stones, i, visited);
                groups++;
            }
        }

        return n - groups;
    }
};