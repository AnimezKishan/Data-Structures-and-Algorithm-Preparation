/* 

During push,
val = 2*data - mini;

Since 'val' was pushed and mini was relaced with data, therefore
-> curr = val
-> mini = data

During pop,
= 2*mini - curr
= 2*mini - (2*data - mini)
= 2*data - 2*data + mini
= mini
This is the previous mini stored in such a form that it can be poped later.

*/

#include<stack>
class SpecialStack {
    // Define the data members.
    stack<int> s;
    int mini;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty())
        {
            s.push(data);
            mini = data;
        }
        if(data < mini)
        {
            int val = 2*data - mini;
            s.push(val);
            mini = data;
        }
        else
        {
            s.push(data);
        }

    }

    int pop() {
        // Implement the pop() function.
        if(s.empty())
        {
            return -1;
        }
        else{
            int curr = s.top();
            s.pop();
            if(curr > mini)
            {
                return curr;
            }
            else{
                int prevMin = mini;
                int val = 2*mini - curr;
                mini = val;
                return prevMin;
            }
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini)
            return mini;
        else
            return curr;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return s.empty();
    }

    int getMin() {
        // Implement the getMin() function.
        if (s.empty())
            return -1;
        return mini;
    }  
};