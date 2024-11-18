// Brute Force
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k == 0)
            return vector<int>(n, 0);

        vector<int> ans;
        for(int i=0; i<n; i++) {
            int currNum = 0;
            if(k > 0) {
                for(int j=0; j<k; j++)
                    currNum += code[(i+j+1)%n];
            }
            else{
                for(int j=0; j<abs(k); j++){
                    int idx = i-j-1;
                    if(idx < 0)
                        currNum += code[n + idx];
                    else
                        currNum += code[idx];    
                }
            }

            ans.push_back(currNum);
        }

        return ans;
    }
};


// Sliding Window
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if(k == 0)
            return ans;
        
        int i, j;
        if(k > 0){
            i = 1;
            j = k;
        }
        else{
            i = n - abs(k);
            j = n - 1;
        }

        int windowSum = 0;
        for(int ptr = i; ptr<=j; ptr++){
            windowSum += code[ptr];
        }

        for(int k=0; k<n; k++){
            ans[k] = windowSum;

            windowSum -= code[i%n];
            i++;

            j++;
            windowSum += code[j%n];
        }

        return ans;
    }
};