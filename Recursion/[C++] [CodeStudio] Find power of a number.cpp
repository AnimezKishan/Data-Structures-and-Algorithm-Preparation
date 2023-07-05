#include <bits/stdc++.h> 
long long Pow(int X, int N)
{
    //base case
    if(N == 0)
        return 1;
    if(N == 1)
        return X;
    
    long long ans = Pow(X, N/2);

    //if N is odd
    if(N & 1)
        return X*ans*ans;
    
    //if N is Even
    else
        return ans*ans;
}