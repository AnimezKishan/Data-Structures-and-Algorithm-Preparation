class Solution {
public:
    int minOperations(vector<string>& logs) {
        int operations = 0;
        for(string &log : logs){
            if(log == "../"){
                if(operations == 0)
                    continue;
                else
                    operations--;
            }

            else if(log == "./")
                continue;
            else
                operations++;
        }
        return operations;
    }
};