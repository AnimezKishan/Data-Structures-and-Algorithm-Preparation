/*
the key to solving this is recognizing this property of the XOR (^):

if a ^ b = c then a ^ c = b
*/

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for(int i = pref.size()-1;i>=1;i--){
            pref[i] = pref[i] ^ pref[i-1];
        }

        return pref;
    }
};