//Tabulation (Bottom-Up)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 0);
        ans[0] = 1;

        for(int i=1; i<=rowIndex; i++){

            //progressively update values from end to beginning.
            for(int j=i; j>=1 ;j--)
                ans[j] += ans[j-1];
        }

        return ans;
    }
};


//Brute Force
/*
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex+1);

        for(int i=0;i<=rowIndex;i++)
        {
            for(int j=0;j<=i;j++){
                if(j == 0 || j == i)
                    result[i].push_back(1);
                else
                    result[i].push_back(result[i-1][j-1] + result[i-1][j]);
            }
        }

        return result[rowIndex];
    }
};
*/