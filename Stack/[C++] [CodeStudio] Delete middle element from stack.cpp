#include <bits/stdc++.h> 

void solve(stack<int>&Stack, int count, int N){
   //base case
   if(count == N/2)
   {
      Stack.pop();
      return;
   }
   int e = Stack.top();
   Stack.pop();
   solve(Stack, count+1, N);
   Stack.push(e);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   solve(inputStack, 0, N);

}