class Solution {
public:
    int m, n;
    void gravityFall(int i, int j, vector<vector<char>> &box) {
        if(j+1 >= n || box[i][j+1] == '*' || box[i][j+1] == '#')
            return;
        
        swap(box[i][j], box[i][j+1]);
        gravityFall(i, j+1, box);
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        m = box.size(), n = box[0].size();

        // Apply Gravity
        for(int i=0; i<m; i++) {
            for(int j=n-1; j>=0; j--) {
                if(box[i][j] == '#')
                    gravityFall(i, j, box);
            }
        }

        vector<vector<char>> ans(n, vector<char>(m));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) 
                ans[j][m-i-1] = box[i][j];

        return ans;
    }
};