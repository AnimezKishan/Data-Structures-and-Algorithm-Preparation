// Cumulative XOR

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long long, long long> m;
        
        m[0] = 1;
        int cum_xor = 0;
        long long result = 0;

        for(char &ch : word){
            // Binary Representation of character
            int shift = ch - 'a';
            int chToBinary = (1 << shift);

            cum_xor ^= chToBinary;

            // All characters are even in count
            result += m[cum_xor];

            // Check for odd occurance of character should be once.
            for(char c='a';c<='j';c++){
                shift = c-'a';
                long long checkXOR = cum_xor ^ (1<<shift); 
                result += m[checkXOR];
            }
            m[cum_xor]++;
        }
        return result;
    }
};