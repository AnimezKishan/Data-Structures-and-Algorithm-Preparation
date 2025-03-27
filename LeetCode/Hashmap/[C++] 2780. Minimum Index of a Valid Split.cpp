class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int, int> mp;
    
            int dominant;
            for(int &num : nums) {
                mp[num]++;
    
                if(mp[num] > n/2)
                    dominant = num;
            }
    
            unordered_map<int, int> newMp;
            for(int i=0; i<n; i++) {
                newMp[nums[i]]++;
    
                // cout<<mp[dominant]<<" "<<newMp[dominant]<<" "<<i<<" "<<((mp[dominant] - newMp[dominant]) * dominant)<<" "<<(n-i-1)<<endl;
                // cout<<(newMp[dominant] * dominant)<<" "<<(i+1)<<endl;
                // cout<<((newMp[dominant] * dominant) > (i+1))<<" "<<(((mp[dominant] - newMp[dominant]) * dominant) > (n-i-1))<<endl;
    
                bool c1 = (newMp[dominant]) > (i+1)/2;
                bool c2 = ((mp[dominant] - newMp[dominant])) > (n-i-1)/2;
    
                cout<<c1<<" "<<c2<<endl;
                if(c1 && c2) {
                    return i;
                }
            } 
            return -1;
    
    
        }
    };