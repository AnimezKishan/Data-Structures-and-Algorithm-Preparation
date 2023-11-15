// O(n)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(n+1, 0);
        for(int x : arr) {
            count[min(x, n)]++;
        }
        
        int maxEl = 1;
        int i = 0;
        int num = 1;

        while(num <= n && i < n) {
            int freq = count[num];

            maxEl = max(maxEl, num);
            i += (freq == 0) ? 1 : freq;
            num++;
        }


        //Edge Case - When 'num' doesn't consider element/elements greater than maxEl (when i exceeds n and some elements are still left to be considered).
        if(i>n)
            for(int i=maxEl+1;i<n+1;++i)
                if(count[i]) maxEl++;
        
        return maxEl;

    }
};


// O(n^2)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr), end(arr));

        if(arr[0] != 1)
            arr[0] = 1;

        for(int i = 1;i<arr.size();i++){
            if(abs(arr[i-1] - arr[i]) > 1){
                arr[i] = arr[i-1] + 1;
            }
        }

        return *max_element(begin(arr), end(arr));
    }
};