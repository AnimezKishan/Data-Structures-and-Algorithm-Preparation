// Counting Sort

class Solution {
public:
    void countingSort(vector<int> &arr) {
        unordered_map<int, int> m;

        int minVal = *min_element(begin(arr), end(arr));
        int maxVal = *max_element(begin(arr), end(arr));

        for(int &val : arr)
            m[val]++;
        
        int idx = 0;
        for(int i=minVal; i<=maxVal; i++){
            while(m[i] > 0){
                arr[idx] = i;
                m[i]--;
                idx++; 
            }
        }
    }
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        countingSort(sortedHeights);

        int ans = 0;
        for(int i=0; i<heights.size(); i++){
            if(sortedHeights[i] != heights[i])
                ans++;
        }

        return ans;
    }
};


/*
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> sortedHeights(heights.begin(), heights.end());
        sort(begin(sortedHeights), end(sortedHeights));

        int ans = 0;
        for(int i=0; i<n; i++){
            if(sortedHeights[i] != heights[i])
                ans++;
        }

        return ans;
    }
};
*/