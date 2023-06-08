#include <bits/stdc++.h> 
void solve(stack<int> &stack, int x)
{
    if(stack.empty())
    {
        stack.push(x);
        return;
    }

    int e = stack.top();
    stack.pop();
    solve(stack, x);
    stack.push(e);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack, x);
    return myStack;
}