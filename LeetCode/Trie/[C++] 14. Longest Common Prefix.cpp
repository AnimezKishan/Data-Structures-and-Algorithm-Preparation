/*
T.C -> O(m*n) [m = size of vector which consist strings, n = size of a string]
S.C -> O(m*n)

** Disclaimer - This was solved using trie to show application of trie.
   It can be done in following complexity using brute force
   T.C -> O(m*n)
   S.C -> O(1)
*/


/*
** BRUTE FORCE **
class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        string ans = "";
        for(int i=0;i<arr[0].length();i++)
        {
            char ch = arr[0][i];
            bool flag = true;

            for(int j=1;j<arr.size();j++)
            {
                if(arr[j].size() < i || ch != arr[j][i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == false)
                break;
            else
                ans.push_back(ch);
        }
        return ans;
    }
};
*/

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i=0;i<26;i++)
            children[i] = NULL;
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
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
            root->childCount++;
            root->children[index] = child;
        }
        
        insertUtil(child, word.substr(1));
    }
    
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for(int i=0;i<str.length();i++)
        {
            char ch = str[i];
            // if root child count is only 1, it means all the string has that prefix. 
            if(root->childCount == 1)
            {
                ans.push_back(ch);
                root = root->children[ch-'a'];
            }
            else
                break;
            
            if(root->isTerminal)
                break;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *t = new Trie('\0');

        //insert all strings
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].length() == 0)
                return "";
            t->insertWord(strs[i]);
        }
        string first = strs[0];
        string ans = "";
        t->lcp(first, ans);
        return ans;
    }
};