// Variation of Next Smallest Element
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        st.push(-1);
        vector<int> ans;

        for(int i=prices.size()-1; i>=0; i--) {
            int curr = prices[i];

            while(st.top() != -1 && prices[st.top()] > curr){
                st.pop();
            }
            
            int nextSmall = st.top() == -1 ? 0 : prices[st.top()];
            ans.push_back(curr - nextSmall);
            st.push(i);
        }

        reverse(ans.begin(), ans.end());
        return ans; 
    }
};