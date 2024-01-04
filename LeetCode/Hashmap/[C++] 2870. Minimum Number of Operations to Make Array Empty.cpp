class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        int ans = 0;
        for(auto i:m){
            if(i.second == 1)
                return -1;
            else if(i.second%3 == 0)
                ans += i.second/3;
            else if(i.second%3 == 1)
                ans += (i.second/3 + 1);
            else if(i.second%3 == 2)
                ans += (i.second/3 + 1);
        }

        return ans;
    }
};