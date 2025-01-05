// Difference Array

class Solution {
public:
    int n;

    vector<int> rangeAddition(vector<vector<int>> &shifts) {
        vector<int> ans(n + 1, 0); // Extra space for boundary management

        for (const vector<int> &shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            int delta = (direction == 1) ? 1 : -1;
            ans[start] += delta;
            if (end + 1 < n) {
                ans[end + 1] -= delta;
            }
        }

        // Calculate cumulative sum
        for (int i = 1; i < n; i++) {
            ans[i] += ans[i - 1];
        }

        return ans;
    }

    string shiftingLetters(string s, vector<vector<int>> &shifts) {
        n = s.length();
        vector<int> shiftValues = rangeAddition(shifts);

        for (int i = 0; i < n; i++) {
            int shift = shiftValues[i] % 26; // Handle shifts greater than 26
            if (shift < 0) {
                shift += 26; // Convert negative shifts to positive
            }
            s[i] = 'a' + (s[i] - 'a' + shift) % 26; // Apply shift
        }

        return s;
    }
};
