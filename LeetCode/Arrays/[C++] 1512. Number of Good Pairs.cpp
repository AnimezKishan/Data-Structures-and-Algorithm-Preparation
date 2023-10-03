/*
Use of Combination
No. of ways to make pair (2 element) from n elements -> nCr , here r=2, => nC2

nC2 => n! / (2! * (n-2)!) => (n * (n-1)!) / 2
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i:nums)
            m[i]++;
        
        int ans = 0;
        for(auto i:m)
        {
            if(i.second > 1)
            {
                ans += (i.second*(i.second-1))/2;
            }
        }

        return ans;
    }
};