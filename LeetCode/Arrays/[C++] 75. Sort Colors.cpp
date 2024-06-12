// DNF Algorithm

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size()-1, mid = 0;

        while(mid <= high) {
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[high], nums[mid]);
                high--;
            }
            else
                mid++;
        }
    }
};


// Two-Pass Solution using Counting Sort
/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int &num : nums)
            m[num]++;
        
        int idx = 0;
        for(int i=0;i<3;i++){
            while(m[i]--)
                nums[idx++] = i;
        }
    }
};
*/