class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string &i:words){
            int x = 0, y = i.length() - 1;
            int flag = 0;
            while(x<y){
                if(i[x++] != i[y--]){
                    flag = 1;
                    break;
                }
            }

            if(flag == 0)
                return i;
        }

        return "";
    }
};