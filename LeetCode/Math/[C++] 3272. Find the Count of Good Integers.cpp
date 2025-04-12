class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            unordered_set<string> st;
    
            int d = (n+1)/2;
            int start = pow(10, d-1);
            int end = pow(10, d) - 1;
    
            for(int num=start; num<=end; num++) {
                string leftHalf = to_string(num);
                string full = "";
                string rightHalf;
                if(n%2 == 0) {
                    rightHalf = leftHalf;
                } else {
                    rightHalf = leftHalf.substr(0, d-1);
                }
    
                reverse(rightHalf.begin(), rightHalf.end());
                full = leftHalf + rightHalf;
    
                long long number = stoll(full);
                if(number % k != 0)
                    continue;
    
                sort(full.begin(), full.end());
                st.insert(full); 
            }
    
            vector<long long> factorial(11, 1);
            for(int i=1; i<11; i++) 
                factorial[i] = factorial[i-1] * i;
    
            long long ans = 0;
            for(auto &s : st) {
                vector<int> count(10, 0);
                for(auto &ch : s) {
                    count[ch - '0']++;
                }
    
                int totalDigits = s.length();
                int zeroCount = count[0];
                int nonZeroCount = totalDigits - zeroCount;
    
                long long perm = nonZeroCount * factorial[totalDigits-1];
    
                for(int i=0; i<10; i++) {
                    perm /= factorial[count[i]];
                }
    
                ans += perm;
            }
    
            return ans;
        }
    };