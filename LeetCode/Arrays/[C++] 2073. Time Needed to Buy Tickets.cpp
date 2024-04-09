class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, i=0, n = tickets.size();

        while(true){
            if(tickets[i%n] < 1){
                i++;
                continue;
            }
            else{
                tickets[i%n]--;
                ans++;
            }

            if(tickets[k] == 0)
                break;
            i++;
        }

        return ans;
    }
};