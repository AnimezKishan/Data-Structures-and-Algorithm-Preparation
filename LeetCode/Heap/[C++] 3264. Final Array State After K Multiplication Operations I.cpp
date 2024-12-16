class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();

        for(int i=0; i<n; i++)
            pq.push({nums[i], i});

        while(!pq.empty() && k--) {
            int num = pq.top().first;
            int i = pq.top().second;
            pq.pop();

            num *= multiplier;
            nums[i] = num;
            pq.push({ num, i });
        }

        return nums;
    }
};