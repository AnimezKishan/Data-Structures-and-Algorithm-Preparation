class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        auto lambda = [&](pair<char, int> &a, pair<char, int> &b) {
            if(a.first < b.first)
                return true;
            else if(a.first == b.first && a.second > b.second)
                return true;
            else
                return false;
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(lambda)> pq(lambda);
        
        for(int i=0; i<s.length(); i++) 
            pq.push({s[i], i});

        for(int i=0; i<s.length(); i++) {
            char currVal = pq.top().first;
            int currIdx = pq.top().second;
            pq.pop();

            if(i < currIdx && s[i] < currVal){
                int nextIdx = currIdx;
                while(!pq.empty() && pq.top().first == currVal){
                    nextIdx = pq.top().second;
                    pq.pop();
                }
                swap(s[i], s[nextIdx]);
                break;
            }
        }

        return stoi(s);
    }
};