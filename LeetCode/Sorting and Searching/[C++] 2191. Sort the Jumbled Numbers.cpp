class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> vec;

        for(int &num : nums){
            int temp = num;
            int newNum = 0;

            if(temp < 10){
                vec.push_back({num, mapping[num]});
                continue;
            }

            int mappedNum  = 0;
            int plaveValue = 1;

            while(num) {
                int lastDigit   = num%10;
                int mappedDigit = mapping[lastDigit];
                mappedNum += plaveValue * mappedDigit;

                plaveValue *= 10;
                num /= 10;
            }

            vec.push_back({temp, mappedNum});
        } 

        auto lambda = [&](auto &v1, auto &v2){
            return v1.second < v2.second;
        };

        sort(begin(vec), end(vec), lambda);
        vector<int> ans;
        for(auto &i : vec){
            cout<<i.first<<" "<<i.second<<endl;
            ans.push_back(i.first);
        }

        return ans;
    }
};