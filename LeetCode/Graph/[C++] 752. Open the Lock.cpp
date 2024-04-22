// BFS

class Solution {
public:
    void fillNeighbour(string &curr, queue<string> &q, unordered_set<string> &st){
        for(int i=0;i<4;i++){
            char ch = curr[i];

            char inc = ch == '9' ? '0' : ch+1;
            char dec = ch == '0' ? '9' : ch-1;

            curr[i] = inc;
            if(st.find(curr) == st.end()){
                q.push(curr);
                st.insert(curr);
            }

            curr[i] = dec;
            if(st.find(curr) == st.end()){
                q.push(curr);
                st.insert(curr);
            }

            curr[i] = ch;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(begin(deadends), end(deadends));

        string start = "0000";

        //Edge Case - if starting state is present in deadend
        if(st.find(start) != st.end())
            return -1;
        
        queue<string> q;
        q.push(start);

        int level = 0, size;
        while(!q.empty()){
            size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();

                if(curr == target)
                    return level;
                
                fillNeighbour(curr, q, st);
            }
            level++;
        } 

        return -1;
    }
};