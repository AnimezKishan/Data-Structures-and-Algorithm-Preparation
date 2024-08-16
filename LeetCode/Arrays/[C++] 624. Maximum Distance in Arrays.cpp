class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int prevMin = arrays[0][0];
        int prevMax = arrays[0][arrays[0].size()-1];

        int ans = INT_MIN;
        for(int i=1; i<arrays.size(); i++){
            int currMin = arrays[i][0];
            int currMax = arrays[i][arrays[i].size()-1];

            ans = max(ans, max(currMax-prevMin, prevMax-currMin));

            prevMin = min(prevMin, currMin);
            prevMax = max(prevMax, currMax);
        }

        return ans;
    }
};