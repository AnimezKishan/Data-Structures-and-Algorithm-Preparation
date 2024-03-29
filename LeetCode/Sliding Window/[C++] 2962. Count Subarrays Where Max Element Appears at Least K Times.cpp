// Total No.s of Subarrays - Subarrays with max element with less than k occurance.

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        /*
        static_cast<long long int>(n) explicitly converts the int variable n to a long long int. 
        This ensures that the multiplication n * (n + 1) is performed using the larger data type long long int, preventing overflow when n is large.
        */
        long long int total = static_cast<long long int>(n) * (n + 1) / 2;

        int maxElem = *max_element(nums.begin(), nums.end()), maxCount = 0;
        long long lessOccurance = 0;

        int i = 0, j = 0;
        while(j<n){
            if(nums[j] == maxElem)
                maxCount++;
            
            while(maxCount >= k){
                if(nums[i] == maxElem)
                    maxCount--;
                i++;
            }

            lessOccurance += (j-i+1);
            j++;
        }

        long long ans = total - lessOccurance;
        return ans;
    }
};