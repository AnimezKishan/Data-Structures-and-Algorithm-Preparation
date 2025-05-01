class Solution {
    public:
        bool isPoss(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
            int currPillsCount = 0;
            multiset<int> ms(begin(workers), begin(workers) + mid);
    
            for(int i=mid-1; i>=0; i--) {
                int required = tasks[i];
                auto it = prev(ms.end());
    
                if(*it >= required) {
                    ms.erase(it);
                } else if(currPillsCount == pills) {
                    return false;
                } else {
                    auto reqWeakestWorkerIt = ms.lower_bound(required - strength);
    
                    if(reqWeakestWorkerIt == ms.end())
                        return false;
                    
                    ms.erase(reqWeakestWorkerIt);
                    currPillsCount++;
                }
            }
    
            return true;
        }
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            int m = tasks.size(), n = workers.size();
    
            sort(begin(tasks), end(tasks));
            sort(begin(workers), end(workers), greater<int>());
    
            int s = 0, e = min(m, n);
            int ans = 0;
            while(s <= e) {
                int mid = s + (e-s)/2;
                if(isPoss(tasks, workers, pills, strength, mid)) {
                    ans = mid;
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
    
            return ans;
        }
    };