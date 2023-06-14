queue<int> modifyQueue(queue<int> q, int k) {
    
    //Using Stack to reverse first 'k' elements
    stack<int> st;
    for(int i=0;i<k;i++)
    {
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    
    //Placing remaining elements into thier right position 
    for(int i=k;i<q.size();i++)
    {
        q.push(q.front());
        q.pop();
    }
    
    return q;
}