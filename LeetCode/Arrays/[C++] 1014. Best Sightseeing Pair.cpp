// Try to think about rearranged formula, (values[i] + i) + (values[j] - j) instead of values[i] + values[j] + i - j.

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxPrev = values[0];
        int ans = INT_MIN;
        for(int i=1; i<values.size(); i++) {
            ans = max(ans, (maxPrev + (values[i] - i)));
            maxPrev = max(maxPrev, values[i] + i);
        }

        return ans;
    }
};