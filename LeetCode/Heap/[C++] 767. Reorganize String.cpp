class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        //Create a map to store frequency of each character
        unordered_map<char, int> mp;

        for(int i=0;i<s.length();i++)
            mp[s[i]]++;

        //Create a max heap
        priority_queue<pair<int, char>> pq; 

        for(auto m:mp)
            pq.push(make_pair(m.second, m.first));
        
        while(pq.size() > 1)
        {
            //Get top two elements from max heap and append in answer
            auto top1 = pq.top();
            pq.pop();
            auto top2 =pq.top();
            pq.pop();

            
            ans += top1.second;
            ans += top2.second;

            //Decrease their frequency by 1
            top1.first--;
            top2.first--;

            //If the frequency of character is not zero, push it back in max heap
            if(top1.first > 0)
                pq.push(top1);
            
            if(top2.first > 0)
                pq.push(top2);
        }

        /* 
        One character was intentionally left in the max heap.
        As, no other character is left expect that character in max heap.
        So its frequency should be <= 1 to make reorganization of string possible.
        */
        if(!pq.empty())
        {
            if(pq.top().first > 1)
                return "";
            else
                ans += pq.top().second;
        }
        
        return ans;
    }
};