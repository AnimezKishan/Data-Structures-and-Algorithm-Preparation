// T.C : o(n*l + m*l^2) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.

class Solution {
public:
    string findRoot(string &s, unordered_set<string> &st) {
        // try to find shortest length root
        for(int len=1;len<=s.length();len++){
            string root = s.substr(0, len);
            if(st.count(root))
                return root;
        }
        return s;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> s(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string word, ans;

        // stringstream to split the sentence into individual words
        while(getline(ss, word, ' ')){
            ans += findRoot(word, s) + ' ';
        }

        ans.pop_back();
        return ans;
    }
};