class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int m = grid.size(), n = grid[0].size();
    
            vector<int> nums;
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    nums.push_back(grid[i][j]);
                }
            }
    
            sort(nums.begin(), nums.end());
    
            int N = nums.size();
            int target = nums[N/2]; // median element gives minimum no. of operations
    
            int operations = 0;
            for(int i=0; i<N; i++) {
                // check if it's possible to make nums[i] equal to target
                if(target%x != nums[i]%x)
                    return -1;
                
                operations += abs(target - nums[i])/x;
            }
    
            return operations;
        }
    };