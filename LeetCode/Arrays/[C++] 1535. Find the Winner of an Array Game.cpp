class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int M = *max_element(begin(arr), end(arr));
        
        if(k >= arr.size())
            return M;

        int maxi = arr[0];
        int maxCount = 0;

        for(int i=1;i<arr.size();i++){
            if(arr[i] > maxi){
                maxi = arr[i];
                maxCount = 1;
            }
            else{
                maxCount++;
            }

            if(maxCount == k || maxi == M)
                return maxi;
        }
        return 0;
    }
};