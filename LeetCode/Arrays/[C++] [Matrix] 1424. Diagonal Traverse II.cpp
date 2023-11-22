// Notice that numbers with equal sums of row and column indexes belong to the same diagonal.

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> mp;

        for(int i=0;i<nums.size();i++){
            for(int j = 0;j<nums[i].size();j++){
                mp[i+j].push_back(nums[i][j]);
            }
        }

        vector<int> ans;
        for(auto i:mp){
            for(int j = i.second.size()-1;j>=0;j--){
                ans.push_back(i.second[j]);
            }
        }

        return ans;
    }
};