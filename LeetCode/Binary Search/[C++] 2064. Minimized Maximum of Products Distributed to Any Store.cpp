class Solution {
public:
    bool isPossible(int mid, int n, vector<int>& quantities) {
        int totalStores = 0;
        for(int &i : quantities) {
            int quantityEachStore = i / mid;
            if(i % mid > 0)
                quantityEachStore++;
            
            totalStores += quantityEachStore;
            if(totalStores > n)
                return false;
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = 1;
        int e = *max_element(begin(quantities), end(quantities));
        int ans = -1;
        while(s <= e) {
            int mid = s + (e-s)/2;
            if(isPossible(mid, n, quantities)) {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }

        return ans;
    }
};