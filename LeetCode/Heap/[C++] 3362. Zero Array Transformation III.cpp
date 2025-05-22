class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // Min-heap of used queries' end indices
        priority_queue<int, vector<int>, greater<int>> past;

        // Max-heap of available queries' end indices
        priority_queue<int> maxHeap;

        // Sort queries by start index
        sort(queries.begin(), queries.end());

        int j = 0;              // Pointer to queries
        int usedCount = 0;      // Number of queries actually used

        for (int i = 0; i < n; ++i) {
            // Push all queries starting at index i into maxHeap
            while (j < queries.size() && queries[j][0] == i) {
                maxHeap.push(queries[j][1]);  // push only the end
                ++j;
            }

            // Apply effect of already-used queries
            nums[i] -= past.size();

            // Apply more queries if needed
            while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i) {
                int r = maxHeap.top(); maxHeap.pop();
                past.push(r);
                usedCount++;
                nums[i]--;
            }

            // If we can't reduce nums[i] to 0
            if (nums[i] > 0)
                return -1;

            // Remove expired queries
            while (!past.empty() && past.top() == i) {
                past.pop();
            }
        }

        return queries.size() - usedCount;
    }
};