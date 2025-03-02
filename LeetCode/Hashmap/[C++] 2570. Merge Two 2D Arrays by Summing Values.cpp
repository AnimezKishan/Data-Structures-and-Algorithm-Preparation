class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            map<int, int> mp;
            int n1 = nums1.size(), n2 = nums2.size();
            for(int i=0; i<n1; i++) {
                if(mp.find(nums1[i][0]) == mp.end())
                    mp[nums1[i][0]] = nums1[i][1];
                else
                    mp[nums1[i][0]] += nums1[i][1];
            }
    
            for(int i=0; i<n2; i++) {
                if(mp.find(nums2[i][0]) == mp.end())
                    mp[nums2[i][0]] = nums2[i][1];
                else
                    mp[nums2[i][0]] += nums2[i][1];
            }
    
            vector<vector<int>> resultArr;
            for(auto i : mp) {
                resultArr.push_back({ i.first, i.second });
            }
    
            return resultArr;
        }
    };