class Solution {
public:
    bool checkV(char ch){
        ch = (char)tolower(ch);
        if(ch == 'a' || ch == 'e' || ch == 'u' || ch == 'o' || ch == 'i')
            return true;
        else
            return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.length();
        int count1 = 0, count2 = 0;

        for(int i=0;i<n;i++){
            if(checkV(s[i]))
            {
                if(i >= n/2)
                    count2++;
                else
                    count1++;
            }
        }

        return count1 == count2;
    }
};