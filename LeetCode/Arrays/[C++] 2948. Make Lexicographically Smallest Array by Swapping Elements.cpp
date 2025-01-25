class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;
        sort(begin(vec), end(vec));

        // make groups out of elements
        unordered_map<int, list<int>> mp;
        unordered_map<int, int> elemToGroup;
        
        int groupNo = 0;
        mp[groupNo].push_back(vec[0]);
        elemToGroup[vec[0]] = groupNo;

        for(int i=1; i<n; i++) {
            if(abs(vec[i] - vec[i-1]) > limit) {
                groupNo++;
            }

            elemToGroup[vec[i]] = groupNo;
            mp[groupNo].push_back(vec[i]);
        }

        // Merge the Groups according to group belonging of element at each index
        for(int i=0; i<n; i++) {
            int currNum = nums[i];
            int group = elemToGroup[currNum];

            nums[i] = *(mp[group].begin());
            mp[group].pop_front(); // O(1) due to use of doubly linked list
        }
        return nums;
    }
};