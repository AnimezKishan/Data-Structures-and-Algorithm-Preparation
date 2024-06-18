//Binary Search
/*
Make a pair array of difficulty and profit and sort it based on difficulty.
For every worker, iterate to possible difficulties and calculate the current Max Profit for each iteration.
*/

// T.C -> O(n*log(n) + m*log(n)) = O(n*log(n))
// S.C -> O(n)

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size(), m = worker.size();
        vector<pair<int, int>> diffPro;
        for(int i=0; i<n; i++)
            diffPro.push_back({difficulty[i], profit[i]});
        
        sort(begin(diffPro), end(diffPro));

        //Pre-Processing to find the maximum profit till i index
        /*
        Why need of pre-processing?
        Dry Run this,
        difficulty = [68,35,52,47,86], profit = [67,17,1,81,3], worker = [92,10,85,84,82]
        */
        for(int i=1; i<n; i++)
            diffPro[i].second = max(diffPro[i].second, diffPro[i-1].second);

        int s, e;
        int ans = 0;
        for(int i=0; i<m; i++){
            s = 0, e = n-1;
            int currWorker = worker[i], currMaxProfit = 0;
            while(s <= e){
                int mid = s + (e-s)/2;
                if(currWorker >= diffPro[mid].first){
                    currMaxProfit = max(currMaxProfit, diffPro[mid].second);
                    s = mid + 1;
                }
                else
                    e = mid - 1;
            }

            ans += currMaxProfit;
        }

        return ans;
    }
};