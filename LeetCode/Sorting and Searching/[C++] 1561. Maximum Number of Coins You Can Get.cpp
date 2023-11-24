class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(begin(piles), end(piles));

        int lastPileSize = n / 3;

        int i = n - 1;
        int j = lastPileSize - 1;

        int ans = 0;
        while(i >= lastPileSize || j>=0){
            if(i<lastPileSize){
                j--;
                ans += piles[j--];
                j--;
            }
            i--;
            ans += piles[i--];
            j--;
        }

        return ans;
    }
};