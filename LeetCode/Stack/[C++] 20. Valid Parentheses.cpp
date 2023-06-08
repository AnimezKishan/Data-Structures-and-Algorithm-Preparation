class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];
        st.push(ch);
        if(!st.empty() && st.top() == ')')
        {
            st.pop();
            if(!st.empty() && st.top() == '(')
                st.pop();
            else
                return false; 
        }

        if(!st.empty() && st.top() == ']')
        {
            st.pop();
            if(!st.empty() && st.top() == '[')
                st.pop();
            else
                return false; 
        }

        if(!st.empty() && st.top() == '}')
        {
            st.pop();
            if(!st.empty() && st.top() == '{')
                st.pop();
            else
                return false; 
        }
    }
    if(st.empty())
        return true;
    else
        return false;
    }
};