class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> zero_count(n-1);
        vector<int> one_count(n-1);

        int cnt = 0;
        for(int i=0;i<n-1;i++){
            if(s[i] == '0')
                cnt++;
            
            zero_count[i] = cnt;
        }

        cnt = 0;
        for(int i=n-1;i>=1;i--){
            if(s[i] == '1')
                cnt++;
            
            one_count[i-1] = cnt;
        }

        int ans = INT_MIN;
        for(int i=0;i<n-1;i++)
            ans = max(ans, zero_count[i]+one_count[i]);
        
        
        return ans;
    }
};