/*
   T.C -> O((m*n)^2)
   S.C -> O(m*n)
*/
class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char c)
    {
        this->data = c;
        for(int i=0;i<26;i++)
            this->children[i] = NULL;
        this->isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;
    
    Trie(){
        this->root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word, int depth = 0)
    {
        //base case
        if(depth == word.size())
        {
            root->isTerminal = true;
            return;
        }
        
        //Assumption - words will be in lowercase
        int index = word[depth]-'a';
        TrieNode* child;
        
        //If child node is already present.
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        //If not present
        else
        {
            child = new TrieNode(word[depth]);
            root->children[index] = child;
        }
        
        insertUtil(child, word, depth+1);
    }
    
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix)
    {
        //base case
        if(curr->isTerminal)
            temp.push_back(prefix);
        
        for(char ch='a';ch<='z';ch++)
        {
            
            TrieNode* next = curr->children[ch-'a'];

            //if child found
            if(next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                
                //backtracking
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode* prev = root;
        vector<vector<string>> ans;
        string prefix = ""; 

        //check for all characters in string
        for(int i=0;i<str.length();i++)
        {
            char lastCh = str[i];
            prefix.push_back(lastCh);

            //check for last character
            TrieNode* curr = prev->children[lastCh - 'a'];
            
            //if not found
            if(curr == NULL)
                break;
            
            //if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            ans.push_back(temp);
            temp.clear();
            prev = curr;

        }
        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //create a trie
    Trie *t = new Trie();

    //insert all contact in trie
    for(int i=0;i<contactList.size();i++)
        t->insertWord(contactList[i]);
    
    //return ans
    return t->getSuggestions(queryStr);

}