// Approach I
class Solution {
public:
    string revInvert(string &s) {
        string revStr = "";
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] == '1')
                revStr += '0';
            else
                revStr += '1';
        }

        return revStr;
    }
    char findKthBit(int n, int k) {
        string s = "0";

        for(int i=1; i<n; i++) {
            s = s + '1' + revInvert(s);
            if(s.length() >= k)
                break;
        }

        return s[k-1];
    }
};