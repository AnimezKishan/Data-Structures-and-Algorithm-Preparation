// Similar Problems : Leetcode - 561, Leetcode - 1877, Leetcode - 2740

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n =weights.size();

        int m = n-1;
        vector<int> pairSum(m, 0);
        for(int i=0; i<m; i++) {
            pairSum[i] = weights[i] + weights[i+1];
        }

        sort(begin(pairSum), end(pairSum));
        long long minSum = 0;
        long long maxSum = 0;
        for(int i=0; i<k-1; i++) {
            maxSum += pairSum[m-i-1];
            minSum += pairSum[i];
        }

        return maxSum - minSum;
    }
};