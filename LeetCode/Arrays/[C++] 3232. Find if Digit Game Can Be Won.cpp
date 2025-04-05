class Solution {
    public:
        bool canAliceWin(vector<int>& nums) {
            int singleNo = 0, doubleNo = 0;
    
            for(int &num : nums) {
                int digits = 0;
                int tempNum = num;
                while(num) {
                    digits++;
                    num /= 10;
                }
    
                if(digits == 1)
                    singleNo += tempNum;
                else
                    doubleNo += tempNum;
            }
    
            return singleNo > doubleNo || doubleNo > singleNo;
        }
    };