class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st;
        for(string &s : folder)
            st.insert(s);
        
        vector<string> ans;
        for(string &currFolder : folder) {
            bool isSub = false;
            string tempFolder = currFolder;

            // trim the string till it's empty (to check all possible sub folder options)
            while(!currFolder.empty()){
                // find the last position of '/' and trim the string till there. 
                size_t position = currFolder.find_last_of('/');
                currFolder = currFolder.substr(0, position);
                
                // check if it can be a sub folder
                if(st.find(currFolder) != st.end()){
                    isSub = true;
                    break;
                }
            }

            if(!isSub)
                ans.push_back(tempFolder);
        }

        return ans;
    }
};