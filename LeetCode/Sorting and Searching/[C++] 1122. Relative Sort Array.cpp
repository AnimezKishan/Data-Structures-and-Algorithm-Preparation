// Counting Sort
// T.C : O(nlogn)
// S.C : O(n)

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;

        for(int &n : arr1)
            m[n]++;
        
        int i = 0;
        for(int &n : arr2){
            while(m[n]){
                arr1[i] = n;
                m[n]--;
                i++;
            }

            m.erase(n);
        }

        for(auto &n : m){
            while(n.second){
                arr1[i] = n.first;
                n.second--;
                i++;
            }
        }

        return arr1;
    }
};