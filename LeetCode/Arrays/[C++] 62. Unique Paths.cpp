// Reference - https://www.youtube.com/watch?v=IlEsdxuD4lY

// Mathematical Approach 

/*
For m = 3, n = 7,

Rows can be shown as,

28 21 15 10 6 3 1
7  6  5  4  3 2 1
1  1  1  1  1 1 1
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 1);

        for(int i=0;i<m-1;i++)
        {
            vector<int> newRow(n, 1);
            for(int j=n-2;j>=0;j--)
            {
                newRow[j] = newRow[j+1] + row[j];
            }
            row = newRow;
        }

        return row[0];
    }
};

