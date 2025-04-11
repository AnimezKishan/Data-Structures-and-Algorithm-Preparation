class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int ans = 0;
            int first, last;
            for(int num=low; num<=high; num++) {
                string str = to_string(num);
                if(str > "10" && str.length()%2 == 0) {
                    int half = str.length()/2;
                    first = 0;
                    for(int i=0; i<half; i++) {
                        first += str[i] - '0';
                    }
    
                    last = 0;
                    for(int i=half; i<str.length(); i++) {
                        last += str[i] - '0';
                    }
    
                    ans += first == last;
                }
            }
            
            return ans;
        }
    };