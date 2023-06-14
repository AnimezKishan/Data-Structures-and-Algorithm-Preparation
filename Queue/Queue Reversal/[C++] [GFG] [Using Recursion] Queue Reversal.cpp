/*
 T.C -> O(n)
 S.C -> O(n) [since recursion uses stack internally]
*/

void reversal(queue<int> &q)
{
    if(q.empty())
        return;
    
    int e = q.front();
    q.pop();
    reversal(q);
    q.push(e);
    
}

queue<int> rev(queue<int> q)
{
    reversal(q);
    return q;
}