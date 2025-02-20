// cantor diagonal argument
/*
Iterate through the array, and for each number, check number['index of the number'] and append in ans the opposite of whats there.

This way, we will create a unique string which doesn't already exists in the vector.
The idea is that a new binary string can only be new if it has at least 1 bit that's 
different compared to every other binary string. By taking the opposite of the bit at 
nums[index][index], you guarantee that the result has at least 1 different bit compared to 
every other string!
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;

        for(int i=0;i<nums.size();i++){
            if(nums[i][i] == '0')  
                ans.push_back('1');
            else
                ans.push_back('0');
        }

        return ans;
    }
};

// Recursive Approach
/*
class Solution {
public:
    void solve(int i, string currStr, string &missingStr, int n, unordered_map<string, bool> &mp) {
        if(i == n) {
            if(mp.find(currStr) == mp.end())
                missingStr = currStr;
            return;
        }

        for(char ch='0'; ch<='1'; ch++) {
            solve(i+1, currStr+ch, missingStr, n, mp);
            if(missingStr != "")
                return;
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].length();
        unordered_map<string, bool> mp;
        for(string &s : nums) {
            mp[s] = true;
        }
        
        string missingString = "";
        solve(0, "", missingString, n, mp);
        return missingString;
    }
};
*/