// T.C. -> (2^n * L), L = average length of word
// S.C. -> O(N) (Depth of Recursive Tree would be maximum of length of words)

class Solution {
public:
    int n, maxScore;

    void solve(int idx, vector<string>& words, vector<int>& score, int currScore,vector<int> &lettersCount) {
        maxScore = max(maxScore, currScore);
        
        if(idx == n)
            return;
        
        // Include + check for condition (if we are able to take the word or not)
        int j = 0;
        int tempScore = 0;
        vector<int> tempCount = lettersCount; // O(26)
        while(j < words[idx].length()){
            char ch = words[idx][j];

            if(tempCount[ch-'a'] == 0)
                break;
            
            tempCount[ch-'a']--;
            tempScore += score[ch-'a'];
            j++;
        }
        if(j == words[idx].length())
            solve(idx+1, words, score, currScore + tempScore, tempCount); // If taken, pass the updated Count/Frequency of letters.
        
        // Exclude 
        solve(idx+1, words, score, currScore, lettersCount);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size(), maxScore = INT_MIN;
        vector<int> lettersCount(26, 0);

        for(char &ch:letters)
            lettersCount[ch-'a']++;

        solve(0, words, score, 0, lettersCount);
        return maxScore;
    }
};


// With Return type function
/*
class Solution {
public:
    int n;
    
    int solve(int idx, vector<string>& words, vector<int>& score,vector<int> &lettersCount) {
        if(idx == n)
            return 0;
        
        // include + check for condition (if we are able to take the word or not)
        int j = 0;
        int tempScore = 0;
        int include = 0;
        vector<int> tempCount = lettersCount; // O(26)
        while(j < words[idx].length()){
            char ch = words[idx][j];

            if(tempCount[ch-'a'] == 0)
                break;
            
            tempCount[ch-'a']--;
            tempScore += score[ch-'a'];
            j++;
        }
        if(j == words[idx].length())
            include = tempScore + solve(idx+1, words, score, tempCount); // If taken, pass the updated Count/Frequency of letters.
        
        // Exclude 
        int exclude = solve(idx+1, words, score, lettersCount);

        return max(include, exclude);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        vector<int> lettersCount(26, 0);

        for(char &ch:letters)
            lettersCount[ch-'a']++;

        return solve(0, words, score, lettersCount);
    }
};
*/