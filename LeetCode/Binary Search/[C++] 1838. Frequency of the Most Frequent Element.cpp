// Sorting + Binary Search + Prefix Sum.
// windowSum represents what would be the sum if elements of particular indices become nums[target_index].
// Prefix Sum is used here to get the get sum from a starting index to particular index.  

class Solution {
public:
    vector<long> prefixSum;
    int bSearch(int target_idx, int k, vector<int> &nums){
        int s = 0, e = target_idx;
        int mid;
        int result = target_idx;
        while(s <= e)
        {
            mid = s + (e - s)/2;
            long count = target_idx - mid + 1;
            long windowSum = nums[target_idx] * count;
            long currSum = prefixSum[target_idx] - prefixSum[mid] + nums[mid];

            if(windowSum - currSum <= k){
                result = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        return (target_idx - result + 1);
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        prefixSum.resize(nums.size());
        prefixSum[0] = nums[0];

        for(int i=1;i<nums.size();i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }

        int result = 1;
        for(int i=0;i<nums.size();i++){
            int freq = bSearch(i, k, nums);
            result = max(result, freq);
        }

        return result;
    }
};