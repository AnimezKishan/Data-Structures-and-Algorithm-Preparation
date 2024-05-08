class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> sortedScore = score;
        sort(begin(sortedScore), end(sortedScore), greater<int>());

        unordered_map<int, string> m;
        for(int i=0;i<n;i++){
            if(i == 0)
                m[sortedScore[i]] = "Gold Medal";
            else if(i == 1)
                m[sortedScore[i]] = "Silver Medal";
            else if(i == 2)
                m[sortedScore[i]] = "Bronze Medal";
            else
                m[sortedScore[i]] = to_string(i+1);
        }

        vector<string> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = m[score[i]];
        }

        return ans;
    }
};