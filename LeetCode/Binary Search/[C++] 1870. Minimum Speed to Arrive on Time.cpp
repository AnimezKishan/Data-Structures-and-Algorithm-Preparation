//O(nlog(n))

class Solution {
public:
    bool solve(int mid, vector<int> &dist, double hour){
        double temp = 0;
        for(int i=0;i<dist.size();i++)
        {
            // Take the decimal value only for the last train's distance, otherwise take ceiling value.
            if(i != dist.size()-1)
                temp += ceil(dist[i]*1.0/mid);
            else
                temp += dist[i]*1.0/mid;
        }
        return temp<=hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour < dist.size()-1)
            return -1;
        int s = 1;
        int e = 1e7;
        int ans = -1;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(solve(mid, dist, hour))
            {
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return ans;
    }
};