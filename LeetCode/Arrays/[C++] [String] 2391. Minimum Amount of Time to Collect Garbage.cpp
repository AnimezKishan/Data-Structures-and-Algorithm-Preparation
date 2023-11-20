class Solution {
public:
    unordered_map<char, int> lastIndex;
    unordered_map<char, int> occurance;
    void solve(char ch, int i, string &garbage){
        lastIndex[ch] = i;
        occurance[ch] += count(garbage.begin(), garbage.end(), ch);
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        

        for(int i=0;i<garbage.size();i++){
            if(find(begin(garbage[i]), end(garbage[i]), 'G') != garbage[i].end()){
                solve('G', i, garbage[i]);
            }

            if(find(begin(garbage[i]), end(garbage[i]), 'P') != garbage[i].end()){
                solve('P', i, garbage[i]);
            }

            if(find(begin(garbage[i]), end(garbage[i]), 'M') != garbage[i].end()){
                solve('M', i, garbage[i]);
            }
        }

        vector<int> prefixSum(travel.size(), travel[0]);
        for(int i=1;i<travel.size();i++){
            prefixSum[i] = prefixSum[i-1] + travel[i];
        }

        int ans = 0;
        for(auto i:lastIndex)
        {
            int sum = lastIndex[i.first]-1 < 0 ? 0 : prefixSum[lastIndex[i.first]-1];
            ans +=  sum + occurance[i.first];
        }

        return ans;
    }
};