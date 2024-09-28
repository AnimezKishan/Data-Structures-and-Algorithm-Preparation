struct Deque {
    int val;
    Deque *front;
    Deque *back;

    Deque(int v) {
        val = v;
        front = NULL;
        back = NULL;
    }
};

class MyCircularDeque {
public:
    int size = 0, K;
    Deque *start;
    Deque *end;
    MyCircularDeque(int k) {
        size = k;
        K = k;
        start = NULL;
        end = start;
    }
    
    bool insertFront(int value) {
        if(size) {
            if(start == NULL) {
            Deque *temp = new Deque(value);
            start = temp;
            end = start;
            }
            else {
                Deque *temp = new Deque(value);
                temp->back = start;
                start->front = temp;
                start = temp;
            }

            size--;
            return true;
        }
        else
            return false;
    }
    
    bool insertLast(int value) {
        if(size) {
            if(end == NULL) {
            Deque *temp = new Deque(value);
            start = temp;
            end = start;
            }
            else {
                Deque *temp = new Deque(value);
                end->back = temp;
                temp->front = end;
                end = temp;
            }

            size--;
            return true;
        }
        else
            return false;
    }
    
    bool deleteFront() {
        if(!start)
            return false;
        else{
            if(end == start){
                Deque *temp = start;
                start = NULL;
                end = NULL;
                delete temp;
            }else {
                Deque *temp = start->back;
                Deque *s = start;
                temp->front = NULL;
                s->back = NULL;
                start = temp;
                delete s;
            }

            size++;
            return true;
        }
    }
    
    bool deleteLast() {
        if(!end)
            return false;
        else{
            if(end == start){
                Deque *temp = start;
                start = NULL;
                end = NULL;
                delete temp;
            }else {
                Deque *temp = end;
                Deque *tempBack = end->front;
                tempBack->back = NULL;
                temp->front = NULL;
                end = tempBack;
                delete temp;
            }

            size++;
            return true;
        }
    }
    
    int getFront() {
        if(start)
            return start->val;
        else
            return -1;
    }
    
    int getRear() {
        if(end)
            return end->val;
        else
            return -1;
    }
    
    bool isEmpty() {
        if(size == K)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if(!size)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */