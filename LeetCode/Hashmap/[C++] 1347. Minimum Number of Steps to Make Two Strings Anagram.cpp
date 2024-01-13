class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count1(26, 0), count2(26, 0);
        for(int i=0;i<s.length();i++){
            count1[s[i]-'a']++;
            count2[t[i]-'a']++;
        }

        int ans = 0;
        for(int i=0;i<26;i++){
            if(count2[i] > count1[i])
                continue;
            
            else
                ans += count1[i] - count2[i]; 
        }

        return ans;
    }
};