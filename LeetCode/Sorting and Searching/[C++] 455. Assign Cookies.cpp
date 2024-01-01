class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int i = 0, j = 0;
        int m = g.size(), n = s.size();
        while(i<m && j<n){
            if(s[j] >= g[i]){
                i++;
            }
            j++;
        }

        return i;
    }
};