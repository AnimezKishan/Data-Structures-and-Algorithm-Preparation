class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> noCount(51, 0);

        vector<int> prefixCommonArray;
        int currCount = 0;
        for(int i=0; i<n; i++){
            noCount[A[i]]++;
            noCount[B[i]]++;

            if(noCount[A[i]] > 1)
                currCount++;
            if(noCount[B[i]] > 1 && A[i] != B[i])
                currCount++;
            
            prefixCommonArray.push_back(currCount);
        }

        return prefixCommonArray;
    }
};