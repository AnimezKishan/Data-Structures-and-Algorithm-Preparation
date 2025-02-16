// Backtracking

class Solution {
    public:
        bool solve(int i, int n, vector<int> &arr, vector<bool> &visited) {
            if(i >= arr.size())
                return true;
            
            if(arr[i] != -1)
                return solve(i+1, n, arr, visited);
    
            for(int num=n; num>=1; num--) {
                if(!visited[num]) {
                    visited[num] = true;
                    arr[i] = num;
    
                    if(num == 1){
                        if(solve(i+1, n, arr, visited))
                            return true;
                    } else {
                        int j = i + num;
                        if(j<arr.size() && arr[j] == -1) {
                            arr[j] = num;
                            if(solve(i+1, n, arr, visited))
                                return true;
                            arr[j] = -1;
                        }
                    }
    
                    arr[i] = -1;
                    visited[num] = false;
                }
            }
    
            return false;
        }
        vector<int> constructDistancedSequence(int n) {
            vector<int> arr(2*n-1, -1);
    
            vector<bool> visited(n+1, false);
    
            solve(0, n, arr, visited);
    
            return arr;
        }
    };