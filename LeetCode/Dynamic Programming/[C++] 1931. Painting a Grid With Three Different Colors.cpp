class Solution {
public:
    int M, N;
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    void generateStates(int i, char prev, string currState, vector<string> &states) {
        if(i >= M) {
            states.push_back(currState);
            return;
        }

        for(char ch : {'R', 'G', 'B'}) {
            if(prev == '$' || prev != ch) {
                currState += ch;
                generateStates(i+1, ch, currState, states);
                currState.pop_back();
            }
        }
    }

    int solve(int i, int prevStateIdx, vector<string> &states, int &statesLen) {
        if(i == N-1) {
            return 1;
        }

        if(dp[i][prevStateIdx] != -1)
            return dp[i][prevStateIdx];

        int ways = 0;
        for(int k=0; k<statesLen; k++) {
            if(k == prevStateIdx) continue;

            string prevState = states[prevStateIdx], currState = states[k];
            bool valid = true;
            for(int j=0; j<M; j++) {
                if(currState[j] == prevState[j]) {
                    valid = false;
                    break;
                }
            }

            if(valid) {
                ways = (ways + solve(i+1, k, states, statesLen)) % MOD;
            }
        }

        return dp[i][prevStateIdx] = ways;
    }

    int colorTheGrid(int m, int n) {
        M = m, N = n;

        // Step 1: Generate all possible column states as m <= 5
        vector<string> states;
        generateStates(0, '$', "", states);
        
        // Step 2: Generate all possible ways by selecting each possible column state as the first column
        int ways = 0;
        int statesLen = states.size();
        dp.resize(n+1, vector<int>(statesLen, -1));
        for(int i=0; i<statesLen; i++) {
            ways = (ways + solve(0, i, states, statesLen)) % MOD;
        }
        return ways;
    }
}