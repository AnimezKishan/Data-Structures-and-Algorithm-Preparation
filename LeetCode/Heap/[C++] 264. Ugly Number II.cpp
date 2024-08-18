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

// DP
/*
class Solution {
public:
    unordered_map<int, bool> mp;
    bool isUgly(int n) {
        if(n <= 0)
            return false;
        if(n == 1)
            return true;
        
        if(mp.find(n) != mp.end())
            return mp[n];
        
        if(n%2 == 0 && isUgly(n/2))
            return mp[n] = true;
        else if(n%3 == 0 && isUgly(n/3))
            return mp[n] = true;
        else if(n%5 == 0 && isUgly(n/5))
            return mp[n] = true;
        
        return mp[n] = false;
    }
    int nthUglyNumber(int n) {
        mp.clear();
        int num = 1;
        while(n > 0) {
            if(isUgly(num)) {
                n--;
            }
            num++;
        }
        
        return num-1;
    }
};
*/