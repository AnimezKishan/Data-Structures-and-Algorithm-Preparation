class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int num3 = INT_MIN;

        stack<int> st;

        //traversing reverse to take care of condition --> i < j < k
        // Also, we need a condition of num1 < num3 < num2 to return true
        for(int i=n-1;i>=0;i--)
        {
            //this represents num1
            if(nums[i] < num3)
                return true;
            
            //stack represents num2
            while(!st.empty() && st.top() < nums[i])
            {
                num3 = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};