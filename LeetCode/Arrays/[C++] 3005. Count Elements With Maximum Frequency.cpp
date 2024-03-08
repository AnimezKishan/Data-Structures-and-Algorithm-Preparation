class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = INT_MIN, freqCount;
        vector<int> freq(101, 0);

        for(int &i:nums){
            freq[i]++;
            if(maxFreq < freq[i]){
                maxFreq = freq[i];
                // reset count
                freqCount = 1;
            } 
            else if(maxFreq == freq[i]){
                freqCount++;
            }
        }

        return maxFreq*freqCount;
    }
};