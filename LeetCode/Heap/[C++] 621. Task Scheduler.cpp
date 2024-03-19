class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);

        for(char &ch:tasks){
            count[ch-'A']++;
        }

        int time = 0;
        // max heap
        priority_queue<int> pq;

        for(int i=0;i<26;i++)
            if(count[i] > 0)
                pq.push(count[i]);

        while(!pq.empty()){
            vector<int> temp;
            //no. of tasks at a time
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int &i:temp)
                if(i > 0)
                    pq.push(i);
            
            //Edge Case - if no more task left to do
            if(pq.empty())
                time += temp.size();
            else
                time += n+1;
        }

        return time;
    }
};