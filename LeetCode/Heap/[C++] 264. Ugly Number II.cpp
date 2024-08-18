class Solution {
public:
    vector<int> factors = {2, 3, 5};
    int nthUglyNumber(int n) {
        // min heap
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        // to not add same number twice
        unordered_set<long long> visited;
        pq.push(1);
        visited.insert(1);
        long long num = 1;
        
        while(n > 0){
            num = pq.top();
            pq.pop();
            n--;

            for(int factor : factors){
                if(visited.find(num * factor) == visited.end()){
                    pq.push(num * factor);
                    visited.insert(num * factor);
                }
            }
        }

        return num;
    }
};