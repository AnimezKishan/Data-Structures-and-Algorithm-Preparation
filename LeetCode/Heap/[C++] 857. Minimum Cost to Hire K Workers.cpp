// Intuition - https://www.youtube.com/watch?v=kxR52OB_I8k

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        int n = quality.size();

        double ans = DBL_MAX;

        vector<pair<double, int>> worker_ratio(n);
        for(int i=0;i<n;i++)
            worker_ratio[i] = {(double)min_wage[i]/quality[i], quality[i]};

        sort(begin(worker_ratio), end(worker_ratio));

        int sumQuality = 0;
        priority_queue<int> pq;
        for(int i=0; i<k; i++){
            pq.push(worker_ratio[i].second);
            sumQuality += worker_ratio[i].second;
        }

        double managerRatio = worker_ratio[k-1].first;
        ans = managerRatio * sumQuality;

        for(int manager=k; manager<n; manager++){
            managerRatio = worker_ratio[manager].first;

            pq.push(worker_ratio[manager].second);
            sumQuality += worker_ratio[manager].second; 

            if(pq.size() > k){
                sumQuality -= pq.top();
                pq.pop();
            }


            ans = min(ans, managerRatio * sumQuality);
        }
        return ans;
    }
}; 