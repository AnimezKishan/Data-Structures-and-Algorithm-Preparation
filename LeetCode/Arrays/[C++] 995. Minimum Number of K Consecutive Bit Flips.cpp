class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        // Flip Count tells how many flips to be applied for current index.
        int flipCount = 0, flips = 0;
        vector<bool> isFlipped(n, false);

        for(int i=0; i<n; i++){
            // if current num doesn't come under the previous flipping window, then don't flip it.
            if(i>=k && isFlipped[i-k] == true)
                flipCount--;
            
            /*
            if current num = 0 and flipCount is even or current num = 1 and flipCount is odd.
                then we need to flip it to make it 1.
            
            In shorthand, it can be written as flipCount%2 == nums[i].
            */
            if(flipCount%2 == nums[i]){
                if(i+k > n)
                    return -1;
                flips++;
                isFlipped[i] = true;
                flipCount++;
            }
        }

        return flips;
    }
};