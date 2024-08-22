class Solution {
public:
    int findComplement(int num) {
        // mask is needed to avoid taking leading zero bits.
        int temp = num, mask = 0;
        while(temp){
            // make a mask with all digits as 1 corresponding to the orginal number
            mask = (mask<<1) | 1;
            temp >>= 1;
        }

        return (~num)&mask;
    }
};