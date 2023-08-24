//Reference - https://leetcode.com/problems/text-justification/solutions/1243483/intuitive-code-with-explanation/

class Solution {
public:
    string spaceJustifier(string output, int maxWidth, bool isLastLine){
        if(output.length() == maxWidth)
            return output;
        
        int spaceInString = 0;
        for(int i=0;i<output.length();i++)
            if(output[i] == ' ')
                spaceInString++;
        
        int spaceToBeInserted = maxWidth - output.length();

        if(isLastLine == true || spaceInString == 0)
        {
            output.insert(output.length(), spaceToBeInserted, ' ');
            return output;
        }

        int eachSlot = spaceToBeInserted / spaceInString;
        int leftOver = spaceToBeInserted % spaceInString;

        for(int i=0;i<output.length();i++)
        {
            if(output[i] == ' ' && (eachSlot > 0 || leftOver > 0))
            {
                int noOfSpaces = eachSlot + ((leftOver--) > 0 ? 1:0);
                output.insert(i, noOfSpaces, ' ');
                i += noOfSpaces;
            }
        }
        return output;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string output = words[0];
        for(int i=1;i<words.size();i++)
        {
            if(output.length() + words[i].length() + 1 <= maxWidth)
            {
                output += " " + words[i]; 
            }
            else
            {
                output = spaceJustifier(output, maxWidth, 0);
                ans.push_back(output);
                output = words[i];
            }
        }

        output = spaceJustifier(output, maxWidth, 1);
        ans.push_back(output);
        return ans;
    }
};