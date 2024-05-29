/*
For Odd, add 1 to it : turn all ones to zero till a zero is found, and then turn that zero to one
For Even, Divide by 2 : right shift a bit.
*/

// T.C -> O(n^2)
// S.C -> O(n)
class Solution {
public:
    int numSteps(string s) {
        int ans = 0;

        while(s.length() > 1){
            int n = s.length();
            
            //Even
            if(s[n-1] == '0'){
                s.pop_back();
                ans++;
            }

            //Odd
            else{
                int i = n-1;
                while(i>=0 && s[i] != '0')
                    s[i--] = '0';
                
                // If all bits are 1
                if(i < 0)
                    s = '1' + s;
                else
                    s[i] = '1';
                
                ans++;
            }
        }

        return ans;
    }
};