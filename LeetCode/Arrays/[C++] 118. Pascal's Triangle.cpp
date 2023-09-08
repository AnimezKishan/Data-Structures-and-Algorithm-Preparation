class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        for(int i=0;i<numRows;i++)
        {
            ans[i] = vector<int> (i+1, 1);
            for(int j=1;j<i;j++)
            {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};

/*
Brute Force (Less Space Optimized)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=0;i<numRows;i++)
        {
            vector<int> temp;
            for(int j=0;j<(i+1);j++)
            {
                if(j == 0 || j == i)
                    temp.push_back(1);
                else
                    temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
*/