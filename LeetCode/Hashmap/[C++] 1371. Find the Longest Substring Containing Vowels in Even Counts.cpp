// Similar to Commulative Sum + Hashmap

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string, int> mp;

        vector<int> vowelCount(5, 0);

        string currVowelCount = "00000";
        mp[currVowelCount] = -1;
        int ans = 0;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'a')
                vowelCount[0] = (vowelCount[0]+1) % 2;
            else if(s[i] == 'e')
                vowelCount[1] = (vowelCount[1]+1) % 2;
            else if(s[i] == 'i')
                vowelCount[2] = (vowelCount[2]+1) % 2;
            else if(s[i] == 'o')
                vowelCount[3] = (vowelCount[3]+1) % 2;
            else if(s[i] == 'u')
                vowelCount[4] = (vowelCount[4]+1) % 2;

            currVowelCount = "";
            for(int j=0; j<5; j++)
                currVowelCount += to_string(vowelCount[j]);
            
            if(mp.find(currVowelCount) != mp.end())
                ans = max(ans, i - mp[currVowelCount]);
            else
                mp[currVowelCount] = i;
        }

        return ans;
    }
};