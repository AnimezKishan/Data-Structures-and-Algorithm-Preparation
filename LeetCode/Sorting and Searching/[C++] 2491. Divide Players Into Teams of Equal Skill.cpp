class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(begin(skill), end(skill));

        int teamSkill = skill[0] + skill[n-1];
        int i = 0, j = n-1;
        long long chemistry = 0;
        while(i < j) {
            if(skill[i] + skill[j] != teamSkill)
                return -1;
            else
                chemistry += skill[i] * skill[j];
            
            i++;
            j--;
        }

        return chemistry;
    }
};