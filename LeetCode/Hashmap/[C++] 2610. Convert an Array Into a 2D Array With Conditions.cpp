class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> count(201);

        int maxCount = -1;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;

            if(count[nums[i]] > maxCount)
                maxCount = count[nums[i]];
        }

        vector<vector<int>> ans(maxCount);
        
        for(int i=0;i<count.size();i++){
            int j = 0;
            while(count[i] != 0){
                ans[j++].push_back(i);
                count[i]--;
            }
        }

        return ans;
    }
};