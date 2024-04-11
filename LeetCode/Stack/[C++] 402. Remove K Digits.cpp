/*
Make smallest no. from digits 2,1,3,9
=> 1239

Notice the possible solution is in increasing order.
So, make a monotonic stack with no.s in increasing order until k elements
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() == k)
            return "0";

        stack<char> st;
        for(int i=0;i<num.length();i++){

            while(k>0 && !st.empty() && st.top() > num[i]){
                k--;
                st.pop();
            }

            st.push(num[i]);
        }

        // Edge case - "112", k=1
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }


        string ans;
        while(!st.empty()){
            ans.insert(ans.begin(), st.top());
            st.pop();
        }

        while(ans[0] == '0')
            ans.erase(ans.begin());
        
        if(ans.empty())
            return "0";

        return ans;
    }
};