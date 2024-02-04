// Intuition Explaination - https://www.youtube.com/watch?v=3Bp3OVD1EGc&t=13

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length() > n)
            return "";
        
        unordered_map<char, int> mp;
        for(auto &ch:t)
            mp[ch]++;

        int minWindowSize = INT_MAX; 
        int requiredCount = t.length();
        int start_i = 0;
        int i = 0, j = 0;

        while(j < n){
            char ch = s[j];
            if(mp[ch] > 0)
                requiredCount--;
            
            mp[ch] --;

            while(requiredCount == 0){
                int currWindowSize = j-i+1;

                if(minWindowSize > currWindowSize){
                    minWindowSize = currWindowSize;
                    start_i = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0)
                    requiredCount++;
                
                i++;
            }
            j++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);

    }
};