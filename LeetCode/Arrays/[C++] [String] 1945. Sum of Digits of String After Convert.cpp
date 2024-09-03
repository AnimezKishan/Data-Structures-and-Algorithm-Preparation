class Solution {
public:
    int getLucky(string s, int k) {
        string positions = "";
        for(char &ch : s) {
            positions += to_string(ch-'a'+1);
        }

        int sum;
        while(k--) {
            sum = 0;
            for(char &ch : positions)
                sum += ch-'0';
            
            positions = to_string(sum);
        }

        return sum;
    }
};