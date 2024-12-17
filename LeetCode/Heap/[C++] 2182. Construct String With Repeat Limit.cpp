class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<int, int> mp;
        for(char &ch : s)
            mp[ch-'a']++;
        
        priority_queue<pair<int, int>> pq;
        for(auto &i : mp)
            pq.push({ i.first, i.second });

        string ans = "";
        while(!pq.empty()) {
            int ch = pq.top().first;
            int count = pq.top().second;
            pq.pop();

            if(ans.length() && (char)(ch+'a') == ans.back()){
                if (pq.size() == 0)
                    break;
                else{
                    int ch2 = pq.top().first;
                    int count2 = pq.top().second;
                    pq.pop();

                    ans += string(1, (char)(ch2+'a'));
                    if(count2-1 > 0)
                        pq.push({ ch2, count2-1 });

                    pq.push({ ch, count });
                }
            }
            else {
                if(count <= repeatLimit)
                    ans += string(count, (char)(ch+'a'));
                else {
                    ans += string(repeatLimit, (char)(ch+'a'));
                    if(count-repeatLimit > 0)
                        pq.push({ ch, count-repeatLimit });
                }
            }
        }
        return ans;
    }
};