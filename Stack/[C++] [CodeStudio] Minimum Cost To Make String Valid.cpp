#include <bits/stdc++.h>
int findMinimumCost(string str) {
  // Write your code here
  if (str.length() % 2 != 0)
    return -1;
  
  stack<char> st;
  for(int i=0;i<str.length();i++)
  {
    if(str[i] == '{')
    {
      st.push(str[i]);
    }
    else
    {
      if(!st.empty() && st.top() == '{')
      {
        st.pop();
      }
      else
        st.push(str[i]);
    }
  }
  int a=0,b=0;
  while(!st.empty()){
    if(st.top() == '{')
      a++;
    else
      b++;
    st.pop();
  }
  int ans = ((a+1)/2) + ((b+1)/2);
  return ans;
}