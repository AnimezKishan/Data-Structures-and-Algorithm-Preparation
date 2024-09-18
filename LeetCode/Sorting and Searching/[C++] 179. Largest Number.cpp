/*
In comparator, concatinate two string numbers and check which one gives larger result
ex: "30" and "3"
30 + 3 or 3 + 30
303 or 330 
330 is greater so 3 is kept earlier in the array. 
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        auto lambda = [&](int &a, int &b) {
            string s1 = to_string(a);
            string s2 = to_string(b);

            if(s1+s2 > s2+s1)
                return true;
            else
                return false;
        };

        sort(nums.begin(), nums.end(), lambda);

        // Edge Case like "00"
        if(nums[0] == 0)
            return "0";

        string ans;
        for(int &num : nums)
            ans += to_string(num);
        
        return ans;
    }
};