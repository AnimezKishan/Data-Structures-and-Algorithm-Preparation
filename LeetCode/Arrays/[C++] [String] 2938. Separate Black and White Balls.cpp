// whenever you encounter a white ball(0), check how many black balls(1) appeared in past and swap with each.
class Solution {
public:
    long long minimumSteps(string s) {
        long long black = 0, ans = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1')
                black++;
            else
                ans += black;
        }

        return ans;
    }
};