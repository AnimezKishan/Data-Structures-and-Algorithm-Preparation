/*
Brute Force
1. Merge arrays
2. Sort the merged array.
3. Find the Median 
T.C. --> O(n)+O(nlogn)+O(n)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> m;

        for(auto n:nums1)
            m.push_back(n);
        for(auto n:nums2)
            m.push_back(n);

        sort(m.begin(), m.end());

        //applying median formula based on number of total elements.
        if(m.size()%2)
            return m[m.size()/2];
        else
            return (m[(m.size()/2)-1]+m[m.size()/2])/2.0;
        
    }
};