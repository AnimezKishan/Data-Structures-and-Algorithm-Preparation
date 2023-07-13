/*
T.C -> O(k log(k)) + O((n*k-k)log(k)) -> O(k log(k)) + O((n*k)log(k)) -> O((n*k)log(k)) [N = Total No. of elements in array, k = No. of arrays]
S.C -> O(k)
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int i=0;i<k;i++)
        {
            min_heap.push(nums[i]);
        }

        for(int i = k;i<nums.size();i++)
        {
            if(nums[i] > min_heap.top())
            {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }

        return min_heap.top();
    }
};