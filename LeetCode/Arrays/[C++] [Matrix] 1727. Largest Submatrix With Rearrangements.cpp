/* 
Pre-Requiste - 
    84. Largest Rectangle in Histogram 
    85. Maximal Rectangle.
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] != 0){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }

        for(int i=0;i<matrix.size();i++)
            sort(begin(matrix[i]), end(matrix[i]), greater<int>());

        int ans = INT_MIN;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                int l = matrix[i][j];
                int b = j+1;
                ans = max(ans, l*b);
            }
        }

        return ans;
    }
};