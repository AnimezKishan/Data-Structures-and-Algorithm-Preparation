class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;

        // get the maximum occurance of a pattern, and to maintain the pattern flipping is being done. 
        int ans = 0;
        for(int i=0; i<matrix.size(); i++) {
            string curr = "";
            for(int j=0; j<matrix[0].size(); j++) {
                // if first bit of row is 0, store as it is.
                if(matrix[i][0] == 0) {
                    curr += to_string(matrix[i][j]);
                }
                //otherwise, store the flipped version of the row.
                else{
                    curr += to_string(matrix[i][j] == 0 ? 1 : 0);
                }
            }
            mp[curr]++;
            ans = max(ans, mp[curr]);
        }

        return ans;
    }
};