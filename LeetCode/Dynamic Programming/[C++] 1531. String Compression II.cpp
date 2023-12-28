int dp[101][27][101][101]; // Defined outside class, to store in heap.
class Solution {
public:
    int n;
    int solve(string& s, int i, int prev_char, int freq, int k){
        if(k < 0)
            return INT_MAX;
        
        if(i >= n)
            return 0;

        if(dp[i][prev_char][freq][k] != -1)
            return dp[i][prev_char][freq][k];
        
        int delete_i = 0, take_i = 0;

        delete_i = solve(s, i+1, prev_char, freq, k-1);

        if(s[i]-'a' != prev_char){
             take_i = 1+solve(s, i+1, s[i]-'a', 1, k);
        }
        else{
            /*
            we only have 4 options to reduce the length:
                a, a2~a9, a10~99, a100
            */
            int one_more_addition = 0;
            if(freq == 1 || freq == 9 || freq == 99)
                one_more_addition = 1;
            
            take_i = one_more_addition + solve(s, i+1, prev_char, freq+1, k);
        }

        return dp[i][prev_char][freq][k] = min(delete_i, take_i);
    }

    int getLengthOfOptimalCompression(string s, int k) {
        n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 26, 0, k);
    }
};