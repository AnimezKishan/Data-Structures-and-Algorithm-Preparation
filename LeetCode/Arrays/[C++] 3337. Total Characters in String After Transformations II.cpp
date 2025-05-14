using ll = long long;

class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<vector<ll>> multiplyMatrices(const vector<vector<ll>> &A, const vector<vector<ll>> &B) {
        int rowsA = A.size(), colsA = A[0].size(), colsB = B[0].size();
        vector<vector<__int128_t>> temp(rowsA, vector<__int128_t>(colsB, 0));
        vector<vector<ll>> result(rowsA, vector<ll>(colsB, 0));

        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                for (int k = 0; k < colsA; k++) {
                    temp[i][j] += A[i][k] * B[k][j];
                }
                result[i][j] = temp[i][j] % MOD;
            }
        }
        return result;
    }

    vector<vector<ll>> powerMatrix(vector<vector<ll>> matrix, ll exponent) {
        vector<vector<ll>> result(matrix.size(), vector<ll>(matrix.size(), 0));

        for (int i = 0; i < matrix.size(); i++) result[i][i] = 1;

        while (exponent > 0) {
            if (exponent % 2 == 1) result = multiplyMatrices(result, matrix);
            matrix = multiplyMatrices(matrix, matrix);
            exponent /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<ll>> transform(26, vector<ll>(26, 0));

        for (int i = 0; i < 26; i++) {
            for (int shift = 0; shift < nums[i]; shift++) {
                transform[i][(i + 1 + shift) % 26]++;
            }
        }

        transform = powerMatrix(transform, t);
        vector<vector<ll>> freq(1, vector<ll>(26, 0));
        for (char ch : s) {
            freq[0][ch - 'a']++;
        }

        freq = multiplyMatrices(freq, transform);
        int totalLength = 0;
        for (int count : freq[0]) {
            totalLength += count;
            if (totalLength >= MOD) totalLength -= MOD;
        }

        return totalLength;
    }
};