//Brainteaser
// Don't consider it as a collision problem, consider if they are MAGICAL ANTS which passes by through each other while they meet each other.

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftMost = (right.empty() ? n : *min_element(begin(right), end(right)));
        int rightMost = (left.empty() ? 0 : *max_element(begin(left), end(left)));

        int leftLen = n-leftMost;
        int rightLen = rightMost-0;

        return (leftLen > rightLen ? leftLen : rightLen);
    }
};