class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2 != 0) return false; // Odd length strings can't be valid.

        stack<int> openStack; // Tracks positions of locked '('
        stack<int> flexibleStack; // Tracks positions of unlocked parentheses

        // Left-to-right traversal to ensure valid pairing
        for (int i = 0; i < s.length(); i++) {
            if (locked[i] == '1') { // Locked parentheses
                if (s[i] == '(') {
                    openStack.push(i);
                } else { // s[i] == ')'
                    if (!openStack.empty()) {
                        openStack.pop(); // Match with a previous '('
                    } else if (!flexibleStack.empty()) {
                        flexibleStack.pop(); // Use an unlocked parenthesis as '('
                    } else {
                        return false; // No way to match this ')'
                    }
                }
            } else { // Unlocked parenthesis
                flexibleStack.push(i);
            }
        }

        // Now handle remaining unmatched '(' using flexible parentheses
        while (!openStack.empty() && !flexibleStack.empty()) {
            if (openStack.top() > flexibleStack.top()) {
                return false; // Unlocked parenthesis cannot balance this '('
            }
            openStack.pop();
            flexibleStack.pop();
        }

        // Valid if no unmatched '(' remain
        return openStack.empty();
    }
};
