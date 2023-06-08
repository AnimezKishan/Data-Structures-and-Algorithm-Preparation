#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    // Write your code here.
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            bool isRedundant = true;
            while(st.top() != '('){
            if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                isRedundant = false;
            st.pop();
            }
            if(isRedundant == true)
                return true;
            st.pop();
        }
        
    }
    return false;
}