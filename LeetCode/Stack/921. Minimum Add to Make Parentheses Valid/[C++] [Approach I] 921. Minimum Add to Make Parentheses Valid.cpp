class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            st.push(s[i]);
            cnt++;
            if(!st.empty() && st.top() == ')')
            {
                st.pop();
                if(!st.empty() && st.top() =='(')
                {
                    st.pop();
                    cnt--;
                    cnt--;
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        return cnt;
    }
};