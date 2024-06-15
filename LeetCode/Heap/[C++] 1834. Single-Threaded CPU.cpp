// Similar to LeetCode 502

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<vector<int>> sortedTasks(n, vector<int>(3));
        for(int i=0; i<n; i++)
            sortedTasks[i] = {tasks[i][0], tasks[i][1], i};
        
        sort(begin(sortedTasks), end(sortedTasks));

        int i = 0;
        long long currTime = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        vector<int> ans;
        while(i < n || !min_heap.empty()){

            if(min_heap.empty() && currTime < sortedTasks[i][0]) {
                currTime = sortedTasks[i][0];
            }

            while(i<n && sortedTasks[i][0] <= currTime){
                min_heap.push({ sortedTasks[i][1], sortedTasks[i][2] });
                i++;
            }

            ans.push_back(min_heap.top().second);
            currTime += min_heap.top().first;
            min_heap.pop();
        }

        return ans;
    }
};