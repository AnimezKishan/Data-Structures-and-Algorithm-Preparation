// Map
// T.C -> O(n)
// S.C -> O(n) 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;

        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]] >= 2)
                return true;
        }

        return false;
    }
};


// Sorting
// T.C -> O(n*log(n))
// S.C -> O(n) or O(1) [depending on the sorting algorithm used]
/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(begin(nums), end(nums));

        for(int i=0;i<nums.size()-1;i++)
            if(nums[i] == nums[i+1])
                return true;
        
        return false;
    }
};
*/

// Set
// T.C -> O(n)
// S.C -> O(n)
/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;

        for(int i=0; i<n; i++)
            s.insert(nums[i]);

        return nums.size() != s.size();
    }
};
*/