#include <bits/stdc++.h>
using namespace std;


class Solution{
    private:
    bool isSafe(int newX, int newY, int n, vector<vector<int>> visited, vector<vector<int>> m){
        /*
        Three conditions for rat to move :-
        * The index values should be inside the maze matrix.
        * The index should be unvisited.
        * The value in index should be 1 so that rat can move.
        */
        if((newX>=0 && newX<n) && (newY>=0 && newY<n) && m[newX][newY] == 1 && visited[newX][newY] == 0)
            return true;
        else
            return false;
    }
    
    void solve(vector<vector<int>> m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path){
        //base case
        if(x == n-1 && y == n-1)
        {
            ans.push_back(path);
            return;
        }
        //visited the maze element
        visited[x][y] = 1;
        
        //4 choice - D/L/R/U
        //Down
        int newX = x+1;
        int newY = y;
        if(isSafe(newX, newY, n, visited, m)){
            path.push_back('D');
            solve(m, n, ans, newX, newY, visited, path);
            path.pop_back();
        }
        //Left 
        newX = x;
        newY = y-1;
        if(isSafe(newX, newY, n, visited, m)){
            path.push_back('L');
            solve(m, n, ans, newX, newY, visited, path);
            path.pop_back();
        }
        //Right
        newX = x;
        newY = y+1;
        if(isSafe(newX, newY, n, visited, m)){
            path.push_back('R');
            solve(m, n, ans, newX, newY, visited, path);
            path.pop_back();
        }
        //Up
        newX = x-1;
        newY = y;
        if(isSafe(newX, newY, n, visited, m)){
            path.push_back('U');
            solve(m, n, ans, newX, newY, visited, path);
            path.pop_back();
        }
        
        /*
        Backtrack
        Mark paths unvisited while backtracking
        */
        visited[x][y] = 0;
        
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        if(m[0][0] == 0)
            return ans;
            
        int x=0;
        int y=0;
        vector<vector<int>> visited = m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j] = 0;
            }
        }
        string path = "";
        solve(m, n, ans, x, y, visited, path);
        return ans;
    }
};

    


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
