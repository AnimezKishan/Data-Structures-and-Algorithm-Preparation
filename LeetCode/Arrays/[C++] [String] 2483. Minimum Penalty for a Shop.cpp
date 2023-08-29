class Solution {
public:
    int bestClosingTime(string customers) {
        int index = -1, maxi = 0, score = 0;
        for(int i=0;i<customers.length();i++)
        {
            if(customers[i] == 'Y')
                score++;
            else
                score--;
            
            if(score > maxi)
            {
                maxi = score;
                index = i;
            }
        }
        return index+1;
    }
};