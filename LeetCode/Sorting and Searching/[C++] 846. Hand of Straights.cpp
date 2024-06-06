// Sorting + Map + Greedy

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n < groupSize || n % groupSize != 0)
            return 0;

        sort(hand.begin(), hand.end());
        unordered_map<int, int> m;

        for(int &num : hand)
            m[num]++;

        for(int &num : hand){
            int tempSize = groupSize;
            int tempNum = num;

            if(!m[tempNum])
                continue;

            while(tempSize && m[tempNum]){
                m[tempNum]--;
                tempSize--;
                tempNum++;
            }

            if(tempSize != 0)
                return 0;
        }

        return 1;
    
    }
};