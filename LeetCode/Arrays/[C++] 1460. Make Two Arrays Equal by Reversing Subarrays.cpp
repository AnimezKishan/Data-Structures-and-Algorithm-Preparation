class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> numCount(1001, 0);

        for(int &n : target)
            numCount[n]++;

        for(int &n : arr)
            numCount[n]--;

        for(int &n : numCount)
            if(n != 0)
                return false;

        return true;
    }
};