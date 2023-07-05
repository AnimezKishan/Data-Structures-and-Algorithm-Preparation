string removeDuplicate(string &s)
{
    //base case
    if(s.length() == 1)
        return s;
    
    else
    {
        //storing the next elements for comparison after recursive calls
        char next = s[s.length()-1];
        s.pop_back();
        removeDuplicate(s);
        
        //comparing
        if(s[s.length()-1] != next)
        {
            s.push_back(next);
        }
        return s;
    }
    
}