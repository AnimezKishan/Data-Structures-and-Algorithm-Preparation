// At most one alphabet has an odd number of occurrencies in a palindrome string.

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int> m;

        for(int i=0;i<n;i++)
            m[s[i]]++;

        // for(auto i: m)
        //     cout<<i.first<<" -> "<<i.second<<endl;

        int ans = 0;
        bool oddExist = 0;
        for(auto i : m) {
            if(i.second % 2 == 0)
                ans += i.second;
            // For Odd occurances, take it's character even no. of times. 
            else{
                ans += i.second-1;
                oddExist = 1;
            }
        }  

        // Since, at most one odd occurance can exist to make it palindrome.
        return oddExist == 0 ? ans :ans+1;
    }
};