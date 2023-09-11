/*
Time Complexity - O(n + n*log()n) => O(n*log(n)) [n is for traversal of groupSize and n*log(n) is for operations of Min Heap]
Space Complexity - O(n+k) 
[n is the space used by the minHeap, temp vector, and ans vector.
k is the maximum number of distinct group available.]
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for(int i=0;i<groupSizes.size();i++)
        {
            min_heap.push({groupSizes[i], i});
        }

        while(!min_heap.empty())
        {
            int k = min_heap.top().first;
            vector<int> temp;
            while(k>0)
            {
                temp.push_back(min_heap.top().second);
                k--;
                min_heap.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};