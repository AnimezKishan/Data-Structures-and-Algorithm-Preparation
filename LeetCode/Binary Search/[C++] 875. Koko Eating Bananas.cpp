/*
Using Search Space
1. Search for the correct options in a appropiate search space.
2. To check for correct option, 
    2.1 "i/mid" gives the hour/hours taken by koko to finish bananas of each iteration.
    2.2 "i%mid" gives the extra hour if there is any banana left.
3. Return the minimum possible solution. 
*/class Solution {
public:
    bool isPoss(vector<int> &a, int h, int mid){
        long long int eatHour=0;
        for(auto i:a){
            int consumed = i/mid;
            eatHour+=consumed;
            int ifLeft = i % mid;
            if(ifLeft!=0)
                eatHour++;
        }
        return eatHour <= h;
    }

    int minEatingSpeed(vector<int>& a, int h) {
        int s=1;
        int e=1000000000;
        long long int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(isPoss(a, h, mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};