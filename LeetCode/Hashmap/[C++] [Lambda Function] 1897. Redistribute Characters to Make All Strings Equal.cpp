//Using STL and Lambda
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> count(26, 0);

        for(int i=0;i<words.size();i++){
            for(char &ch:words[i]){
                count[ch -'a']++;
            }
        }

        auto lambda = [&](int freq){
            return freq%n == 0;
        };

        //all_of validates the given condition for every elements of vector.
        return all_of(begin(count), end(count), lambda);
    }
};

//Approach 1
/*class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> count(26, 0);

        for(int i=0;i<words.size();i++){
            for(char &ch:words[i]){
                count[ch -'a']++;
            }
        }

        for(int i=0;i<26;i++){
            if(count[i] != 0){
                if(count[i]%n != 0)
                    return false;
            }
        }

        return true;
    }
};
*/