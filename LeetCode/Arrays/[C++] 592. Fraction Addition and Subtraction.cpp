// Simulation + Math

class Solution {
public:
    string fractionAddition(string expression) {
        int n = expression.length();

        int i = 0, numerator = 0, denominator = 1;
        while(i < n) {
            int newNum = 0;
            int newDen = 0;

            bool isNegative = (expression[i] == '-');

            if(expression[i] == '+' || expression[i] == '-')
                i++;
            
            while(i<n && isdigit(expression[i])){
                int digit = expression[i] - '0';
                newNum = (newNum * 10) + digit;
                i++;
            }

            if(isNegative)
                newNum *= -1;
            
            i++; // skip the division character '/'

            while(i<n && isdigit(expression[i])){
                int digit = expression[i] - '0';
                newDen = (newDen * 10) + digit;
                i++;
            }

            numerator = newNum * denominator + newDen * numerator;
            denominator = newDen * denominator;
        }

        // find GCD for the numerator and denominator
        int gcd = abs(__gcd(numerator, denominator));

        numerator /= gcd;
        denominator /= gcd;

        return to_string(numerator) + "/" +to_string(denominator);
    }
};