class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n =boxes.length();

        vector<int> ans(n, 0);
        int cumValue = 0; // cummulative sum
        int cumSum = 0; // sum of cummulative sum

        // left to right
        for(int i=0; i<n; i++) {
            ans[i] = cumSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumSum += cumValue;
        }

        // right to left
        cumValue = 0;
        cumSum = 0;
        for(int i=n-1; i>=0; i--) {
            ans[i] += cumSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumSum += cumValue;
        }

        return ans;
    }
};