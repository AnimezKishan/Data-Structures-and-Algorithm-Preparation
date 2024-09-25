class Trie {
    public:
    int count = 0;
    Trie* children[26];
};

class Solution {
public:
    Trie* getTrie() {
        Trie *root = new Trie();
        for(int i=0; i<26; i++)
            root->children[i] = NULL;
        
        return root;
    }

    void insertInTrie(string &word, Trie *root) {
        Trie *crawler = root;

        for(char &ch : word){
            int idx = ch - 'a';

            if(!crawler->children[idx])
                crawler->children[idx] = getTrie();
            
            crawler->children[idx]->count += 1;
            crawler = crawler->children[idx];
        }
    }

    int getScore(string &word, Trie *root) {
        int score = 0;
        Trie *crawler = root;

        for(char &ch : word) {
            int idx = ch - 'a';

            score += crawler->children[idx]->count;
            crawler = crawler->children[idx];
        }

        return score;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *root = getTrie();

        for(string &word : words) {
            insertInTrie(word, root);
        }

        vector<int> ans;
        for(string &word : words) {
            int score = getScore(word, root);
            ans.push_back(score);
        }

        return ans;
    }
};