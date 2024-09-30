struct LL {
    int val;
    LL *front;
    LL *next;

    LL(int value) {
        val = value;
        front = NULL;
        next = NULL;
    }
};

class CustomStack {
public:
    int size;
    int S;
    LL *start;
    LL *end;

    CustomStack(int maxSize) {
        size = maxSize;
        S = maxSize;
        start = NULL;
        end = NULL;
    }
    
    void push(int x) {
        if(size) {
            if(start == NULL){
                LL *temp = new LL(x);
                start = temp;
                end = start;
            }
            else{
                LL *temp = new LL(x);
                temp->front = end;
                end->next = temp;
                end = temp;
            }

            size--;
        }
    }
    
    int pop() {
        if(size != S) {
            int last;
            if(start == end) {
                LL *temp = start;
                start = NULL;
                end = NULL;
                last = temp->val;
                delete temp;
            }else{
                LL *temp = end;
                temp->front->next = temp->next;
                end = temp->front;
                temp->front = NULL;
                last = temp->val;
                delete temp;
            }

            size++;
            return last;
        }

        return -1;
    }
    
    void increment(int k, int val) {
        LL *temp = start;
        int i = 0;
        while(temp && i < k) {
            temp->val += val;
            temp = temp->next;
            i++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */