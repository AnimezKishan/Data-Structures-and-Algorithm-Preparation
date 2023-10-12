/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        // 1. Find mountain's peak
        int s = 0, e = mountainArr.length()-1;
        int mid = s+(e-s)/2;
        while(s<e){
            mid = s+(e-s)/2;
            cout<<mid<<endl;
            if(mountainArr.get(mid) > mountainArr.get(mid+1))
                e = mid;
            else
                s = mid+1;
        }
        cout<<mid<<" "<<mountainArr.get(mid);

        // 2. search for target in left part
        int peak = mid;
        s = 0, e = mid;
        int ans = INT_MAX;
        mid = s+(e-s)/2;
        while(s<=e){
            mid = s+(e-s)/2;
            if(mountainArr.get(mid) == target){
                ans = mid;
                e = mid - 1;
            }
            if(target > mountainArr.get(mid))
                s = mid + 1;
            else
                e = mid - 1;
        }

        if(ans != INT_MAX)
            return ans;
        
        // 3. if not found, search for target in right part
        s = peak+1, e = mountainArr.length()-1;
        mid = s+(e-s)/2;
        while(s<=e){
            mid = s+(e-s)/2;
            if(mountainArr.get(mid) == target){
                ans = mid;
                e = mid - 1;
            }
            if(target < mountainArr.get(mid))
                s = mid + 1;
            else
                e = mid - 1;
        }

        if(ans != INT_MAX)
            return ans;
        else
            return -1;
    }
};