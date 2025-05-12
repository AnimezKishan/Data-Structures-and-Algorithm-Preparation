// Counting

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> count(10, 0);

        for(int &i : digits) {
            count[i]++;
        }

        vector<int> ans;
        for(int i=1; i<10; i++) {
            if(count[i] == 0)
                continue;
            
            count[i]--;
            for(int j=0; j<10; j++) {
                if(count[j] == 0)
                    continue;
                
                count[j]--;
                for(int k=0; k<10; k+=2) {
                    if(count[k] == 0)
                        continue;
                    
                    ans.push_back(i*100+j*10+k);
                }
                count[j]++;
            }
            count[i]++;
        }

        return ans;
    }
};