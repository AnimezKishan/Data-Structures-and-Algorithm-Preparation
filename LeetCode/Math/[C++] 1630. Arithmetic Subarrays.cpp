//Without Sorting. [ Arithmetic Progression ]
//O(m * n)

class Solution {
public:
    bool isAp(vector<int> & temp){
        int n = temp.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_set<int> st;

        for(int &i:temp){
            mini = min(mini, i);
            maxi = max(maxi, i);
            st.insert(i);
        }

        if((maxi - mini) % (n-1) != 0){
            return false;
        }

        int commDiff = (maxi - mini)/(n-1);
        int curr = mini;
        while(curr < maxi){
            if(st.find(curr) == st.end())
                return false;
            curr += commDiff;
        }
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            int start_index = l[i];
            int last_index = r[i];

            vector<int> temp(last_index - start_index + 1);
            copy(nums.begin() + start_index, nums.begin() + last_index + 1, temp.begin());
            bool check = isAp(temp);
            ans.push_back(check);
        }

        return ans;
    }
};

//Brute Force
//O(m * nlog(n))
/*
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            int start_index = l[i];
            int last_index = r[i];

            vector<int> temp(last_index - start_index + 1);
            copy(nums.begin() + start_index, nums.begin() + last_index + 1, temp.begin());
            sort(temp.begin(), temp.end());

            int commDiff = -1;
            for(int j=0;j<temp.size()-1;j++){
                temp[j] = temp[j+1] - temp[j]; 
                if(commDiff == -1)
                    commDiff = temp[j];
                else if(temp[j] != commDiff){
                    ans.push_back(false);
                    break;
                }
                if(j == temp.size() -2)
                    ans.push_back(true);
            }

            // if(count(begin(temp), end(temp) - 1, temp[0]) == temp.size() -1)
            //     ans.push_back(true);
            // else
            //     ans.push_back(false);
            
            // for(auto i:temp)
            //     cout<<i<<" ";
            
            // cout<<endl;
        }

        return ans;
    }
};
*/