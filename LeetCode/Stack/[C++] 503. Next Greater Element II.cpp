/*
Traverse the array in a circular manner
For example [1,2,3] -> [1,2,1,1,2,3]

Then apply the stack's next greater element algo
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for(int i=2*n-1;i>=0;i--)
        {
            int curr = nums[i%n];
            while(!st.empty() && st.top() <= curr)
            {
                st.pop();
            }
            if(!st.empty() && (i<n))
            {
                ans[i] = st.top();
            }
            st.push(curr);
        }
        return ans;
    }
};