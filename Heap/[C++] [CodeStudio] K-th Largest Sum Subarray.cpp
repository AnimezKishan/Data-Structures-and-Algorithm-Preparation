/*
T.C -> O(N^2 log(k)), N^2 since two loops and log k to heapify it.
S.C -> O(k)
*/

#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int>> min_heap;
	for(int i=0;i<arr.size();i++)
	{
		int sum = 0;
		for(int j=i;j<arr.size();j++)
		{
			//check for all possible subarray sum
			sum += arr[j];

			//Store elements in min heap till the size of k 
			if(min_heap.size() < k)
				min_heap.push(sum);
			else
			{
				/*
				When size of min heap reaches k, then
				For every iteration, Check if element is greater than top element of min heap.
				[Top element of min heap is the largest value possibly avaiable inside the min heap]
					If yes, then pop the top element of min heap and store the sum value in it's right place inside min heap.
				*/
				if(sum > min_heap.top())
				{
					min_heap.pop();
					min_heap.push(sum);
				}
			}
		}
	}
	return min_heap.top();
}