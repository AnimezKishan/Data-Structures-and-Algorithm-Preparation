//Pre - Requisite --> 392. Is Subsequence

class Solution {
public:
    int n;
    int dp[1001][1001];

    static bool compare(string &word1, string &word2){
        return word1.length() < word2.length();
    }

    bool isPred(string &prev, string &curr){
        int M = prev.length();
        int N = curr.length();

        if(M >= N || N-M != 1)
            return false;
        
        int i = 0, j = 0;
        while(i<M && j<N){
            if(prev[i] == curr[j])
                i++;
            j++;
        }

        return i == M;
    }

    int solve(vector<string> &words, int prev_idx, int curr_idx)
    {
        if(curr_idx == n)
            return 0;
        
        if(prev_idx != -1 && dp[prev_idx][curr_idx] != -1)
            return dp[prev_idx][curr_idx];
        
        int taken = 0, not_taken = 0;

        if(prev_idx == -1 || isPred(words[prev_idx], words[curr_idx])){
            taken = 1 + solve(words, curr_idx, curr_idx+1);
        }

        not_taken = solve(words, prev_idx, curr_idx+1);

        if(prev_idx != -1)
            dp[prev_idx][curr_idx] = max(taken, not_taken);
        
        return max(taken, not_taken);
    }

    int longestStrChain(vector<string>& words) {
        memset(dp, -1, sizeof(dp));

        n = words.size();
        sort(begin(words), end(words), compare);

        return solve(words, -1, 0);
    }
};