// BFS

class Solution {
public:
    int n;
    void fillNeighbour(string &curr, queue<string> &q, unordered_set<string> &st, unordered_map<string, bool> &visited){
        for(int i=0;i<n;i++){
            char currChar = curr[i];
            for(int ch=0;ch<26;ch++){
                if(currChar != char('a'+ch)){
                    curr[i] = char(ch+'a');
                    if(st.find(curr) != st.end() && !visited[curr]){
                        q.push(curr);
                        visited[curr] = 1;
                    }
                }
            }
            curr[i] = currChar;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = beginWord.length();
        unordered_set<string> st(begin(wordList), end(wordList));
        unordered_map<string, bool> visited;

        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = 1;

        int level = 1, size;
        while(!q.empty()){
            size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();

                if(curr == endWord)
                    return level;
                
                fillNeighbour(curr, q, st, visited);
            }
            level++;
        }

        return 0;
    }
};