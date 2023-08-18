class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char w){
        this->data = w;
        for(int i=0;i<26;i++)
            this->children[i] = NULL;
        this->isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        this->root = new TrieNode('\0');
    }
    
    void insertUtil(string word, TrieNode *root){
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] == NULL)
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        else{
            child = root->children[index];
        }

        insertUtil(word.substr(1), child);
    }

    void insert(string word) {
        insertUtil(word, root);
    }
    
    bool searchUtil(string word, TrieNode* root){
        if(word.length() == 0)
            return root->isTerminal;
        
        int index = word[0] - 'a';
        if(root->children[index] != NULL)
        {
            TrieNode* child = root->children[index];
            return searchUtil(word.substr(1), child);
        }
        else
        {
            return false;
        }
    }

    bool search(string word) {
        return searchUtil(word, root);
    }
    
    bool startUtil(string prefix, TrieNode* root){
        if(prefix.length() == 0)
            return true;
        
        int index = prefix[0] - 'a';
        if(root->children[index] != NULL)
        {
            TrieNode* child = root->children[index];
            return startUtil(prefix.substr(1), child);
        }
        else{
            return false;
        }
    }

    bool startsWith(string prefix) {
        return startUtil(prefix, root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */