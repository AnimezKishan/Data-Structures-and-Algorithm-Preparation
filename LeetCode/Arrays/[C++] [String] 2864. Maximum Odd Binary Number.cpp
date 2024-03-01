// **s contains at least one '1'

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string ans;
        int count = 0;

        for(char &i:s){
            if(i == '1')
                count++;
        }
        count--;

        for(int i=0;i<n;i++){
            if(count > 0)
            {
                ans += '1';
                count--;
            }
            else{
                ans += '0';
            }
        }

        ans[n-1] = '1';
        return ans; 
    }
};