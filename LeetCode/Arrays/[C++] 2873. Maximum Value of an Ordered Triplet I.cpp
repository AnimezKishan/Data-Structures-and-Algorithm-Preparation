// Brute force
class Solution {
    public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        
        long long ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    ans = max(ans, (long long)((long long)(nums[i] - nums[j]) * nums[k]));
                }
            } 
        }

        return ans;
    }
};

// Optimized - Three Pointers
class Solution {
    public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int maxElem = nums[0];
        long long maxDiff = 0, maxTriplet = 0;
        for(int i=1; i<n; i++) {
            maxTriplet = max(maxTriplet, (long long)(maxDiff * nums[i]));

            maxElem = max(maxElem, nums[i]);

            maxDiff = max(maxDiff, (long long)(maxElem - nums[i]));
        }

        return maxTriplet;
    }
};