class Solution {
public:
    string compressedString(string word) {
        int n = word.length(), i = 0;
        string ans = "";

        while(i<n) {
            char curr = word[i];
            int count = 0;
            while(i<n && count < 9 && word[i] == curr){
                count++;
                i++;
            }

            ans += to_string(count) + curr;
        }

        return ans;
    }
};