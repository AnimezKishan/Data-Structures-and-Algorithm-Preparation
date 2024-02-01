class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(begin(nums), end(nums));

        for(int i=0;i<n;i+=3){
            if(nums[i+2]-nums[i] <= k){
                vector<int> temp(begin(nums)+i, begin(nums)+i+3);
                ans.push_back(temp);
            }
            else{
                return {};
            }
        }

        return ans;
    }
};