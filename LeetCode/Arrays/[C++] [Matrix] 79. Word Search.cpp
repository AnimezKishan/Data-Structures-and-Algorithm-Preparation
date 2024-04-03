class Solution {
public:
    int m, n;
    bool ans = false;
    vector<vector<bool>> visited;
    bool isValid(int i, int j, vector<vector<char>>& board, int wordIdx,string &word){
        if((i>=0 && i<m) && (j>=0 && j<n) && !visited[i][j] && board[i][j] == word[wordIdx]){
            //cout<<i<<" "<<j<<" -> "<<board[i][j]<<" "<<visited[i][j]<<endl;
            return true;
        }
        return false;
    }

    void solve(int i, int j, vector<vector<char>>& board, int wordIdx,string &word){
        
        if(wordIdx == word.length())
        {
            ans = true;
            return;
        }
        
        //left
        if(isValid(i, j-1, board, wordIdx, word)){
            visited[i][j-1] = 1;
            solve(i, j-1, board, wordIdx+1, word);
            visited[i][j-1] = 0;
        }

        //up
        if(isValid(i+1, j, board, wordIdx, word)){
            visited[i+1][j] = 1;
            solve(i+1, j, board, wordIdx+1, word);
            visited[i+1][j] = 0;
        }

        //right
        if(isValid(i, j+1, board, wordIdx, word)){
            visited[i][j+1] = 1;
            solve(i, j+1, board, wordIdx+1, word);
            visited[i][j+1] = 0;
        }

        //down
        if(isValid(i-1, j, board, wordIdx, word)){
            visited[i-1][j] = 1;
            solve(i-1, j, board, wordIdx+1, word);
            visited[i-1][j] = 0;
        }

    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited.resize(m, vector<bool>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = 1;
                    solve(i, j, board, 1, word);
                    if(ans)
                        return 1;
                    
                    visited[i][j] = 0;
                }
            }
        }

        return 0;

    }
};