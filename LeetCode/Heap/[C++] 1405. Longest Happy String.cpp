class Solution {
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P> pq;

        if(a > 0)
            pq.push({a, 'a'});
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});

        string ans = "";
        while(!pq.empty()) {
            int currVal = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();

            if(ans.length() >= 2 && ans[ans.length()-1] == currChar && ans[ans.length()-2] == currChar){
                if(pq.empty())
                    break;
                
                int nextVal = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();

                ans.push_back(nextChar);
                nextVal--;
                if(nextVal > 0)
                    pq.push({nextVal, nextChar});
            }
            else {
                ans.push_back(currChar);
                currVal--;
            }

            if(currVal > 0)
                pq.push({currVal, currChar});
        }

        return ans;
    }
};