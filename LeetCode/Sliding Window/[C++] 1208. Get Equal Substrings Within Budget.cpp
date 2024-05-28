class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();

        int i = 0, j = 0, ans = 0, currCost = 0;

        while(j<n){
            currCost += abs(s[j] - t[j]);

            while(currCost > maxCost){
                currCost -= abs(s[i] - t[i]);
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};