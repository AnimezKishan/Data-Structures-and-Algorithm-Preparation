class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0;i<m;i++)
            for(int j=1;j<n;j++)
                matrix[i][j] += matrix[i][j-1];

        int ans = 0;
        for(int start=0;start<n;start++){

            for(int j=start;j<n;j++){
                unordered_map<int, int> mp;
                mp[0] = 1;
                int pSum = 0;
                for(int row=0;row<m;row++){
                    pSum += start == 0 ? matrix[row][j] : (matrix[row][j] - matrix[row][start-1]);

                    if(mp.count(pSum-target))
                        ans += mp[pSum-target];
                    
                    mp[pSum]++;
                }
            }
        }

        return ans;
    }
};