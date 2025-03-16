class Solution {
    public:
        typedef long long ll;
        bool isPossible(vector<int>& ranks, ll mid, int cars) {
            ll carsFixed = 0;
    
            for(int i = 0; i < ranks.size(); i++) 
                carsFixed += sqrt(mid/ranks[i]);
    
            return carsFixed >= cars;
        }
    
        long long repairCars(vector<int>& ranks, int cars) {
            int n = ranks.size();
    
            ll s = 1;
            int maxR = *max_element(begin(ranks), end(ranks));
            ll e = 1LL * maxR * cars * cars;
    
            ll result = -1;
            while(s <= e) { 
                ll mid = s + (e-s)/2;
    
                if(isPossible(ranks, mid, cars)) {
                    result = mid;
                    e = mid-1;
                } else {
                    s = mid+1;
                }
            }
    
            return result;
        }
    };
    