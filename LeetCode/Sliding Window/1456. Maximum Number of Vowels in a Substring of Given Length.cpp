class Solution {

/*
Firstly, check for vowels till kth element.
Like Sliding Window -->
Then, after kth element, in every iteration, check if its a vowel or not and minus the past value of sliding window.
And the max value of count.
*/

public:
    int maxVowels(string s, int k) {
        int count = 0;
        unordered_set<char> v={'a','e','o','i','u'};
        for(int i=0;i<k;i++)
        {
            count += v.count(s[i]);
        }
        int ans = count;
        for(int i=k;i<s.length();i++)
        {
            count += v.count(s[i]) - v.count(s[i - k]);
            ans = max(ans, count);
        }
        return ans;

    }
};