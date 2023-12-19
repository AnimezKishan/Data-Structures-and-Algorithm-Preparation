class Solution {
public:
    int m, n;
    bool isSafe(int x, int y){
        if((x>=0 && x<m) && (y>=0 && y<n))
            return true;
        return false;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        m = img.size();
        n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n));

        for(int i=0;i<img.size();i++){
            for(int j=0;j<img[i].size();j++){
                int ans = 0;
                int cnt = 1;
                ans += img[i][j];

                //up
                if(isSafe(i-1, j)){
                    ans += img[i-1][j];
                    cnt++;
                }
                    
                //down
                if(isSafe(i+1, j)){
                    ans += img[i+1][j];
                    cnt++;
                }

                //left
                if(isSafe(i, j-1)){
                    ans += img[i][j-1];
                    cnt++;
                }
                    
                //right
                if(isSafe(i, j+1)){
                    ans += img[i][j+1]; 
                    cnt++;
                }

                //top-right
                if(isSafe(i-1, j+1)){
                    ans += img[i-1][j+1];
                    cnt++;
                }
                    
                //top-left
                if(isSafe(i-1, j-1)){
                    ans += img[i-1][j-1];
                    cnt++;
                }              

                //bottom-right
                if(isSafe(i+1, j+1)){
                    ans += img[i+1][j+1];
                    cnt++;
                } 

                //bottom-left
                if(isSafe(i+1, j-1)){
                    ans += img[i+1][j-1];
                    cnt++;
                }
                    
                result[i][j] = floor(ans/cnt);
            }
            
        }

        return result;
    }
};