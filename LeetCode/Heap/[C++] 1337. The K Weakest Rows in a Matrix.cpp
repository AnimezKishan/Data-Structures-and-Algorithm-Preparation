class Solution {
public:
    typedef pair<int, int> P;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<P, vector<P>, greater<P>> min_heap;

        for(int i=0;i<mat.size();i++)
        {
            int count = 0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j] == 1)
                    count++;
            }
            min_heap.push({count, i});
        }

        vector<int> ans;
        while(k>0 && !min_heap.empty())
        {
            int rowVal = min_heap.top().second;
            min_heap.pop();
            k--;
            
            ans.push_back(rowVal);
        }
        return ans;
    }
};