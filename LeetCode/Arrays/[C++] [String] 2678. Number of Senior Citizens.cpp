// One-liner using lambda and count_if
class Solution {
public:
    int countSeniors(vector<string>& details) {
        return count_if(begin(details), end(details), [&](string &s1){
            return stoi(s1.substr(11, 2)) > 60;
        });
    }
};

/*
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(int i=0; i<details.size(); i++){
            int age = stoi(details[i].substr(11, 2));
            if(age > 60)
                ans++;
        }

        return ans;
    }
};
*/