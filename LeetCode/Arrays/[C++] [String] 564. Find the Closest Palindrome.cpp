class Solution {
public:
    string nearestPalindromic(string num) {
        long originalNum = stol(num);
        long length = num.size();
        
        if (length == 1) return to_string(stoi(num) - 1);

        vector<long> candidates;
        candidates.push_back(pow(10, length - 1) - 1); // 999 for "1000"
        candidates.push_back(pow(10, length) + 1);     // 10001 for "9999"

        long halfLen = (length + 1) / 2;
        long prefix = stol(num.substr(0, halfLen));
        vector<long> prefixes = {prefix, prefix + 1, prefix - 1};

        for (auto p : prefixes) {
            string left = to_string(p);
            string right = left;
            if (length % 2) right.pop_back();
            reverse(right.begin(), right.end());
            candidates.push_back(stol(left + right));
        }

        long minDiff = LONG_MAX, closestPalin = 0;
        for (auto candidate : candidates) {
            long diff = abs(candidate - originalNum);
            if (candidate != originalNum && diff < minDiff) {
                closestPalin = candidate;
                minDiff = diff;
            } else if (diff == minDiff) {
                closestPalin = min(closestPalin, candidate);
            }
        }

        return to_string(closestPalin);
    }
};