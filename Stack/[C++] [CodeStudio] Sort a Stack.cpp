#include <bits/stdc++.h> 

void sortedInsert(stack<int> &stack, int x)
{
	if(stack.empty() || (x > stack.top()))
	{
		stack.push(x);
		return;
	}
	int ee = stack.top();
	stack.pop();
	sortedInsert(stack, x);
	stack.push(ee);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty())
		return;
	
	int e = stack.top();
	stack.pop();
	sortStack(stack);
	sortedInsert(stack, e);
}