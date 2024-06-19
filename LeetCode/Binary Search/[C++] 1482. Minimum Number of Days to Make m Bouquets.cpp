class Solution {
public:
    int isPossible(int mid, vector<int> &bloomDay, int &m, int &k){
        int noOfBouquets = 0, flowers = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid)
                flowers++;
            else
                flowers = 0;
            
            if(flowers == k){
                flowers = 0;
                noOfBouquets++;
            }
        }

        return noOfBouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // If No. of flowers required for all Bouquets is greater than no. of flowers available i.e. (m*k) > bloomDay.size()
        if(m > (bloomDay.size()/k))
            return -1;
        
        int s = 0, e = *max_element(begin(bloomDay), end(bloomDay));

        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(isPossible(mid, bloomDay, m, k)){
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }

        return ans;
    }
};