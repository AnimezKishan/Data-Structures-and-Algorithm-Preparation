//Two Pointer

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, j = 0;

        while(j<n)
        {
            if(j == (n-1) || s[j] == ' ')
            {
                int i_ = i;
                int j_ = (j == (n-1) ? j : j-1);
                while(i_ <= j_)
                {
                    swap(s[i_], s[j_]);
                    i_ ++;
                    j_ --;
                }
                i = j+1;
            }
            j++;
        }
        return s;
    }
};