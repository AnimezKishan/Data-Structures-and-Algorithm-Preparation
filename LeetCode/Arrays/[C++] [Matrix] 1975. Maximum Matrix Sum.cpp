/*
-> find absolute sum of matrix
-> find absolute smallest value in the matrix
-> count no. of negative values
-> if it's even, then all negative no.s can be turned into positive
-> else, then we can make the smallest number in the matrix as -ve and then return sum
*/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int mini = INT_MAX, negativeCount = 0;
        
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] < 0)
                    negativeCount++;
                sum += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
            }
        }

        if(negativeCount & 1) 
            return sum - (mini*2);
        else
            return sum;
    }
};