#include <bits/stdc++.h> 

void solve(vector<vector<int>> & arr, int n, int x, int y, vector<vector<bool>> &visited, string path, vector<string> &ans)
{
    //base case
    if(x == n-1 && y == n-1)
    {
        ans.push_back(path);
        path.pop_back();
        return;
    }

    /*
    Conditions to make rat move :-
    -> next x and y index should be within matrix 
    -> next index's value should be 1
    -> next index should be unvisited
    */
    if((x <0 || x >= n) || (y <0 || y >= n) || (arr[x][y] == 0) || visited[x][y])
        return;
    
    visited[x][y] = 1;
    //Four options to move -> Down/Left/Right/Up
    //Down
    solve(arr, n, x+1, y, visited, path+'D', ans);

    //Left
    solve(arr, n, x, y-1, visited, path+'L', ans);

    //Right
    solve(arr, n, x, y+1, visited, path+'R', ans);

    //Up
    solve(arr, n, x-1, y, visited, path+'U', ans);

    visited[x][y] = 0;
}

vector <string> searchMaze(vector<vector<int>> &arr, int n) {
    // Write your code here.
    vector<string> ans;
    
    if(arr[0][0] == 0)
        return ans;

    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    solve(arr, n, 0, 0, visited, "", ans);
    return ans;
}