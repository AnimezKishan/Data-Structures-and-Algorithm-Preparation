/*
Two Pointer without Extra Space (Insertion Sort [applied on second array])
1. Make the array num1 of size num1+num2.
2. Starting comparing and insert smaller elements into nums1.
    2.1 Continue if nums[i] < nums2[0].
    2.2 Else, swap them and then sort the nums2 array using insertion sort.
3. Now Insert elements if remaining in nums2 array.
4. Now, Find median using formula.
*/
class Solution {
private:
    void rearrange(vector<int> &n){
        for(int i=1;i<n.size() && n[i] < n[i-1];i++)
            swap(n[i], n[i-1]);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;

        //Edge Case
        if(n1==0)
            return (n2%2)?nums2[n2/2]:(nums2[(n2/2)-1]+nums2[n2/2])/2.0;
        if(n2==0)
            return (n1%2)?nums1[n1/2]:(nums1[(n1/2)-1]+nums1[n1/2])/2.0;
        
        int i=0, j=0;
        nums1.resize(n);
        while(i<n1)
        {
            if(nums1[i] > nums2[0])
            {
                swap(nums1[i], nums2[0]);
                //Rearrange array nums2
                rearrange(nums2);
            }
            i++;
        }

        while(j<n2)
        {
            nums1[i++] = nums2[j++];
        }
        
        return (n%2)?nums1[n/2]:(nums1[(n/2)-1]+nums1[n/2])/2.0;
    }
};