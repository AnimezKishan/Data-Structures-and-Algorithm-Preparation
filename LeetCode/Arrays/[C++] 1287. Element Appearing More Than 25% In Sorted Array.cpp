/*
Since,  there is exactly one integer in the array that occurs more than 25% of the time and also the array is sorted.
So, if a ith indexed element is also present in (i + (n/4))th index, then it's the desired number.
*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
            if(arr[i] == arr[i+arr.size()/4])
                return arr[i];
        
        return 0;
    }
};