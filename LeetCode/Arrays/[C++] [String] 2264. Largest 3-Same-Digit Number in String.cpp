class Solution {
public:
    string largestGoodInteger(string num) {
        
        char maxi = '/';
        int count = 0;
        for(int i=1;i<num.length();i++){
            if(num[i] == num[i-1]){
                if(count == 1)
                {
                    maxi = max(maxi, num[i]);
                    count = 0;
                }
                else
                    count++;
            }
            else
                count = 0;
        }

        string ans;
        for(int i=0;i<3;i++)
            ans.push_back(maxi);
        
        return (ans[0] == '/' ? "" : ans);
    }
};