class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int, int> mp;
        for(int &i:arr){
            mp[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for(auto &i:mp){
            min_heap.push({i.second, i.first});
        } 

        while(!min_heap.empty()){
            auto temp = min_heap.top();
            if(temp.first <= k){
                min_heap.pop();
                k -= temp.first;
            }
            else
                break;
        }

        return min_heap.size();
    }
};