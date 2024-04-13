class Solution {
public:
    unordered_map<char, int> m;
    int romanToInt(string s) {
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0;
        int n = s.length()-1;
        for(int i=n;i>=0;i--){
            if(i<n && m[s[i]] < m[s[i+1]])
                ans -= m[s[i]];
            else
                ans += m[s[i]];
        }

        return ans;
    }
};