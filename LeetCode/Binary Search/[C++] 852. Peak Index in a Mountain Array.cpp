// O(log(n)) [n = size of array]

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int start = 0;
        int end = a.size()-1;
        int i = start +(end-start)/2;
        while(start<end){
            if(a[i]>a[i+1]){
                end = i;
            }
            else{
                start = i+1;
            }
            i = start +(end-start)/2;
        }
        return i;
    }
};