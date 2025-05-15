class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> ansIdx;

        for(int i=0; i<max(n-i, static_cast<int>(ansIdx.size())); i++) {
            vector<int> temp;
            temp.push_back(i);
            for(int j=i+1; j<n; j++) {
                if(groups[j] != groups[temp.back()])
                    temp.push_back(j); 
            }

            if(temp.size() > ansIdx.size())
                ansIdx = move(temp);
        }

        vector<string> ans;
        for(int &i : ansIdx)
            ans.push_back(words[i]);

        return ans;
    }
};