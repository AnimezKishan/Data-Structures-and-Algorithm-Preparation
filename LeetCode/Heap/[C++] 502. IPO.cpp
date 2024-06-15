/*
Sorting + Greedy (Heap)
make a merged array of capital and profits and then sort it based on capital

For each project selection, choose the maximum profit possible from current capital value i.e. 'w'
*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> P;
        for(int i=0; i<n; i++)
            P.push_back({capital[i], profits[i]});

        sort(begin(P), end(P));

        int i = 0;
        priority_queue<int> max_heap;
        while(k--){
            while(i < n && P[i].first <= w){
                max_heap.push(P[i].second);
                i++;
            }  

            // Edge Case - If no profit available for current capital value
            if(max_heap.empty())
                break;

            w += max_heap.top();
            max_heap.pop();
        }

        return w;
    }
};