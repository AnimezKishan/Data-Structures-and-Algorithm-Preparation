class Solution {
    public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int maxElem = nums[0];
        long long maxDiff = 0, triplet = 0;

        for(int i=1; i<n; i++){
            triplet = max(triplet, maxDiff * nums[i]);

            maxDiff = max(maxDiff, (long long)(maxElem - nums[i]));
            maxElem = max(maxElem, nums[i]);
        }

        return triplet;
    }
};