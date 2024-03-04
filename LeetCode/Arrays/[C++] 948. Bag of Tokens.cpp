// Sorting + Two Pointer + Greedy

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens), end(tokens));

        int n = tokens.size();
        int i = 0, j = n-1;
        int maxScore = 0, score = 0;

        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i++];
                score++;
                maxScore = max(maxScore, score);
            }
            else if(score > 0){
                power += tokens[j--];
                score--;

            }
            else
                return maxScore;
        }

        return maxScore;
    }
};