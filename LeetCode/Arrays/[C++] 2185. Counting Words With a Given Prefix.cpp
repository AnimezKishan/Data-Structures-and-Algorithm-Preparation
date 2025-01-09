class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(int i=0; i<words.size(); i++) {
            int j=0, k=0;
            while(k < words[i].length() && j < pref.length() && pref[j] == words[i][k]){
                j++;
                k++;
            }

            if(j == pref.length())
                ans++;
        }
        return ans;
    }
};