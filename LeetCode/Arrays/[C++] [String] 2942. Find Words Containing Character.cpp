// Brute Force
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for(int i=0; i<words.size(); i++) {
            string word = words[i];
            for(char &ch : word) {
                if(ch == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};


// Using Lambda Capture and any_of() STL
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();

        // Passed [&x] is the reference to the 'x' character and it could also be passed as copy of it by simply doing [x]. This is known as Lambda Capturing.
        auto lambda = [&x](char &ch) {
            return ch==x;
        };

        vector<int> ans;
        for(int i=0; i<n; i++) {
            string word = words[i];
            if(any_of(begin(word), end(word), lambda) == true)
                ans.push_back(i);
        }

        return ans;
    }
};