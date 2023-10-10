class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        //sort and remove duplicates
        set<int> st(begin(nums), end(nums));
        vector<int> temp(begin(st), end(st));
        
        int ans = INT_MAX;

        for(int i=0;i<temp.size();i++)
        {
            int min_range = temp[i];
            int max_range = temp[i] + (n-1);

            //gets the index of max_range element.
            int j = upper_bound(begin(temp), end(temp), max_range) - begin(temp);

            //no. of elements that are within range is j-i
            int within_range = j-i;

            //no. of out of bounds are total no. of elements - no. of within range elements
            //as we used set which sorted array and removed duplicate elements, this algorithm automatically consider those in out_of_bound.
            // DRY-RUN -> [1,3,2,3] 
            int out_of_range = n - within_range;

            ans = min(ans, out_of_range);
        }
    return ans;
    }
};