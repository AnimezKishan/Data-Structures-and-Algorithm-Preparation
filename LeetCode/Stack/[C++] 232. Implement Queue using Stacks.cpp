class MyQueue {
public:
    stack<int> s1;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }

    void popHelper(int &ans){
        if(s1.size() == 1)
        {
            ans = s1.top();
            s1.pop();
            return;
        }

        auto t = s1.top();
        s1.pop();

        popHelper(ans);

        s1.push(t);

    }
    
    int pop() {
        int ans;
        popHelper(ans);
        return ans;
    }

    void peekHelper(int &ans){
        if(s1.size() == 1){
            ans = s1.top();
            return;
        }

        auto t = s1.top();
        s1.pop();

        peekHelper(ans);

        s1.push(t);

    }
    
    int peek() {
        int ans;
        peekHelper(ans);
        return ans;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */