/*
T.C -> O(n^2)
S>C -> O(n)
*/

void insertAtBottom(stack<int> &stack, int x)
{
    if(stack.empty())
    {
        stack.push(x);
        return;
    }
    int e = stack.top();
    stack.pop();
    insertAtBottom(stack, x);
    stack.push(e);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty())
    {
        return;
    }
    int e = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, e);
}