class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        // for each 'd' distance, store the count of it.
        int maxElem = *max_element(begin(nums), end(nums));
        vector<int> distance(maxElem+1, 0);

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int d = abs(nums[j] - nums[i]);
                distance[d]++;
            }
        }

        // iterate through distances and when k becomes zero or less means the kth smallest pair distance falls under that distance
        for(int i=0; i<=maxElem; i++){
            k -= distance[i];

            if( k<=0)
                return i;
        }

        return -1;
    }
};