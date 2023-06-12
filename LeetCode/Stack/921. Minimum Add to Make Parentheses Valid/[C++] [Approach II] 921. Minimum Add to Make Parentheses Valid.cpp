class Solution {
public:
    int minAddToMakeValid(string s) {
        int not_closed = 0, not_opened = 0;
        for(char c:s)
        {
            if(c == '(')
                not_closed++;
            
            //if c is ')' and a '(' is available in previous position.
            else if(not_closed > 0)
                not_closed--;

            //if c is ')' and no '(' available previously.
            else
                not_opened++;
        }
        return (not_opened + not_closed);
    }
};