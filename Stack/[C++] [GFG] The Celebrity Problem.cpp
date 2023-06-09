class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        //Step 1- push all persons
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        
        //Step 2- check for the mentioned condition (This stack is used to extract a potential celebrity)
        while(st.size() > 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(M[a][b] == 1)
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        
        //Step 3- Verify the potential celebrity
        bool rowCheck = true, colCheck = true;
        
        //the celebrity row should have all values zero
        for(int i =0; i<n;i++)
        {
            if(M[st.top()][i] == 1)
                rowCheck = false;
        }
        
        //all other persons except himself should know him
        for(int i=0;i<n;i++)
        {
            if(M[i][st.top()] == 0 && i != st.top())
                colCheck = false;
        }
        
        if(rowCheck == true && colCheck == true)
            return st.top();
        else
            return -1;
    }
};