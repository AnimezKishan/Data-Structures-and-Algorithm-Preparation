/*
Property of XOR
If, x^y = z
x^y^y = z^y [taking xor of y both side]
then, x = z^y
also, y = x^y

So, if original[i] ^ original[i+1] = derived[i]
then, original[i+1] = original[i] ^ derived[i]
*/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        // Two Possibilities 
        // First, try with original[0] = 0.
        vector<int> original(n);
        original[0] = 0;
        for(int i=0; i<n-1; i++)
            original[i+1] = original[i] ^ derived[i];

        if(original[0] ^ original[n-1] == derived[n-1])
            return true;

        // If not, try with original[0] = 1.
        original[0] = 1;
        for(int i=0; i<n-1; i++)
            original[i+1] = original[i] ^ derived[i];

        if(original[0] ^ original[n-1] == derived[n-1])
            return true;

        return false;
    }
};