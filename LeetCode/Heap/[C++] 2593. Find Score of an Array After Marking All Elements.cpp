class Solution {
public:
typedef pair<int, int> P;
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> pq; // min-heap
        unordered_map<int, bool> visited;

        for(int i=0; i<n; i++)
            pq.push({nums[i], i});

        long long ans = 0;
        while(!pq.empty()) {
            int num = pq.top().first;
            int idx = pq.top().second;
            if(visited.find(idx) == visited.end()) {
                ans += num;
                visited[idx] = true;

                if(idx-1 >= 0) visited[idx-1] = true;
                if(idx+1 < n) visited[idx+1] = true;
            }

            pq.pop();
        }

        return ans;
    }
};