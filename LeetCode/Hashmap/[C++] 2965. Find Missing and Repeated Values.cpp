class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<int> mp((n*n)+1, 0);
    
            vector<int> ans(2, 0);
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    mp[grid[i][j]]++;
    
                    if(mp[grid[i][j]] == 2)
                        ans[0] = grid[i][j];
                }
            }
    
            for(int i=1; i<=(n*n); i++) {
                if(!mp[i]){
                    ans[1] = i;
                    return ans;
                }
            }
    
            return ans;
        }
    };