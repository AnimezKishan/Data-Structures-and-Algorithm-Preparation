// Sorting + Cummulative Max + Hashmap

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // sort items by price
        sort(items.begin(), items.end());

        // cummulative max beauty 
        map<int, int> mp;
        int maxBeauty = 0;
        for(vector<int> &item : items) {
            int price = item[0];
            int beauty = item[1];

            maxBeauty = max(maxBeauty, beauty);
            mp[price] = maxBeauty;
        }

        // handle queries
        vector<int> ans;
        for(int &query_price : queries) {
            auto it = mp.upper_bound(query_price);

            // no price less than or equal to it found
            if(it == mp.begin()) {
                ans.push_back(0);
            }
            else{
                --it;
                ans.push_back(it->second);
            }
        }

        return ans;
    }
};