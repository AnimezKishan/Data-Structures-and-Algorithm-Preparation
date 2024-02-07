// Approach I - Map + Min Heap
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto &i:mp)
            pq.push({i.second, i.first});
        
        string ans = "";
        while(!pq.empty()){
            ans += string(pq.top().first, pq.top().second);
            pq.pop();
        }

        return ans;
    }
};


// Approach II - Sorting + Array Map
/*
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> mp(75, {0, '0'});

        for(int i=0;i<s.length();i++){
            mp[s[i]-'0'].first++;
            mp[s[i]-'0'].second = s[i];
        }

        auto lambda = [&](pair<int, char> &a, pair<int, char> &b){
            return a.first > b.first;
        };
        
        sort(begin(mp), end(mp), lambda);
        string ans = "";
        for(auto &i:mp)
        {
            if(i.first == 0)
                break;
            else
                ans += string(i.first, i.second);
                
        }
        return ans;
    }
};
*/