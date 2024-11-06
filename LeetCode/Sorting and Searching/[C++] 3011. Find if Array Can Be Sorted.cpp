class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        unordered_map<int, int> setBits;

        for(int &num : nums) {
            int temp = num;
            if(setBits.find(temp) == setBits.end()){
                while(temp){
                    setBits[num] += temp & 1;
                    temp = temp>>1;
                }
            }
        }

        // Bubble Sort O(N^2)
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n-i-1; j++) {
                if(nums[j] > nums[j+1] && setBits[nums[j]] == setBits[nums[j+1]])
                    swap(nums[j], nums[j+1]);
            }
        }

        return is_sorted(begin(nums), end(nums));
    }
};