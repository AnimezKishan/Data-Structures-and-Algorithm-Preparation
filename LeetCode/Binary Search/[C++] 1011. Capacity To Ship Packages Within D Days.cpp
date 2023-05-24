class Solution {
public:
    bool isPossible(vector<int> &a,int m, int mid){
        int weightSum =0;
        int dayCount = 1;
        for(int i=0;i<a.size();i++){
            //iterate till sum of weights goes more than mid(weight load decided for a day).
            if(weightSum + a[i] <= mid){
                weightSum +=a[i];
            }
            else{
                //increase the day count and reset the weight count.
                dayCount++;

                //weight element shouldn't be more than decided weigth load(mid).
                //And, should be within the days given to complete the task. 
                if(a[i]>mid || dayCount>m)
                    return false;
                weightSum = a[i];
            }
        }
        return true;

    }
    int shipWithinDays(vector<int>& a, int days) {
        int s=0;
        int e=0;

        //value of e would not be than sum of all weights.
        for(auto i:a)
            e+=i;

        int ans =-1;
        int mid = s+(e-s)/2;
        while(s<=e){
            if(isPossible(a, days, mid)){
                ans = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};