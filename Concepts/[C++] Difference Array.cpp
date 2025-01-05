/*
Difference Array - Famous technique used to efficiently apply range updates to an array.
It helps to do multiple updates in constant time.

** Ideal for Range Modification Problems ** 

for [L, R, x], to add x to the range L~R
1. arr[L] += x
2. if arr[R+1] is not out of bound, do arr[R+1] -= x
3. Do the cummulative sum of array

Leetcode 370 - Range Addition (Premium Question)
Where the initial state of array of n size is 0 as element values.
Perform range based addition and result the final state of array.

Example: 
n = 5
queries = {{1,3,2}, {2,4,3}, {0,2,-2}}

So initial array is {0, 0, 0, 0, 0}
1st query -> {0, 2, 2, 2, 0}
2nd query -> {0, 2, 5, 5, 3}
3rd query -> {-2, 0, 3, 5, 3}

Now, this could be done in a brute force way but using Difference Array, operation is effective
-> We add the given query value to the starting index only which gets cummulatively added to next indices.
-> And, we add the opposite of query value to the next index of ending query index so that it doesn't gets cummulated from there.

So it looks like, 
1st query -> { 0, 2, 0, 0, -2 }
2nd query -> { 0, 2, 3, 0, -2 }
3rd query -> { -2, 2, 3, 2, -2 }
cummulative sum of array -> { -2, 0, 3, 5, 3} (ANS)
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> rangeAddition(int n, vector<vector<int>> &queries) {
    vector<int> ans(n, 0);
    for(vector<int> &query : queries) {
        int start = query[0];
        int end = query[1];
        int val = query[2];
        
        ans[start] += val;
        if(end+1 < n)
            ans[end+1] -= val;
    }
    
    for(int i=1; i<n; i++){
        ans[i] = ans[i] + ans[i-1];
    }
    
    return ans;
}
int main()
{
    int n, m;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    
    cout<<"Enter the number of queries: "<<endl;
    cin>>m;
    vector<vector<int>> queries(m, vector<int>(3));
    for(int i=1; i<=m; i++) {
        cout<<"\nEntry "<<i<<endl;
        cout<<"Enter starting index: ";
        cin>>queries[i-1][0];
        cout<<"Enter ending index: ";
        cin>>queries[i-1][1];
        cout<<"Enter query value: ";
        cin>>queries[i-1][2];
    }
    
    vector<int> ans = rangeAddition(n, queries);
    cout<<"Output: "<<endl;
    for(int &i : ans)
        cout<<i<<" ";
    return 0;
}