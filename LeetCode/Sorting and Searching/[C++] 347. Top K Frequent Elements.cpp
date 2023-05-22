/*
Using Bucket Sort
1. Store the counting in unordered_map.
2. create a matrix in which row indicates the no. of occurance and each column value of that row represents the no.s that are occuring that much times.
3. Now retrieve as per k elements required. 
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        if(!nums.size())
            return ans;
        //Step 1
        unordered_map<int, int> mp;
        for(auto i:nums)
            mp[i]++;

        //Step 2
        vector<vector<int>> bucket(nums.size()+1);
        for(auto m:mp)
            bucket[m.second].push_back(m.first);
        
        //Step 3
        for(int i=bucket.size()-1;i>=0;--i)
        {
            for(int j=0;j<bucket[i].size();j++)
            {
                ans.push_back(bucket[i][j]);
                if(ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};