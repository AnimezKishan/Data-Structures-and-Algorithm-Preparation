/*
Recursive Solution 
*gives TLE - DP should be used.
*/

class Solution {
public:
    unordered_map<int,bool> mp;
    bool recursion(int pos, int prevStep, vector<int>& arr, int n){

        if(mp[pos]== false || pos > arr[n-1]) return false;
        if(pos == arr[n-1]) return true;  


        bool isPossible;

        if(pos==0){
            isPossible = recursion(pos+1,1,arr,n);
        }
        else{
            if(prevStep-1>0) 
                isPossible = recursion(pos+(prevStep-1),prevStep-1,arr,n);
            if(isPossible) return true;
            isPossible = recursion(pos+prevStep,prevStep,arr,n);
            if(isPossible) return true;
            isPossible = recursion(pos+(prevStep+1),prevStep+1,arr,n);
            if(isPossible) return true;
        }

        return isPossible;

    }

    bool canCross(vector<int>& stones) {
        for(auto itr : stones) mp[itr] = true;
        int n = stones.size();
        return recursion(0,1,stones,n);
    }
};