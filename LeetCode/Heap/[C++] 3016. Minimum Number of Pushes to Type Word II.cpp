class Solution {
public:
    int minimumPushes(string word) {
        vector<int> letterCount(26, 0);
        for(char &ch : word){
            letterCount[ch-'a']++;
        }

        priority_queue<pair<int, char>> pq;
        for(int i=0; i<26; i++)
            if(letterCount[i] > 0)
                pq.push({letterCount[i], i+'a'});

        // stores current no of letters in the key 
        vector<int> keyCount(8, 0);
        int keyCycle = 0, ans = 0;
        while(!pq.empty()){
            int count = pq.top().first;
            pq.pop();

            keyCount[keyCycle%8]++;
            ans += keyCount[keyCycle%8] * count;
            keyCycle++;
        }
        return ans;
    }
};