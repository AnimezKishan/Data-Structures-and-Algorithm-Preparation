class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> m(1001, 0);

        for(int &i:nums1){
            if(m[i] <= 0)
                m[i]++;
        }

        vector<int> ans;
        for(int &j:nums2){
            if(m[j] > 0 && m[j] < 2)
            {
                m[j]++;
                ans.push_back(j);
            }
        }

        return ans;
    }
};