class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        string rev = s;
        reverse(begin(rev), end(rev));
        
        for(int i=0; i<n; i++){
            // using memcmp to avoid TLE 
            // It demands pointer to the character array and compare each element till the length provided.
            // it accepts starting point of first string, starting point of second string, and length to be taken for both string
            if(memcmp(s.c_str(), rev.c_str()+i, n-i) == 0) 
                return rev.substr(0, i) + s;
        }

        return rev + s;
    }
};