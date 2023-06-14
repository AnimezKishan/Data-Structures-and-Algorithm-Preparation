/*
 T.C -> O(n)
 S.C -> O(n) 
*/

queue<int> rev(queue<int> q)
{
    stack<int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}