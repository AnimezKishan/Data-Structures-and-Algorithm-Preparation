class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int largest = INT_MIN, second_largest = 0, smallest = INT_MAX, second_smallest = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] >= largest){
                second_largest = largest;
                largest = nums[i];
            }
            else if(nums[i] > second_largest)
                second_largest = nums[i];

            
            if(nums[i] <= smallest){
                second_smallest = smallest;
                smallest = nums[i];
            }
            else if(nums[i] < second_smallest)
                second_smallest = nums[i];
        }
        
        return (largest*second_largest) - (smallest*second_smallest);
    }
};