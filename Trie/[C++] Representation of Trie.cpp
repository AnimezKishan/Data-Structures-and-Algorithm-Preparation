#include <bits/stdc++.h>
using namespace std;

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
    
    void insertUtil(TrieNode* root, string word)
    {
        //base case
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        
        //Assumption - words will be in lowercase
        int index = word[0]- 'a';
        TrieNode* child;
        
        //If child node is already present.
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        //If not present
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        insertUtil(child, word.substr(1));
    }
    
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    
    bool searchUtil(TrieNode *root, string word)
    {
        //base case
        if(word.length() == 0)
        {
            return root->isTerminal;
        }
        
        //Assumption - words will be in lowercase
        int index = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        
        return searchUtil(child, word.substr(1));
    }
    
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
    
    //Return True if the Trie node has no child, else false
    bool isEmpty(TrieNode* root)
    {
        for(int i=0;i<26;i++)
            if(root->children[i])
                return false;
        
        return true;
    }
    
    TrieNode* deleteUtil(TrieNode* root, string word)
    {
        if(root == NULL)
            return NULL;
        
        //Last character being processed
        if(word.length() == 0)
        {
            //This will not be a word after removal
            if(root->isTerminal)
                root->isTerminal = false;
            
            //If this is not a prefix of any other word. [not helping to make any other word]
            if(isEmpty(root))
            {
                delete root;
                root = NULL;
            }
            
            return root;
        }
        
        //Recursion call
        int index = word[0] - 'a';
        root->children[index] = deleteUtil(root->children[index], word.substr(1));
        
        //Backtracking
        //If root has no child (as it's only child got deleted) and it is also not end of any other word
        if(isEmpty(root) && root->isTerminal == false)
        {
            delete root;
            root = NULL;
        }
        
        return root;
    }
    
    TrieNode* deleteWord(string word)
    {
        return deleteUtil(root, word);
    }

    bool startsWithUtil(TrieNode *root, string word)
    {
        //base case
        if(word.length() == 0)
        {
            return true;
        }
        
        //Assumption - words will be in lowercase
        int index = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        
        return startsWithUtil(child, word.substr(1));
    }

    // Returns if there is any word in the trie that starts with the given prefix. 
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("abcd");
    t->insertWord("abc");
    t->deleteWord("abc");
    cout<<t->searchWord("abc")<<"  "<<t->searchWord("abcd")<<endl;

    t->insertWord("help");
    cout<<t->startsWith("hel");
    return 0;
}